<<<<<<< HEAD
#include "Trojkat.h"
#include <iostream>
using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c) {
	cout << "Konstruktor Trojkata(" << a << ", " << b << ", " << c << ")" << endl;
}
void Trojkat::Wypisz(std::ostream& out) const {
	out << "Trojkat o wymiarach: a=" << this->a;
	out << " b=" << this->b;
	out << " c=" << this->c << endl;
}
double Trojkat::GetA() const {
	return this->a;
}
double Trojkat::GetB() const {
	return this->b;
}
double Trojkat::GetC() const {
	return this->c;
}
void Trojkat::SetA(double a) {
	this->a = a;
}
void Trojkat::SetB(double b) {
	this->b = b;
}
void Trojkat::SetC(double c) {
	this->c = c;
}
double Trojkat::Obwod() {
	return this->a + this->b + this->c;
}
double Trojkat::Pole() {
	double p = Obwod() / 2;
	return sqrt(p * (p-this->a) * (p - this->b) * (p - this->c));
}
Trojkat::~Trojkat() {
	cout << "Zawartosc obiektu a = " << this->a << ", b = " << this->b;
	cout << ", c = " << this->c << endl;
=======
#include "Trojkat.h"
#include <iostream>
using namespace std;

Trojkat::Trojkat(double a, double b, double c) : a(a), b(b), c(c) {
	cout << "Konstruktor Trojkata(" << a << ", " << b << ", " << c << ")" << endl;
}
void Trojkat::Wypisz(std::ostream& out) const {
	out << "Trojkat o wymiarach: a=" << this->a;
	out << " b=" << this->b;
	out << " c=" << this->c << endl;
}
double Trojkat::GetA() const {
	return this->a;
}
double Trojkat::GetB() const {
	return this->b;
}
double Trojkat::GetC() const {
	return this->c;
}
void Trojkat::SetA(double a) {
	this->a = a;
}
void Trojkat::SetB(double b) {
	this->b = b;
}
void Trojkat::SetC(double c) {
	this->c = c;
}
double Trojkat::Obwod() {
	return this->a + this->b + this->c;
}
double Trojkat::Pole() {
	double p = Obwod() / 2;
	return sqrt(p * (p-this->a) * (p - this->b) * (p - this->c));
}
Trojkat::~Trojkat() {
	cout << "Zawartosc obiektu a = " << this->a << ", b = " << this->b;
	cout << ", c = " << this->c << endl;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}