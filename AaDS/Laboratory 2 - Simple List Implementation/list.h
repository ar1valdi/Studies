#pragma once
#include "Node.h"
class List
{
private:
	Node* FirstNode;
	int size;
public:
	List();

	void add(string v, int id);
	void add(string v);
	void pop();
	void printList() const;

	~List();
};

