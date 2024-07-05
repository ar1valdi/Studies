<<<<<<< HEAD
#include "Library.h"

Library::Library() {
	this->size = 0;
	this->FirstNode = nullptr;
}
Library::Library(std::initializer_list<Book> list) {
	this->size = 0;
	this->FirstNode = nullptr;
	for (Book b : list) {
		push_back(b);
	}
}
Library::Library(const Library& orig) {
	this->size = 0;
	this->FirstNode = nullptr;
	for (int i = 0; i < orig.size; i++) {
		push_back(orig[i]);
	}
}
Library::Library(Library&& orig) {
	swap(this->size, orig.size);
	swap(this->FirstNode, orig.FirstNode);
}
Library& Library::operator=(const Library& right) {
	if (right.FirstNode == this->FirstNode)
		return *this;
	delete this->FirstNode;
	this->FirstNode = nullptr;
	this->size = 0;
	for (int i = 0; i < right.size; i++) {
		push_back(right[i]);
	}
	return *this;
}
Library& Library::operator=(Library&& right) {
	if (right.FirstNode == this->FirstNode)
		return *this;
	swap(this->size, right.size);
	swap(this->FirstNode, right.FirstNode);
	return *this;
}
Book& Library::operator[](std::size_t index) {
	Node* tmp = this->FirstNode;
	for (std::size_t i = 0; i < index; i++) {
		tmp = tmp->GetNext();
	}

	return tmp->GetVal();
}
const Book& Library::operator[](std::size_t index) const {
	Node* tmp = this->FirstNode;
	for (std::size_t i = 0; i < index; i++) {
		tmp = tmp->GetNext();
	}

	return tmp->GetVal();
}
std::size_t Library::GetSize() const {
	return this->size;
}
Node* Library::GetFirstNode() const {
	return this->FirstNode;
}
Library::~Library() {
	delete this->FirstNode;
}
ostream& operator<<(ostream& out, const Library& lib) {
	out << "Zawartosc biblioteki:\n";
	Node* tmp = lib.GetFirstNode();
	for (int i = 0; i < lib.GetSize(); i++) {
		out << i + 1 << ". " << tmp->GetVal() << "\n";
		tmp = tmp->GetNext();
	}
	return out;
}

void Library::push_back(const Book& b) {
	Node* tmp = this->FirstNode;
	if (tmp == nullptr)
		this->FirstNode = new Node(b);
	else {
		for (int i = 0; i < this->size+1; i++) {
			if (tmp->GetNext() == nullptr) {
				tmp->SetNext(new Node(b));
				break;
			}
			tmp = tmp->GetNext();
		}
	}
	size++;
}
void Library::push_back(Book&& b){
	Node* tmp = this->FirstNode;
	if (tmp == nullptr)
		this->FirstNode = new Node(b);
	else {
		for (int i = 0; i < this->size+1; i++) {
			if (tmp->GetNext() == nullptr) {
				tmp->SetNext(new Node(b));
				break;
			}
			tmp = tmp->GetNext();
		}
	}
	size++;
}
Book Library::pop_back() {
	if (this->size == 0)
		return { "pusta", "lista" };
	if (this->size == 1) {
		Book tmpB = this->FirstNode->GetVal();
		delete this->FirstNode;
		this->FirstNode = nullptr;
		this->size--;
		return tmpB;
	}
	else {
		Node* tmp = FirstNode;
		for (int i = 0; i < this->size - 1; i++) {
			if (tmp->GetNext()->GetNext() == nullptr) {
				Book tmpB = tmp->GetNext()->GetVal();
				delete tmp->GetNext();
				size--;
				return tmpB;
			}
			tmp = tmp->GetNext();
		}
	}
=======
#include "Library.h"

Library::Library() {
	this->size = 0;
	this->FirstNode = nullptr;
}
Library::Library(std::initializer_list<Book> list) {
	this->size = 0;
	this->FirstNode = nullptr;
	for (Book b : list) {
		push_back(b);
	}
}
Library::Library(const Library& orig) {
	this->size = 0;
	this->FirstNode = nullptr;
	for (int i = 0; i < orig.size; i++) {
		push_back(orig[i]);
	}
}
Library::Library(Library&& orig) {
	swap(this->size, orig.size);
	swap(this->FirstNode, orig.FirstNode);
}
Library& Library::operator=(const Library& right) {
	if (right.FirstNode == this->FirstNode)
		return *this;
	delete this->FirstNode;
	this->FirstNode = nullptr;
	this->size = 0;
	for (int i = 0; i < right.size; i++) {
		push_back(right[i]);
	}
	return *this;
}
Library& Library::operator=(Library&& right) {
	if (right.FirstNode == this->FirstNode)
		return *this;
	swap(this->size, right.size);
	swap(this->FirstNode, right.FirstNode);
	return *this;
}
Book& Library::operator[](std::size_t index) {
	Node* tmp = this->FirstNode;
	for (std::size_t i = 0; i < index; i++) {
		tmp = tmp->GetNext();
	}

	return tmp->GetVal();
}
const Book& Library::operator[](std::size_t index) const {
	Node* tmp = this->FirstNode;
	for (std::size_t i = 0; i < index; i++) {
		tmp = tmp->GetNext();
	}

	return tmp->GetVal();
}
std::size_t Library::GetSize() const {
	return this->size;
}
Node* Library::GetFirstNode() const {
	return this->FirstNode;
}
Library::~Library() {
	delete this->FirstNode;
}
ostream& operator<<(ostream& out, const Library& lib) {
	out << "Zawartosc biblioteki:\n";
	Node* tmp = lib.GetFirstNode();
	for (int i = 0; i < lib.GetSize(); i++) {
		out << i + 1 << ". " << tmp->GetVal() << "\n";
		tmp = tmp->GetNext();
	}
	return out;
}

void Library::push_back(const Book& b) {
	Node* tmp = this->FirstNode;
	if (tmp == nullptr)
		this->FirstNode = new Node(b);
	else {
		for (int i = 0; i < this->size+1; i++) {
			if (tmp->GetNext() == nullptr) {
				tmp->SetNext(new Node(b));
				break;
			}
			tmp = tmp->GetNext();
		}
	}
	size++;
}
void Library::push_back(Book&& b){
	Node* tmp = this->FirstNode;
	if (tmp == nullptr)
		this->FirstNode = new Node(b);
	else {
		for (int i = 0; i < this->size+1; i++) {
			if (tmp->GetNext() == nullptr) {
				tmp->SetNext(new Node(b));
				break;
			}
			tmp = tmp->GetNext();
		}
	}
	size++;
}
Book Library::pop_back() {
	if (this->size == 0)
		return { "pusta", "lista" };
	if (this->size == 1) {
		Book tmpB = this->FirstNode->GetVal();
		delete this->FirstNode;
		this->FirstNode = nullptr;
		this->size--;
		return tmpB;
	}
	else {
		Node* tmp = FirstNode;
		for (int i = 0; i < this->size - 1; i++) {
			if (tmp->GetNext()->GetNext() == nullptr) {
				Book tmpB = tmp->GetNext()->GetVal();
				delete tmp->GetNext();
				size--;
				return tmpB;
			}
			tmp = tmp->GetNext();
		}
	}
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}