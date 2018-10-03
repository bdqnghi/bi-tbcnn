#include "Queue.h"
#include "Sequence.h"

namespace custom_service
{


uint16 QUEUE::agent_list(std::vector<AGENT_INFO>& ret_agent_list)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);
	return m_agentmgr.getlist(ret_agent_list);
}


bool QUEUE::agent_presence(const UMID& id,const uint16& capacity,std::vector<INVITE_INFO>& ret_invite_list)
{

	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	AGENT agent(id,capacity);
	if (!m_sp_dbmgr->verify_queue_agent(queue_id,agent))
	{
		return false;
	}

	AGENT*agent_ptr = m_agentmgr.insert(agent);
	if (agent_ptr == NULL)
	{
		return false;
	}

	do_invite(ret_invite_list);
	return true;
}



bool QUEUE::agent_absence(const UMID& id)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	AGENT* agent_ptr = m_agentmgr.find(id);
	if (agent_ptr == NULL)
	{
		return false;
	}

	if (agent_ptr->load >0)
	{
		return false;
	}

	m_agentmgr.erase(agent_ptr);
	return true;

};


bool QUEUE::agent_offline(const UMID& id,std::vector<USER_CONVERSATION>& ret_usercvs_list,std::vector<INVITE_INFO>& ret_invite_list)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	AGENT* agent_ptr = m_agentmgr.find(id);
	if (agent_ptr == NULL)
	{
		return false;
	}

	AGENT::CVS_PTR it;
	for (it=agent_ptr->m_conversation_set.begin();it != agent_ptr->m_conversation_set.end();it++)
	{
		CONVERSATION* cvs_ptr = m_cvsmgr.find(*it);
		if (cvs_ptr == NULL)
		{
			continue;
		}
		USER_CONVERSATION user_cvs ; 
		user_cvs.mid = cvs_ptr->user.id;
		//user_cvs.queue_id = queue_id;
		user_cvs.conversation_id= cvs_ptr->cvs_id;
		ret_usercvs_list.push_back(user_cvs);

		//insert back to user deque
		m_user_que.push_front(cvs_ptr->user);

		m_sp_dbmgr->save_conversation_info(cvs_ptr);
		m_cvsmgr.erase(cvs_ptr);

	}

	m_agentmgr.erase(agent_ptr);
	do_invite(ret_invite_list);

	return true;

};


bool QUEUE::agent_accept(const UMID& id,CONVERSATION_INFO& cvs_info,std::vector<INVITE_INFO>& ret_invite_list,std::vector<USER_INFO>& ret_user_list)
{

	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	AGENT* agent_ptr = m_agentmgr.accept(id);

	if (agent_ptr == NULL || m_user_que.empty())
	{
		LOG(error)<<"Queue:"<<queue_id<<":: agent={"<<id.uin<<","<<id.multptvalue<<"} accept fail"<<ENDL;
		return false;
	}

	USER user = m_user_que[0];

	//CONVERSATION cvs(CONVERSATION_SEQ::instance().next(),queue_id,agent_ptr,user);
	CONVERSATION cvs(SEQMGR::instance().next_cvs(),queue_id,agent_ptr,user);
	CONVERSATION* cvs_ptr = m_cvsmgr.insert(cvs);
	if (cvs_ptr == NULL)
	{
		LOG(error)<<"Queue:"<<queue_id<<":: agent={"<<id.uin<<","<<id.multptvalue<<"} cvs_id exists"<<ENDL;
		return false;
	}

	m_user_que.pop_front();
	cvs_ptr->agent->add_conversation(cvs_ptr->cvs_id);
	m_sp_dbmgr->save_conversation_info(cvs_ptr);
	
	cvs_info.conversation_id = cvs_ptr->cvs_id;
	cvs_info.agent = cvs_ptr->agent->id;
	cvs_info.agent_name = cvs_ptr->agent->name;
	cvs_info.user = cvs_ptr->user.id;
	cvs_info.user_addr = cvs_ptr->user.address;

	do_invite(ret_invite_list);
	get_userinfo(ret_user_list);

	return true;
}

