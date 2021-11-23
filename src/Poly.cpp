#include "Poly.h"
#include "Rational.h"

Poly::Poly():
	Poly(Rational(0))
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

const PolyData& Poly::getData() const
{
	return m_data;
}

Rational Poly::valueInPoint(const PolyNode* node, const Rational& rational) const
{
	auto result = Rational(pow(rational.getNumerator(), node->m_degree),
		pow(rational.getDenominator(), node->m_degree));

	result *= *(node->m_data);

	return result;
}

Rational Poly::calcPoly(const PolyNode* node, const Rational& rational) const
{
	if (node == nullptr)
		return 0;

	auto inPoint = valueInPoint(node, rational);
	auto left = calcPoly(node->m_left, rational);
	auto right = calcPoly(node->m_right, rational);
	
	return valueInPoint(node, rational) +
		calcPoly(node->m_left, rational) +
		calcPoly(node->m_right, rational);
}


//operators
bool Poly::operator==(const Poly& other) const
{
	return m_data == other.getData();
}

bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}

Rational Poly::operator()(const Rational& rational) const
{
	return calcPoly(m_data.getHead(), rational);
}
