<<<<<<< HEAD
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

=======
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

>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
