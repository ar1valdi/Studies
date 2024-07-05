<<<<<<< HEAD
#pragma once
#include "Bryla.h"

class Prostopadl : public Bryla {
private:
	double a, b, h;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Prostopadl(double a, double b, double h);

	double PoleCal() override;
	double PoleBocz() override;
	double Objetosc() override;
	~Prostopadl() override;
=======
#pragma once
#include "Bryla.h"

class Prostopadl : public Bryla {
private:
	double a, b, h;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Prostopadl(double a, double b, double h);

	double PoleCal() override;
	double PoleBocz() override;
	double Objetosc() override;
	~Prostopadl() override;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};