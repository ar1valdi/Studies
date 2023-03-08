#pragma once
#include "Prostopadl.h"
#include "Prostokat.h"
#include <iostream>
using namespace std;

Prostopadl::Prostopadl(double a, double b, double h) : a(a), b(b), h(h) {
	cout << "Stworzono prostopadloscian o wymiarach: " << this->a << "x" << this->b << "x" << this->h << endl;
}
void Prostopadl::Wypisz(std::ostream& out) const {
	out << "Wymiary prostopadloscianiu: " << this->a << "x" << this->b << "x" << this->h << endl;
}
double Prostopadl::PoleBocz() {
	Prostokat x(this->a, this->h);
	Prostokat y(this->h, this->b);
	return x.Pole()*2 + y.Pole()*2;
}
double Prostopadl::PoleCal() {
	Prostokat x(this->a, this->b);
	Prostokat y(this->h, this->b);
	Prostokat z(this->a, this->h);
	return x.Pole()*2 + y.Pole() * 2 + z.Pole()*2;
}
double Prostopadl::Objetosc() {
	return this->a * this->b * this->h;
}
Prostopadl::~Prostopadl() {
	cout << "Destroyerd\n";
}