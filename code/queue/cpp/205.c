/*
	���в���
	
	//�жӲ���
	typedef struct QNode{
		QElemType data;//����
		struct QNode *next;//��һ�����
	}QNode,*QueuePtr;
	typedef struct{
		QueuePtr front;//����ͷ
		QueuePtr rear;//����β
	}LinkQueue;

	//���в���
	Status InitQueue(LinkQueue &Q);//��ʼ��
	Status DestroyQueue(LinkQueue &Q);//�����ж�
	Status EnQueue(LinkQueue &Q,QElemType e);//����Ԫ��
	Status DeQueue(LinkQueue &Q,QElemType &e);//ɾ��Ԫ��
	int QueueLength(LinkQueue q);//���г���
	Status QueueEmpty(LinkQueue q);//����Ϊ��
	Status GetHead(LinkQueue Q,QElemType &e);//���ض���ͷ
*/

#include "head.h"
Status InitQueue(LinkQueue &Q){
	//��ʼ��
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)exit(OVERFLOW);
	Q.front->next=NULL;
	return OK;
}

Status DestroyQueue(LinkQueue &Q){
	//�����ж�
	while(Q.front){
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue &Q,QElemType e){
	//����Ԫ��
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e){
	//ɾ��Ԫ��
	QueuePtr p;
	if(Q.front==Q.rear)return ERROR;
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;
	free(p);
	return OK;
}

int QueueLength(LinkQueue q){
	QueuePtr p=q.front->next;
	int i=0;
	while(p){
		++i;
		p=p->next;
	}
	return i;
}
Status QueueEmpty(LinkQueue q){
	if(q.front->next)return ERROR;
	return OK;
}
Status GetHead(LinkQueue Q,QElemType &e){
	if(Q.front->next==NULL)return ERROR;
	e=Q.front->next->data;
	return OK;
}
