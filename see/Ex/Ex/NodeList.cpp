#include "NodeList.h"
NodeList::~NodeList()
{
	Node *p;
	while (first->next)
	{
		p = first->next;
		delete first;
		first = p;
	}
	delete first;
}
void NodeList::push_back(const int& tx, const float& tdx,const int &tym)//β�巨
{
	Node *newNode = new Node(tx, tdx,tym);
	last->next = newNode;
	last = newNode;
}
void NodeList::Push(Node *p,  int tx,  float tdx,  int tym)
{
	Node *q = new Node;
	Node *temp;
	temp = p->next;
	q->x = tx;
	q->dx = tdx;
	q->ym = tym;
	p->next = q;
	q->next = temp;
}
void NodeList::Delete(Node *pre,Node *cur)
{
	pre->next = cur->next;
}

