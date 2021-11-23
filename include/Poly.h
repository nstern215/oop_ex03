#pragma once

#include <vector>

#include "PolyData.h"
#include "Rational.h"

class Poly
{
public:
	Poly();
	Poly(const std::vector<Rational>& poly);
	Poly(const Rational& rational);
	Poly(const int degree, const Rational& rational);

	bool operator==(const Poly& other) const;

	PolyData getData() const;

	//todo: add operators +-* << / %

	int getDeg() const;
	//todo: gcd for polies
private:
	PolyData m_data;
	unsigned int m_deg;
};

bool operator!=(const Poly& a, const Poly& b);