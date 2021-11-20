#pragma once

#include <vector>

#include "Rational.h"

class Poly
{
public:
	Poly();
	Poly(const std::vector<int>&);
	Poly(const Rational&);
	Poly(const int, const Rational&);

	//todo: add operators +-* << / %

	int getDeg() const;
	//todo: gcd for polies
private:

	unsigned int m_deg;
};
