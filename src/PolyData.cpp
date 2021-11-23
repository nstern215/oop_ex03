#include "PolyData.h"

#include <iostream>

#include "PolyNode.h"

using std::nothrow;
using std::cerr;
using std::endl;

PolyData::PolyData():
	m_head(nullptr)
{}

PolyData::PolyData(std::vector<Rational> poly)
{
	int reauireSpace = 0;
	for (const auto& r : poly)
		if (r.getNumerator() != 0)
			reauireSpace++;

	PolyNode** nodes = new (nothrow) PolyNode*[reauireSpace];

	if (nodes == nullptr)
	{
		cerr << "Failed to allocate memory" << endl;
		exit(EXIT_FAILURE);
	}

	int nodesCounter = 0;
	for (int i=0; i < poly.size(); i++)
	{
		if (poly[i].getNumerator() != 0)
		{
			PolyNode* node = new PolyNode;
			node->m_degree = i;
			node->m_data = new Rational(poly[i]);
			node->m_left = nullptr;
			node->m_right = nullptr;
			
			nodes[nodesCounter] = node;

			nodesCounter++;
		}
	}

	m_head = buildBST(nodes, 0, reauireSpace - 1);
}

PolyData::~PolyData()
{
	deleteNode(m_head);
}


PolyNode& PolyData::operator[](const int degree)
{
	return *searchNode(degree, m_head);
}

bool PolyData::operator==(const PolyData& other) const
{
	return isCompare(m_head, other.getHead());
}

bool operator!=(const PolyData& a, const PolyData& b)
{
	return !(a == b);
}

PolyNode* PolyData::buildBST(PolyNode **nodes, const int start, const int end)
{	
	if (start > end)
		return nullptr;
	
	auto mid = (start + end) / 2;
	nodes[mid]->m_left = buildBST(nodes, start, mid - 1);
	nodes[mid]->m_right = buildBST(nodes, mid + 1, end);

	return nodes[mid];
}

PolyNode* PolyData::searchNode(const int degree, PolyNode* head) const
{
	if (head == nullptr)
		return nullptr;
	
	if (head->m_degree == degree)
		return head;

	if (degree < head->m_degree)
		return searchNode(degree, head->m_left);

	return searchNode(degree, head->m_right);
}

void PolyData::deleteNode(PolyNode* node)
{
	if (node == nullptr)
		return;

	deleteNode(node->m_left);
	deleteNode(node->m_right);

	delete node->m_left;
	delete node->m_right;
	delete node;
}

bool PolyData::isCompare(const PolyNode* a, const PolyNode* b) const
{
	if (a == nullptr || b == nullptr)
	{
		if (a == nullptr && b == nullptr)
			return true;

		return false;
	}
	
	//todo: check if can compare pointers
	if (*a != *b)
		return false;

	return isCompare(a->m_left, b->m_left) &&
		isCompare(a->m_right, b->m_right);
}

void PolyData::add(const Rational& rational, const int degree)
{
	add(m_head, rational, degree);
}

void PolyData::add(PolyNode*& head, const Rational& rational, const int degree)
{
	if (head == nullptr)
	{
		//todo: code reuse for node creation
		PolyNode* node = new (nothrow) PolyNode();
		//todo: error if allocation failed

		/**(node->m_data) = rational;*/
		Rational* r = new Rational(rational);
		/*node->m_data = new Rational(rational);*/
		node->m_data = r;
		node->m_degree = degree;

		node->m_left = nullptr;
		node->m_right = nullptr;

		head = node;
	}
	else if (head->m_degree == degree)
	{
		*(head->m_data) +=
 rational;		
	}
	else if (degree < head->m_degree)
	{
		if (head->m_left)
			add(head->m_left, rational, degree);
		else
		{
			auto node = new (nothrow) PolyNode();
			//todo: error if allocation failed

			*(node->m_data) = rational;
			node->m_degree = degree;

			node->m_left = nullptr;
			node->m_right = nullptr;
			
			head->m_left = node;
		}
	}
	else
	{
		if (head->m_right)
			add(head->m_right, rational, degree);
		else
		{
			auto node = new (nothrow) PolyNode();
			//todo: error if allocation failed

			*(node->m_data) = rational;
			node->m_degree = degree;

			node->m_left = nullptr;
			node->m_right = nullptr;

			head->m_right = node;
		}
	}
}


const PolyNode* PolyData::getHead() const
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