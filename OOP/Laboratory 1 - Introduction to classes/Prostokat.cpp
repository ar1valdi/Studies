<<<<<<< HEAD
#include <iostream>
#include "Prostokat.h"
using namespace std;

Prostokat::Prostokat(double a, double b) : a(a), b(b)
{
	cout << "Konstruktor Prostokata(" << a << "," << b << ")" << endl;
}
double Prostokat::GetA() const {
	return a;
}
double Prostokat::GetB() const {
	return b;
}
void Prostokat::SetA(double a) {
	this->a = a;
}
void Prostokat::SetB(double b) {
	this->b = b;
}
double Prostokat::Obwod() {
	return 2*(this->a + this->b);
}
double Prostokat::Pole() {
	return this->a * this->b;
}
void Prostokat::Wypisz(std::ostream& out) const {
	out << "Prostokat o parametrach a = " << this->a << ", b = " << this->b << endl;
}
Prostokat::~Prostokat() {
	cout << "Zawartosc obiektu a = " << this->a << ", b = " << this->b << endl;
=======
#include <iostream>
#include "Prostokat.h"
using namespace std;

Prostokat::Prostokat(double a, double b) : a(a), b(b)
{
	cout << "Konstruktor Prostokata(" << a << "," << b << ")" << endl;
}
double Prostokat::GetA() const {
	return a;
}
double Prostokat::GetB() const {
	return b;
}
void Prostokat::SetA(double a) {
	this->a = a;
}
void Prostokat::SetB(double b) {
	this->b = b;
}
double Prostokat::Obwod() {
	return 2*(this->a + this->b);
}
double Prostokat::Pole() {
	return this->a * this->b;
}
void Prostokat::Wypisz(std::ostream& out) const {
	out << "Prostokat o parametrach a = " << this->a << ", b = " << this->b << endl;
}
Prostokat::~Prostokat() {
	cout << "Zawartosc obiektu a = " << this->a << ", b = " << this->b << endl;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}