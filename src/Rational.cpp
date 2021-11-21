#include "Rational.h"

Rational::Rational(const int numerator, const int denominator):
	m_numerator(numerator),
	m_denominator(denominator)
{
	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}
}

Rational::Rational(const int numerator):
	m_numerator(numerator),
	m_denominator(1)
{}

Rational::Rational():
	m_numerator(1),
	m_denominator(1)
{}

Rational::Rational(const Rational& other):
	m_numerator(other.getNumerator()),
	m_denominator(other.getDenominator())
{}

Rational& Rational::operator=(const Rational& other)
{
	if (this != &other)
	{
		m_numerator = other.getNumerator();
		m_denominator = other.getDenominator();
	}

	return *this;
}

int Rational::getNumerator() const
{
	return m_numerator;
}


int Rational::getDenominator() const
{
	return m_denominator;
}
