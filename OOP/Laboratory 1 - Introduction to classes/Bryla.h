<<<<<<< HEAD
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
=======
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
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
};