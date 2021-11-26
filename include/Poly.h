#pragma once

#include <vector>

#include "PolyData.h"
#include "Rational.h"

class Poly
{
public:
	Poly(const std::vector<Rational>& poly);
	Poly(const Rational& rational);
	Poly(const int degree = 0, const Rational& rational = 0);
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
	Poly operator*(const Poly& other) const;
	Poly operator*(const PolyNode& other) const;

	Poly& operator+=(const Poly& other);
	Poly& operator+=(const PolyNode& other);
	Poly& operator-=(const Poly& other);
	Poly& operator*=(const Poly& other);

	PolyData copyData(const Poly& poly) const;
	int getDeg() const;

private:
	Rational valueInPoint(const PolyNode* node, const Rational& rational) const;
	PolyData m_data;
};

Poly operator+(const Poly& a, const Poly& b);

bool operator!=(const Poly& a, const Poly& b);

std::ostream& operator<<(std::ostream& os, const Poly& other);