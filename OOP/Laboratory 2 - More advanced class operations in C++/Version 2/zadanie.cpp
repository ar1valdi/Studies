#include <iostream>
#include "Library.h"
#include "sci_book.h"

int main() {
	Sci_Book s1("Tworczosc Tolkiena", "ktos", nullptr, 0);
	Book b1("Tolkien", "Hobbit");
	Book b2("Tolkien", "Wladca pierscienia");
	s1.addToBib(&b1);
	s1.addToBib(&b2);
	cout << s1 << endl << endl;

	Sci_Book s2("Encyklopedia grzybow", "ktos inny", nullptr, 0);
	Book b3("Madry czlowiek", "Muchomory");
	Book b4("Madry czlowiek", "Borowiki");
	s2.addToBib(&b3);
	s2.addToBib(&b4);
	s2.addToBib(&s1);
	cout << s2 << endl;
}

//ppkt2
/*
int main() {
	Library e;
	cout << "e: " << e << endl;
	//3-5 książek
	Library l1 = { {"k1", "a1"},
	{"k2", "a2"},
	{"k3", "a3"} };
	l1 = l1;
	cout << "l1: " << l1 << endl;
	Library l2;
	cout << "l2: " << l2 << endl;
	l2.push_back({ "k4", "a4" });
	l2.push_back({ "k5", "a5" });
	cout << "l2: " << l2 << endl;
	e = std::move(l2);
	cout << "e: " << e << "l2: " << l2 << endl;
	l1[0] = std::move(e[1]);
	cout << "l1: " << l1 << "e: " << e << endl;
	return 0;
}*/

//ppkt 1
/*
int main(int argc, char** argv) {
	string a = "Book1", t = "Aut1";
	Book e;
	cout << "e: " << e << endl;
	Book b1 = { a, t };
	cout << "b1: " << b1 << endl;
	Book b2 = { "Book2","Aut2" };
	cout << "b2: " << b2 << endl;
	Book b3 = b1;
	cout << "b3: " << b3 << " b1: " << b1 << endl;
	e = std::move(b2);
	cout << "e: " << e << " b2:" << b2 << endl;
	e.SetAuthor("Aut3");
	cout << "e: " << e << endl;
	e.SetTitle("Book3");
	cout << "e: " << e << endl;
}*/