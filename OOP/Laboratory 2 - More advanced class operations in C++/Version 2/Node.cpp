#include "Node.h"

Node::Node() {
	this->val.SetAuthor("");
	this->val.SetTitle("");
	this->next = nullptr;
}
Node::Node(const Book& b) {
	this->val = b;
	this->next = nullptr;
}
Node::Node(Book&& b) {
	this->val = move(b);
	this->next = nullptr;
}
Node::~Node() {
	if (this->next != nullptr)
		delete this->next;
}
void Node::SetVal(const Book& b) {
	this->val = b;
}
void Node::SetNext(Node* n) {
	this->next = n;
}
Book Node::GetVal() const{
	return this->val;
}
Book& Node::GetVal() {
	return this->val;
}
Node* Node::GetNext() const{
	return this->next;
}