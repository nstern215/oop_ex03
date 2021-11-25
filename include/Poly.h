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
	Poly(const Poly&);

	bool operator==(const Poly& other) const;
	Rational operator()(const Rational& rational) const;
	Rational operator[](const int deg) const;

	Poly& operator-();
	Poly operator-() const;
	Poly& operator+();
	Poly operator+() const;

	Poly operator+(const PolyNode& other) const;
	Poly operator-(const Poly& other) const;
	//Poly operator*(const Poly& other) const;

	Poly& operator+=(const Poly& other);
	Poly& operator+=(const PolyNode& other);
	Poly& operator-=(const Poly& other);
	Poly& operator*=(const Poly& other);

	const PolyData& getData() const;
	int getDeg() const;

	//todo: add operators +-* << / %
	//todo: gcd for polies
private:
	Rational valueInPoint(const PolyNode* node, const Rational& rational) const;
	PolyData m_data;
};

Poly operator+(const Poly& a, const Poly& b);

bool operator!=(const Poly& a, const Poly& b);

std::ostream& operator<<(std::ostream& os, const Poly& other);

//Poly operator*(const PolyNode& other) const;