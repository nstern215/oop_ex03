#include "Poly.h"
#include "Rational.h"
#include "PolyNode.h"

#include <ostream>
#include <iostream>

Poly::Poly(const std::vector<Rational>& poly):
	m_data(poly)
{}

Poly::Poly(const Rational& rational):
	Poly(1, rational)
{}

Poly::Poly(const int degree, const Rational& rational)
{
	m_data.add(rational, degree);
}

Poly::Poly(const Poly& p)
	: m_data(p.getData())
{
}

int Poly::getDeg() const
{
	return m_data.getHead()->m_degree;
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

bool Poly::operator==(const Poly& other) const
{
	return m_data == other.getData();
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
	temp += Poly(other.m_degree , *(other.m_data));
	return temp;
}


Poly Poly::operator*(const Poly& other) const
{
	Poly result;
	auto* node = m_data.getHead();
	if (node == nullptr)
	{
		std::cerr << "faild to allocate memory";
		exit(EXIT_FAILURE);
	}

	while(node != nullptr)
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
	auto* node = other.getData().getHead();
	if (node == nullptr)
	{
		std::cerr << "faild to allocate memory";
		exit(EXIT_FAILURE);
	}

	while(node != nullptr)
	{
		m_data.add(*(node->m_data), node->m_degree);
		node = node->m_next;
	}

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
	m_data = result.getData();
	return *this;
}

bool operator!=(const Poly& a, const Poly& b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Poly& other)
{
	auto* node = other.getData().getHead();
	if (node == nullptr)
	{
		std::cerr << "faild to allocate memory";
		exit(EXIT_FAILURE);
	}
	bool firstPrint = true;

	while(node != nullptr)
	{
		if (node->m_data->getNumerator() > 0 && !firstPrint)
			os << "+";
		
		os << *(node->m_data) << "*X" << "^" << node->m_degree << " ";;
		firstPrint = false;
		node = node->m_next;
	}
	return os;
}