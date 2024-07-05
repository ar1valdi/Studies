<<<<<<< HEAD
#pragma once
#include <string>
using namespace std;
class Node
{
private:
	string val;
	Node* next;
public:
	Node();
	Node(const Node& other);
	Node(Node&& other);

	void setNext(Node* n);
	Node* getNext();
	void setVal(string v);
	string getVal();
	~Node();
};

=======
#pragma once
#include <string>
using namespace std;
class Node
{
private:
	string val;
	Node* next;
public:
	Node();
	Node(const Node& other);
	Node(Node&& other);

	void setNext(Node* n);
	Node* getNext();
	void setVal(string v);
	string getVal();
	~Node();
};

>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
