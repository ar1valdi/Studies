<<<<<<< HEAD
#include "sci_book.h"

Sci_Book::Sci_Book() {
	bib = nullptr;
	bibSize = 0;
}
Sci_Book::Sci_Book(const string& t, const string& a, Book** bib, int size) {
	this->title =t;
	this->author = a;
	this->bib = bib;
	this->bibSize = size;
}
Sci_Book::Sci_Book(Book&& b, Book**&& bib, int&&size) {
	this->title = move(b.GetTitle());
	this->author = move(b.GetAuthor());
	this->bib = move(bib);
	this->bibSize = move(size);
}
Sci_Book::Sci_Book(const Sci_Book& b) {
	this->title = b.GetTitle();
	this->author = b.GetAuthor();
	this->bib = b.bib;
	this->bibSize = b.bibSize;
}
Sci_Book::Sci_Book(Sci_Book&& b) {
	this->title = move(b.GetTitle());
	this->author = move(b.GetAuthor());
	this->bib = move(b.bib);
	this->bibSize = move(b.bibSize);
}
Book** rozszerz(Book** og, int ogSize) {
	Book** newptr = og;
	og = new Book * [ogSize+1];
	for (int i = 0; i < ogSize; i++)
		og[i] = newptr[i];
	if (newptr != nullptr)
		delete[] newptr;
	return og;
}

void Sci_Book::addToBib(Book* b) {
	this->bib = rozszerz(this->bib, this->bibSize);
	this->bibSize++;
	this->bib[this->bibSize - 1] = b;
}
void Sci_Book::addToBib(Sci_Book* b) {
	this->bib = rozszerz(this->bib, this->bibSize);
	this->bibSize++;
	this->bib[this->bibSize - 1] = b;
}

ostream& operator<<(ostream& out, Sci_Book book) {
	out << "Tytul: " << book.title;
	out << "\nAutor: " << book.author;
	out << "\nReferencje:\n";
	for (int i = 0; i < book.bibSize; i++) {
		out << i+1 << ". " << book.bib[i]->GetTitle() << " - " << book.bib[i]->GetAuthor() << "\n";
	}
	return out;
=======
#include "sci_book.h"

Sci_Book::Sci_Book() {
	bib = nullptr;
	bibSize = 0;
}
Sci_Book::Sci_Book(const string& t, const string& a, Book** bib, int size) {
	this->title =t;
	this->author = a;
	this->bib = bib;
	this->bibSize = size;
}
Sci_Book::Sci_Book(Book&& b, Book**&& bib, int&&size) {
	this->title = move(b.GetTitle());
	this->author = move(b.GetAuthor());
	this->bib = move(bib);
	this->bibSize = move(size);
}
Sci_Book::Sci_Book(const Sci_Book& b) {
	this->title = b.GetTitle();
	this->author = b.GetAuthor();
	this->bib = b.bib;
	this->bibSize = b.bibSize;
}
Sci_Book::Sci_Book(Sci_Book&& b) {
	this->title = move(b.GetTitle());
	this->author = move(b.GetAuthor());
	this->bib = move(b.bib);
	this->bibSize = move(b.bibSize);
}
Book** rozszerz(Book** og, int ogSize) {
	Book** newptr = og;
	og = new Book * [ogSize+1];
	for (int i = 0; i < ogSize; i++)
		og[i] = newptr[i];
	if (newptr != nullptr)
		delete[] newptr;
	return og;
}

void Sci_Book::addToBib(Book* b) {
	this->bib = rozszerz(this->bib, this->bibSize);
	this->bibSize++;
	this->bib[this->bibSize - 1] = b;
}
void Sci_Book::addToBib(Sci_Book* b) {
	this->bib = rozszerz(this->bib, this->bibSize);
	this->bibSize++;
	this->bib[this->bibSize - 1] = b;
}

ostream& operator<<(ostream& out, Sci_Book book) {
	out << "Tytul: " << book.title;
	out << "\nAutor: " << book.author;
	out << "\nReferencje:\n";
	for (int i = 0; i < book.bibSize; i++) {
		out << i+1 << ". " << book.bib[i]->GetTitle() << " - " << book.bib[i]->GetAuthor() << "\n";
	}
	return out;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}