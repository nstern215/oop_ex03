#include "PolyData.h"

#include <iostream>

#include "PolyNode.h"

using std::nothrow;
using std::cerr;
using std::endl;

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

	m_head = buildBST(nodes, 0, reauireSpace);
}

PolyData::~PolyData()
{
	deleteNode(m_head);
}


PolyNode& PolyData::operator[](const int degree)
{
	return *searchNode(degree, m_head);
}


PolyNode* PolyData::buildBST(PolyNode **nodes, const int start, const int end)
{	
	if (start == end)
		return nodes[start];
	
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
