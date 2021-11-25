#include "PolyData.h"

#include <iostream>

#include "PolyNode.h"

using std::nothrow;
using std::cerr;
using std::endl;

PolyData::PolyData():
	m_head(nullptr)
{}

PolyData::PolyData(std::vector<Rational> poly):
	m_head(nullptr)
{
	unsigned int deg = poly.size();
	
	PolyNode* current = m_head;
	for (const auto& rational : poly)
	{
		deg--;
		
		if (rational.getNumerator() == 0)
			continue;

		auto* elem = new PolyNode();
		elem->m_degree = deg;
		elem->m_data = new Rational(rational);
		elem->m_next = nullptr;

		if (current == nullptr)
		{
			current = elem;
			m_head = current;
		}
		else
		{
			current->m_next = elem;
			current = current->m_next;
		}
	}
}

PolyData::PolyData(const PolyData& other):
	m_head(nullptr)
{
	if (other.getHead() == nullptr)
		return;

	auto* tempHead = other.getHead();
	while (tempHead != nullptr)
	{
		add(*(tempHead->m_data), tempHead->m_degree);

		tempHead = tempHead->m_next;
	}
}

PolyData::~PolyData()
{
	while (m_head != nullptr)
	{
		auto* temp = m_head;
		m_head = m_head->m_next;

		temp->m_next = nullptr;
		delete temp;
	}
}


PolyNode* PolyData::operator[](const int degree) const
{
	auto* current = m_head;
	while(current != nullptr)
	{
		if (current->m_degree == degree)
			return current;

		current = current->m_next;
	}

	return current;
}

bool PolyData::operator==(const PolyData& other) const
{
	return isCompare(m_head, other.getHead());
}

bool operator!=(const PolyData& a, const PolyData& b)
{
	return !(a == b);
}

void PolyData::deleteNode(PolyNode* node)
{
	if (m_head == node)
	{
		auto* temp = m_head;
		m_head = m_head->m_next;
		delete m_head;
	}
	
	auto* current = m_head;

	while(current != nullptr)
	{
		if (current->m_next == node)
		{
			auto* temp = current->m_next;
			current->m_next = current->m_next->m_next;

			temp->m_next = nullptr;
			delete temp;

			return;
		}
	}
}

bool PolyData::isCompare(const PolyNode* a, const PolyNode* b) const
{
	return  a->m_degree == b->m_degree &&
		*(a->m_data) == *(b->m_data);
}

void PolyData::add(const Rational& rational, const int degree)
{
	if (m_head == nullptr || m_head->m_degree == degree)
	{
		auto* node = new (nothrow) PolyNode();
		node->m_data = new Rational(rational);
		node->m_next = m_head == nullptr ? nullptr : m_head->m_next;

		m_head = node;

		return;
	}
	
	auto* current = m_head;
	while (current->m_next != nullptr)
	{
		if (current->m_degree == degree)
		{
			*(current->m_data) += rational;
			return;
		}

		if (current->m_next->m_degree < degree)
			break;
	}

	auto* newNode = new (nothrow) PolyNode();

	if (newNode == nullptr)
	{
		//todo print error
	}

	newNode->m_degree = degree;
	newNode->m_data = new Rational(rational);
	newNode->m_next = current->m_next;
	current->m_next = newNode;
}

PolyNode* PolyData::getHead() const
{
	return m_head;
}

bool operator==(const PolyNode& a, const PolyNode& b)
{
	return (a.m_data->getNumerator() == b.m_data->getNumerator()) &&
		(a.m_data->getDenominator() == b.m_data->getDenominator()) &&
		a.m_degree == b.m_degree;
}

bool operator!=(const PolyNode& a, const PolyNode& b)
{
	return !(a == b);
}

