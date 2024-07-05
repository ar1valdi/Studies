<<<<<<< HEAD
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Kolo.h"
using namespace std;

Kolo::Kolo(double r) : r(r) {
	cout << "Konstruktor kola r=" << r << endl;
}
void Kolo::Wypisz(std::ostream& out) const {
	out << "Kolo o promieniu r=" << this->r;
}
double Kolo::GetR() const {
	return this->r;
}
void Kolo::SetR(double r) {
	this->r = r;
}
double Kolo::Obwod() {
	return M_PI * this->r * 2;
}
double Kolo::Pole() {
	return M_PI * this->r * this->r;
}
Kolo::~Kolo() {
	cout << "Zawartosc obiektu r = " << this->r << endl;
=======
#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "Kolo.h"
using namespace std;

Kolo::Kolo(double r) : r(r) {
	cout << "Konstruktor kola r=" << r << endl;
}
void Kolo::Wypisz(std::ostream& out) const {
	out << "Kolo o promieniu r=" << this->r;
}
double Kolo::GetR() const {
	return this->r;
}
void Kolo::SetR(double r) {
	this->r = r;
}
double Kolo::Obwod() {
	return M_PI * this->r * 2;
}
double Kolo::Pole() {
	return M_PI * this->r * this->r;
}
Kolo::~Kolo() {
	cout << "Zawartosc obiektu r = " << this->r << endl;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
}