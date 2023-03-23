#pragma once
#include "Book.h"

class Sci_Book : public Book
{
private:
	int bibSize;
	Book** bib;
	friend ostream& operator<<(ostream& out, Sci_Book book);
public:
	Sci_Book();
	Sci_Book(const string& t, const string& a, Book** bib, int size);
	Sci_Book(Book&& b, Book**&& bib, int&&size);
	Sci_Book(const Sci_Book& b);
	Sci_Book(Sci_Book&& b);

	void addToBib(Book* b);
	void addToBib(Sci_Book* b);

	Sci_Book& operator=(const Sci_Book& right) {
		this->author = right.author;
		this->title = right.title;
		delete[] this->bib;
		this->bib = right.bib;
		return *this;
	}
	Sci_Book& operator=(Sci_Book&& right) {
		this->author = move(right.author);
		this->title = move(right.title);
		this->bib = move(right.bib);
		return *this;
	};
};