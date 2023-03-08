#pragma once
#include "Bryla.h"

std::ostream& operator<<(std::ostream& os, const Bryla& b) {
	b.Wypisz(os);
	return os;
}

Bryla::~Bryla(){}