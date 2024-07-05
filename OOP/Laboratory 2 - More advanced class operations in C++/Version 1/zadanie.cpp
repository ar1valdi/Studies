<<<<<<< HEAD
﻿#include <iostream>
#include "Library.h"
#include <conio.h>

void refreshMenu(bool add=0) {
	system("CLS");
	cout << "A - Add to library\n";
	cout << "S - Show library\n";
	cout << "R - Remove from library\n";
	cout << "F - Find in library\n";
	cout << "Q - Quit\n";
	if (add)
		cout << "\n\nYou entered worng value!\nTry Again: ";
}

void actionEnd(bool g=1) {
	string buf;
	system("CLS");
	if (g)
		cout << "Done!\nPress enter to continue\n";
	else
		cout << "Program met some problems\nPress enter to continue\n";
	cin >> buf;
}

int main() {
	Library l1= { 
	{"a1", "k1"},
	{"a2", "k2"},
	{"a3", "k3"},
	{"a4", "k4"},
	{"a5", "k5"},
	{"a6", "k6"} };
	
	string input;
	bool add = 0;
	while (1) {
		refreshMenu(add);
		add = 0;
		cin >> input;
		if (input == "A" || input == "a") {
			system("CLS");
			string title, author;
			cout << "Enter Title:\n";
			cin.ignore();	//na sturmieniu in zostaje enter, trzeba go najpierw pobrac
			getline(cin, title);
			cout << "Enter Author:\n";
			getline(cin, author);
			l1.push_back({ author, title });
			actionEnd();
		}
		else if (input == "S" || input == "s") {
			string buf;
			system("CLS");
			cout << l1;
			cout << "Press enter to continue\n";
			cin >> buf;
		}
		else if (input == "R" || input == "r") {
			system("CLS");
			cout << "Enter title: ";
			cin.ignore();
			getline(cin, input);
			if (l1.deleteBook(input))
				actionEnd();
			else
			{
				system("CLS");
				cout << "Book hasn't been deleted\nEntered title is not in the library\n";
				cin >> input;
			}
		}
		else if (input == "F" || input == "f") {
			system("CLS");
			cout << "T - find by title\nI - find by index\n";
			cin >> input;
			system("CLS");
			if (input == "t" || input == "T") {
				cout << "Enter title:\n";
				cin.ignore();
				getline(cin, input);
				system("CLS");
				cout << l1.findBook(input) << endl;
				cin >> input;
			}
			else if (input == "I" || input == "i") {
				int i;
				cout << "Enter album index:\n";
				cin >> i;
				system("CLS");
				cout << l1.findBook(i) << endl;
				cin >> input;
			}
			else
				add = 1;
		}
		else if (input == "Q" || input == "q")
			break;
		else
			add = 1;
	}
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
}
*/
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
=======
﻿#include <iostream>
#include "Library.h"
#include <conio.h>

void refreshMenu(bool add=0) {
	system("CLS");
	cout << "A - Add to library\n";
	cout << "S - Show library\n";
	cout << "R - Remove from library\n";
	cout << "F - Find in library\n";
	cout << "Q - Quit\n";
	if (add)
		cout << "\n\nYou entered worng value!\nTry Again: ";
}

void actionEnd(bool g=1) {
	string buf;
	system("CLS");
	if (g)
		cout << "Done!\nPress enter to continue\n";
	else
		cout << "Program met some problems\nPress enter to continue\n";
	cin >> buf;
}

int main() {
	Library l1= { 
	{"a1", "k1"},
	{"a2", "k2"},
	{"a3", "k3"},
	{"a4", "k4"},
	{"a5", "k5"},
	{"a6", "k6"} };
	
	string input;
	bool add = 0;
	while (1) {
		refreshMenu(add);
		add = 0;
		cin >> input;
		if (input == "A" || input == "a") {
			system("CLS");
			string title, author;
			cout << "Enter Title:\n";
			cin.ignore();	//na sturmieniu in zostaje enter, trzeba go najpierw pobrac
			getline(cin, title);
			cout << "Enter Author:\n";
			getline(cin, author);
			l1.push_back({ author, title });
			actionEnd();
		}
		else if (input == "S" || input == "s") {
			string buf;
			system("CLS");
			cout << l1;
			cout << "Press enter to continue\n";
			cin >> buf;
		}
		else if (input == "R" || input == "r") {
			system("CLS");
			cout << "Enter title: ";
			cin.ignore();
			getline(cin, input);
			if (l1.deleteBook(input))
				actionEnd();
			else
			{
				system("CLS");
				cout << "Book hasn't been deleted\nEntered title is not in the library\n";
				cin >> input;
			}
		}
		else if (input == "F" || input == "f") {
			system("CLS");
			cout << "T - find by title\nI - find by index\n";
			cin >> input;
			system("CLS");
			if (input == "t" || input == "T") {
				cout << "Enter title:\n";
				cin.ignore();
				getline(cin, input);
				system("CLS");
				cout << l1.findBook(input) << endl;
				cin >> input;
			}
			else if (input == "I" || input == "i") {
				int i;
				cout << "Enter album index:\n";
				cin >> i;
				system("CLS");
				cout << l1.findBook(i) << endl;
				cin >> input;
			}
			else
				add = 1;
		}
		else if (input == "Q" || input == "q")
			break;
		else
			add = 1;
	}
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
}
*/
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
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}*/