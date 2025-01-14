#pragma once
using namespace std;
/*
struct Node {
	int son, mother;
	Node *next;
	Node() { next = nullptr; }
	Node(const int& a, const int & b) { next = nullptr; son = a; mother = b; }
};
*/
struct Node {
	int x;
	float dx;
	int ym;
	Node *next;
	Node() { next = nullptr; }
	Node(int tx, int tdx, int tym) :x(tx), dx(tdx), ym(tym)
	{
		next = nullptr;
	}
};
class NodeList
{
private:
	Node *first;
	Node *last;
public:
	NodeList() { first = new Node; last = first; }
	~NodeList();
	inline Node* Getfirst() { return first; }
	inline Node* Getlast() { return last; }
	void push_back(const int& tx, const float& tdx, const int &tym);
	void Push(Node *p, int tx, float tdx, int tym);
	void Delete(Node *p,Node *q);
};

