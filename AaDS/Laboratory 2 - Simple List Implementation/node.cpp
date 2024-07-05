#include "Node.h"
Node::Node() {
	val = "";
	next = nullptr;
}
Node::Node(const Node& other) {
	val = other.val;
	next = other.next;
}
Node::Node(Node&& other) {
	val = other.val;
	next = other.next;
	other.next = nullptr;
}
void Node::setNext(Node* n) {
	this->next = n;
}
Node* Node::getNext() {
	return this->next;
}
void Node::setVal(string v) {
	val = v;
}
string Node::getVal() {
	return val;
}
Node::~Node() {
	if(next != nullptr)
		delete next;
}