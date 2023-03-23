#pragma once
#include "Book.h"

class Node
{
private:
	Book val;
	Node* next;
public:
	Node();
	Node(const Book& b);
	Node(Book&& b);
	void SetVal(const Book& b);
	void SetNext(Node* n);
	Book GetVal() const;
	Book& GetVal();
	Node* GetNext() const;
	~Node();

	Node& operator=(Node& right){
		this->val = right.val;
		this->next = right.next;
	}
	Node& operator=(Node&& right) {
		this->val = move(right.val);
		this->next = move(right.next);
	}
};
