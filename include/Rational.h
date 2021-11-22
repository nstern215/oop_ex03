#pragma once

class Rational
{
public:
	Rational();
	Rational(const Rational& other);
	Rational(const int numerator);
	Rational(const int numerator, const int denominator);

	Rational& operator=(const Rational& other);

	Rational& operator-();
	Rational operator-() const;
	Rational& operator+();

	Rational& operator+=(const Rational& other);
	Rational& operator-=(const Rational& other);
	Rational& operator*=(const Rational& other);
	Rational& operator/=(const Rational& other);
	
	int getNumerator() const;
	int getDenominator() const;

private:
	void minimize_fraction();
	
	int m_numerator; //mone
	int m_denominator; //mechane
};

Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);