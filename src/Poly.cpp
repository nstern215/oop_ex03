#include "Poly.h"
#include "Rational.h"
#include "PolyNode.h"

#include <ostream>
#include <iostream>

Poly::Poly(const std::vector<Rational>& poly) :
	m_data(poly)
{}

Poly::Poly(const Rational& rational) :
	Poly(1, rational)
{}

Poly::Poly(const int degree, const Rational& rational)
{
	if ((degree == 0) && (rational == (0, 0)))
	{
		m_data.add(0, -1);
	}
	else
	{
		m_data.add(rational, degree);
	}
}

Poly::Poly(const Poly& p)
{
	int deg = p.getDeg();

	for (int i = deg; i >= 0; i--)
	{
		m_data.add(p[i], i);
	}
}

int Poly::getDeg() const
{
	return m_data.getHead()->m_degree;
}

Rational Poly::valueInPoint(const PolyNode* node, const Rational& rational) const
{
	auto result = Rational(pow(rational.getNumerator(), node->m_degree),
		pow(rational.getDenominator(), node->m_degree));

	result *= *(node->m_data);

	return result;
}

bool Poly::operator==(const Poly& other) const
{
	if (getDeg() != other.getDeg())
		return false;

	for (int i = getDeg(); i >= 0; i--)
		if ((*this)[i] != other[i])
			return false;

	return true;
}

Rational Poly::operator()(const Rational& rational) const
{
	Rational result;

	auto* current = m_data.getHead();

	while (current != nullptr)
	{
		result += valueInPoint(current, rational);
		current = current->m_next;
	}

	return result;
}


Rational Poly::operator[](const int deg) const
{
	PolyNode* node = m_data[deg];

	return node == nullptr ? 0 : *(node->m_data);
}


Poly operator+(const Poly& a, const Poly& b)
{
	Poly result(a);
	result += b;
	return result;
}


Poly& Poly::operator-()
{
	auto* node = m_data.getHead();

	while (node != nullptr)
	{
		-(*(node->m_data));
		node = node->m_next;
	}
	return *this;
}

Poly Poly::operator-() const
{
	Poly temp(*this);

	return -temp;
}

Poly Poly::operator-(const Poly& other) const
{
	Poly temp(other);
	return (-temp);
}


Poly& Poly::operator+()
{
	return *this;
}

Poly Poly::operator+() const
{
	return *this;
}

Poly Poly::operator+(const PolyNode& other) const
{
	Poly temp(*this);
	temp += Poly(other.m_degree, *(other.m_data));
	return temp;
}


Poly Poly::operator*(const Poly& other) const
{
	Poly result;
	int deg;
	deg = other.getDeg();
	auto* node = m_data.getHead();
	if (node == nullptr)
	{
		std::cerr << "faild to allocate memory";
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i <= (deg + 1); i++)
	{
		result += (other * (*node));
		node = node->m_next;
	}
	return result;
}

Poly Poly::operator*(const PolyNode& other) const
{
	Poly result;
	auto* node = m_data.getHead();
	if (node == nullptr)
	{
		std::cerr << "faild to allocate memory";
		exit(EXIT_FAILURE);
	}

	while (node != nullptr)
	{
		Rational rationalResult = *(node->m_data) * *other.m_data;
		int newDeg = node->m_degree + other.m_degree;
		result += Poly(newDeg, rationalResult);

		node = node->m_next;
	}
	return result;
}

Poly& Poly::operator+=(const Poly& other)
{
	for (int i = other.getDeg(); i >= 0; i--)
		m_data.add(other[i], i);

	return *this;
}

Poly& Poly::operator+=(const PolyNode& other)
{
	m_data.add(*other.m_data, other.m_degree);
	return *this;
}

Poly& Poly::operator-=(const Poly& other)
{
	*this += (-other);

	return *this;
}

Poly& Poly::operator*=(const Poly& other)
{
	Poly result = *this * other;

	m_data = PolyData();

	for (int i = result.getDeg(); i >= 0; i--)
		m_data.add(result[i], i);

	return *this;
}

bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Poly& other)
{
	const auto deg = other.getDeg();
	bool firstPrint = true;

	for (int i = deg; i >= 0; i--)
	{
		auto elem = other[i];
		if (elem.getNumerator() != 0)
		{
			if (elem.getNumerator() > 0 && !firstPrint)
				os << "+";

			if (i == 0)
				break;
			os << elem << "*x^" << i;

			firstPrint = false;
		}
	}
	return os;
}