<<<<<<< HEAD
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List l;
	string input = "";
	while (input != "exit") {
		cin >> input;
		if (input == "append") {
			cin >> input;
			l.add(input);
		}
		else if (input == "insert") {
			cin >> input;
			int id;
			cin >> id;
			l.add(input, id);
		}
		else if (input == "pop") {
			l.pop();
		}
		else if (input == "print") {
			cin >> input;
			l.printList();
		}
	}
=======
#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List l;
	string input = "";
	while (input != "exit") {
		cin >> input;
		if (input == "append") {
			cin >> input;
			l.add(input);
		}
		else if (input == "insert") {
			cin >> input;
			int id;
			cin >> id;
			l.add(input, id);
		}
		else if (input == "pop") {
			l.pop();
		}
		else if (input == "print") {
			cin >> input;
			l.printList();
		}
	}
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}