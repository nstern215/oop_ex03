#include "Rational.h"

#include <numeric>
#include <ostream>

Rational::Rational(const int numerator, const int denominator):
	m_numerator(numerator),
	m_denominator(denominator)
{
	if (m_denominator < 0)
	{
		m_numerator *= -1;
		m_denominator *= -1;
	}

	minimize_fraction();
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


//operators
//Local operators
Rational& Rational::operator=(const Rational& other)
{
	if (this != &other)
	{
		m_numerator = other.getNumerator();
		m_denominator = other.getDenominator();
	}

	return *this;
}

Rational& Rational::operator-()
{
	m_numerator *= -1;
	return *this;
}

Rational Rational::operator-() const
{
	return Rational(-m_numerator, m_denominator);
}


Rational& Rational::operator+()
{
	return *this;
}

Rational& Rational::operator+=(const Rational& other)
{
	*this = *this + other;
	return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
	*this += -other;
	return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
	*this = *this * other;
	return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
	*this = *this / other;
	return *this;
}

bool Rational::operator<(const Rational& other) const
{
	if (m_denominator == other.getDenominator())
	{
		return m_numerator < other.getNumerator();
	}

	const auto lcm = std::lcm(m_denominator, other.getDenominator());

	return m_numerator * (lcm / m_denominator) < other.getNumerator() * (lcm / other.getDenominator());
}

bool Rational::operator==(const Rational& other) const
{
	return m_numerator == other.getNumerator() &&
		m_denominator == other.getDenominator();
}


//Global operators
Rational operator+(const Rational& a, const Rational& b)
{
	const auto lcm = std::lcm(a.getDenominator(), b.getDenominator());
	
	return Rational(a.getNumerator() + b.getNumerator(), lcm);
}

Rational operator-(const Rational& a, const Rational& b)
{
	return a + -b;
}

Rational operator*(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator() * b.getNumerator(),
		a.getDenominator() * b.getDenominator());
}

Rational operator/(const Rational& a, const Rational& b)
{
	return Rational(a.getNumerator() * b.getDenominator(),
		a.getDenominator() * b.getNumerator());
}

int Rational::getNumerator() const
{
	return m_numerator;
}


int Rational::getDenominator() const
{
	return m_denominator;
}

void Rational::minimize_fraction()
{
	auto gcd = std::gcd(m_numerator, m_denominator);

	while (gcd != 1)
	{
		m_numerator /= gcd;
		m_denominator /= gcd;

		gcd = std::gcd(m_numerator, m_denominator);
	}
}

bool operator!=(const Rational& a, const Rational& b)
{
	return !(a == b);
}

bool operator>(const Rational& a, const Rational& b)
{
	return !(a < b) && a != b;
}
bool operator<=(const Rational& a, const Rational& b)
{
	return a < b || a == b;
}
bool operator>=(const Rational& a, const Rational& b)
{
	return a > b || a == b;
}

std::ostream& operator<<(std::ostream& stream, const Rational& other)
{
	stream << other.getNumerator() << "/" << other.getDenominator();
	return stream;
}