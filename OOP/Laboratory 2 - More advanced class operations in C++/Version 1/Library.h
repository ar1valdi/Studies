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

	Book findBook(size_t index);
	Book findBook(string title);
	bool deleteBook(string title);
	void push_back(const Book&);
	void push_back(Book&& b);
	Book pop_back();
};