#pragma once
#include "Book.h"

ostream& operator<<(ostream& out, Book book) {
	out << book.title << " - " << book.author << "\n";
	return out;
}
Book::Book() {
	this->author = "";
	this->title = "";
}
Book::Book(const string& a, const string& t) {
	this->author = a;
	this->title = t;
}
Book::Book(string&& a, string&& t) {
	this->author = move(a);
	this->title = move(t);
}
Book::Book(const Book& b) {
	this->author = b.author;
	this->title = b.title;
}
Book::Book(Book&& b) {
	this->author = move(b.author);
	this->title = move(b.title);
}
string Book::GetAuthor() const {
	return this->author;
}
string Book::GetTitle() const {
	return this->title;
}
void Book::SetAuthor(const string& a) {
	this->author = a;
}
void Book::SetTitle(const string& t) {
	this->title = t;
}
void Book::SetAuthor(string&& a) {
	this->author = move(a);
};
void Book::SetTitle(string&& t) {
	this->title = move(t);
};