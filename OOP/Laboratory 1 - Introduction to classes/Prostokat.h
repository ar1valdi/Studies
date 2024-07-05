<<<<<<< HEAD
#pragma once
#include "FiguraPlaska.h"

class Prostokat : public FiguraPlaska {
private:
	double a, b;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Prostokat(double a, double b);
	double GetA() const;
	void SetA(double a);
	double GetB() const;
	void SetB(double b);
	double Obwod() override;
	double Pole() override;

	~Prostokat() override;
=======
#pragma once
#include "FiguraPlaska.h"

class Prostokat : public FiguraPlaska {
private:
	double a, b;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Prostokat(double a, double b);
	double GetA() const;
	void SetA(double a);
	double GetB() const;
	void SetB(double b);
	double Obwod() override;
	double Pole() override;

	~Prostokat() override;
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};