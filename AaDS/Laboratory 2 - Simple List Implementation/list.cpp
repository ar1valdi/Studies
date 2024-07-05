#include "List.h"
#include <iostream>
using namespace std;
List::List() {
	FirstNode = nullptr;
	size = 0;
}
void List::add(string v, int id) {
	if (FirstNode == nullptr && id==0) {
		FirstNode = new Node();
		FirstNode->setVal(v);
		size++;
		return;
	}
	Node* tmp = FirstNode;
	for (int i = 0; i < id-1; i++)
		tmp = tmp->getNext();
	Node* toAttach = tmp->getNext();
	tmp->setNext(new Node);
	tmp->getNext()->setVal(v);
	tmp->getNext()->setNext(toAttach);
	size++;
}
void List::add(string v) {
	if (FirstNode == nullptr) {
		FirstNode = new Node();
		FirstNode->setVal(v);
		size = 1;
		return;
	}
	Node* tmp = FirstNode;
	for (int i = 0; i < size-1; i++)
		tmp = tmp->getNext();
	tmp->setNext(new Node);
	tmp->getNext()->setVal(v);
	size++;
}
void List::pop() {
	if (size == 0)
		return;
	if (size == 1) {
		delete FirstNode;
		FirstNode = nullptr;
		size = 0;
		return;
	}
	Node* tmp = FirstNode;
	for (int i = 0; i < size-2; i++)
		tmp = tmp->getNext();
	delete tmp->getNext();
	tmp->setNext(nullptr);
	size--;
}
void List::printList() const {
	if (size == 0)
		cout << "empty\n";
	else {
		Node *tmp = FirstNode;
		for (int i = 0; i < size; i++) {
			cout << i << " " << tmp->getVal() << endl;
			tmp = tmp->getNext();
		}
	}
}
List::~List() {
	delete FirstNode;
}