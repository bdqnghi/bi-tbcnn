#include "Bfs.hpp"

void Bfs::set_target_graph(graph* c_graph, const  std::string& c_vertex)
{
	target_graph = c_graph;
	target_vertex = c_vertex;
}

std::vector<vertex*>* Bfs::get_traversal_path()
{
	return &m_travers;
}

void Bfs::show_traversal()
{
	std::vector<vertex*>::iterator it_begin = m_travers.begin();
    std::vector<vertex*>::iterator it_end = m_travers.end();
	for(; it_begin != it_end; ++it_begin){
		std::cout << (*it_begin)->get_name() << " ";
	}
	std::cout <<"\n";
}


void Bfs::traverse()
{
	vertex* current_vertex = target_graph->get_vertex_by_name(target_vertex);
	std::queue<vertex*> m_queue;
	m_queue.push(current_vertex);
	m_travers.push_back(current_vertex);

	while(!m_queue.empty()){
		current_vertex = m_queue.front();
		m_queue.pop();
		current_vertex->set_visited(true);

		std::vector<base_edge*>::const_iterator it_begin = current_vertex->get_edges()->begin();
		std::vector<base_edge*>::const_iterator it_end = current_vertex->get_edges()->end();

		for(; it_begin != it_end; ++it_begin){
			if((*it_begin)->get_source_vertex() == current_vertex 
					&& (*it_begin)->get_destination_vertex()->get_visited() == false){
				m_queue.push((*it_begin)->get_destination_vertex());
				m_travers.push_back((*it_begin)->get_destination_vertex());
				(*it_begin)->get_destination_vertex()->set_visited(true);

			} else if ((*it_begin)->get_source_vertex()->get_visited() == false) {
				m_queue.push((*it_begin)->get_source_vertex());
				m_travers.push_back((*it_begin)->get_source_vertex());
				(*it_begin)->get_source_vertex()->set_visited(true);
			}
		}
	}
}
