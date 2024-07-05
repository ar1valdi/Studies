<<<<<<< HEAD
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string author, title;
	friend ostream& operator<<(ostream& out, Book book);
public:
	Book();
	Book(const string& a, const string& t);
	Book(string&& a, string&& t);
	Book(const Book& b);
	Book(Book&& b);

	Book& operator=(const Book& right) {
		this->author = right.author;
		this->title = right.title;
		return *this;
	}
	Book& operator=(Book&& right) {
		this->author = move(right.author);
		this->title =  move(right.title);
		return *this;
	};

	string GetAuthor() const;
	string GetTitle() const;
	void SetAuthor(const string& a);
	void SetTitle(const string& a);
	void SetAuthor(string&& a);
	void SetTitle(string&& a);
=======
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
	string author, title;
	friend ostream& operator<<(ostream& out, Book book);
public:
	Book();
	Book(const string& a, const string& t);
	Book(string&& a, string&& t);
	Book(const Book& b);
	Book(Book&& b);

	Book& operator=(const Book& right) {
		this->author = right.author;
		this->title = right.title;
		return *this;
	}
	Book& operator=(Book&& right) {
		this->author = move(right.author);
		this->title =  move(right.title);
		return *this;
	};

	string GetAuthor() const;
	string GetTitle() const;
	void SetAuthor(const string& a);
	void SetTitle(const string& a);
	void SetAuthor(string&& a);
	void SetTitle(string&& a);
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};