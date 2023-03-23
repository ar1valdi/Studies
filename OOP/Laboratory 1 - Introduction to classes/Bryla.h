#pragma once
#include <iostream>

class Bryla {
protected:
    virtual void Wypisz(std::ostream& out) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Bryla& figura);

public:
    virtual double PoleCal() = 0;
    virtual double PoleBocz() = 0;
    virtual double Objetosc() = 0;
    virtual ~Bryla();
};