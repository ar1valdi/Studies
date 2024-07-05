<<<<<<< HEAD
#pragma once
#include "Node.h"
#include <initializer_list>

class Library 
{
private:
	Node* FirstNode;
	int size;
	friend ostream& operator<<(ostream& out, const Library& lib);
public:
	Library();
	Library(std::initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
    Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	std::size_t GetSize() const;
	Node* GetFirstNode() const;
	~Library();

	void push_back(const Book&);
	void push_back(Book&& b);
	Book pop_back();
=======
#pragma once
#include "Node.h"
#include <initializer_list>

class Library 
{
private:
	Node* FirstNode;
	int size;
	friend ostream& operator<<(ostream& out, const Library& lib);
public:
	Library();
	Library(std::initializer_list<Book> list);
	Library(const Library& orig);
	Library(Library&& orig);
	Library& operator=(const Library& right);
	Library& operator=(Library&& right);
    Book& operator[](std::size_t index);
	const Book& operator[](std::size_t index) const;
	std::size_t GetSize() const;
	Node* GetFirstNode() const;
	~Library();

	void push_back(const Book&);
	void push_back(Book&& b);
	Book pop_back();
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};