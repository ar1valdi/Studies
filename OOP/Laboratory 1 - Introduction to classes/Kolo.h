<<<<<<< HEAD
#pragma once
#include "FiguraPlaska.h"

class Kolo : public FiguraPlaska {
	double r;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Kolo(double r);
	double GetR() const;
	void SetR(double r);
	double Obwod() override;
	double Pole() override;

	~Kolo() override;
};
=======
#pragma once
#include "FiguraPlaska.h"

class Kolo : public FiguraPlaska {
	double r;
protected:
	void Wypisz(std::ostream& out) const override;
public:
	Kolo(double r);
	double GetR() const;
	void SetR(double r);
	double Obwod() override;
	double Pole() override;

	~Kolo() override;
};
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
