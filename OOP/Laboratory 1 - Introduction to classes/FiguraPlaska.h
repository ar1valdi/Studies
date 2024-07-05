<<<<<<< HEAD
#pragma once
#include <iostream>

class FiguraPlaska {
protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const FiguraPlaska& figura);

public:
    virtual double Pole() = 0;
    virtual double Obwod() = 0;
    virtual ~FiguraPlaska();
=======
#pragma once
#include <iostream>

class FiguraPlaska {
protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const FiguraPlaska& figura);

public:
    virtual double Pole() = 0;
    virtual double Obwod() = 0;
    virtual ~FiguraPlaska();
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};