bool QUEUE::agent_refuse(const UMID& id,std::vector<INVITE_INFO>& ret_invite_list)
{

	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	bool ret = m_agentmgr.refuse(id);
	do_invite(ret_invite_list);
	return ret;
}


bool QUEUE::agent_redirect(const uint64& cvs_id,const UMID& from,const UMID& to,std::vector<INVITE_INFO>& ret_invite_list)
{

	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	AGENT *agent_from,*agent_to;
	if((agent_from = m_agentmgr.find(from)) ==NULL || (agent_to = m_agentmgr.find(to)) == NULL)
	{
		return false;
	}

	CONVERSATION* cvs_ptr;
	if ((cvs_ptr = m_cvsmgr.redirect(cvs_id,agent_from,agent_to)) != NULL)
	{
		m_sp_dbmgr->save_conversation_info(cvs_ptr);
		do_invite(ret_invite_list);
		return true;
	}

	return false;
}


uint16 QUEUE::user_join(const UMID& id,const uint32& addr,std::vector<INVITE_INFO>& ret_invite_list)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	USER user;
	user.id = id;
	user.address = addr;

	m_user_que.push_back(user);
	do_invite(ret_invite_list);
	return (uint16)m_user_que.size();
}


bool QUEUE::user_depart(const UMID& id,std::vector<USER_INFO>& ret_user_list)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	uint16 pos=0,length = m_user_que.size();

	for (;pos < length;pos++)
	{
		if(m_user_que[pos].id == id)
		{
			m_user_que.erase(m_user_que.begin()+pos);
			break;
		}
	}

	if (pos >= length)
	{
		return false;
	}

	get_userinfo(ret_user_list,pos);

	return true;
}

bool QUEUE::user_score(const UMID& id,const uint64& cvs_id,const int8& score)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);
	if(!m_cvsmgr.score(id,cvs_id,score))
	{
		return m_sp_dbmgr->save_conversation_score(queue_id,cvs_id,score);
	}

	return true;
}

uint16 QUEUE::user_amount()
{
	return m_user_que.size();
}

bool QUEUE::conversation_end(const uint64& cvs_id,UMID& agent_mid,USER_CONVERSATION& usercvs,std::vector<INVITE_INFO>& ret_invite_list)
{
	boost::mutex::scoped_lock lock(*m_queue_mutex_ptr);

	CONVERSATION* cvs_ptr = m_cvsmgr.find(cvs_id);
	if (cvs_ptr == NULL)
	{
		return false;
	}
	agent_mid = cvs_ptr->agent->id;
	usercvs.conversation_id= cvs_id;
	usercvs.mid = cvs_ptr->user.id;
	m_sp_dbmgr->save_conversation_info(cvs_ptr);
	m_cvsmgr.erase(cvs_ptr);

	/*
	if (m_cvsmgr.erase(cvs_id))
	{
		do_invite(ret_invite_list);
		return true;
	}
	*/
	return false;

}

uint16 QUEUE::do_invite(std::vector<INVITE_INFO>& ret_invite_list)
{
	AGENT* agent_ptr = NULL;
	uint16 num = 0;
	while(m_agentmgr.inviting_num() < m_user_que.size() &&
			(agent_ptr = m_agentmgr.invite(agent_ptr)) != NULL &&
			++num )
	{
		INVITE_INFO ii;
		ii= agent_ptr->id;
		//ii.queue_id = queue_id;
		ret_invite_list.push_back(ii);
		//num++;
	}

	return num;
}

uint16 QUEUE::get_userinfo(std::vector<USER_INFO>& ret_user_list,const uint16& pos)
{
	uint16 idx=pos;
	if (pos >= m_user_que.size())
	{
		return 0;
	};

	for(;idx<m_user_que.size();idx++)
	{
		USER_INFO ui ;
		ui.mid = m_user_que[idx].id;
		//ui.address = m_user_que[idx].address;
		ui.position = idx+1;
		ret_user_list.push_back(ui);
	}

	return idx;
}


bool QUEUE::load(const uint32& id)
{
	queue_id = id;
	if (m_sp_dbmgr == NULL )
	{
		return false;
	}
	return m_sp_dbmgr->get_queue_info(queue_id,queue_name);

}

}
