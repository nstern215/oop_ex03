#include "Poly.h"
#include "Rational.h"

Poly::Poly():
	m_deg(0)
{}

Poly::Poly(const std::vector<Rational>& poly):
	m_deg(poly.size()),
	m_data(poly)
{}

Poly::Poly(const Rational& rational):
	Poly(1, rational)
{}

Poly::Poly(const int degree, const Rational& rational):
	m_deg(degree)
{
	m_data.add(rational, 1);
}

int Poly::getDeg() const
{
	return m_deg;
}

PolyData Poly::getData() const
{
	return m_data;
}


bool Poly::operator==(const Poly& other) const
{
	return m_data == other.getData();
}

bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}