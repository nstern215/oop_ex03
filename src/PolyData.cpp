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

PolyNode* PolyData::buildBST(PolyNode **nodes, const int start, const int end)
{	
	if (start == end)
		return nodes[start];
	
	auto mid = (start + end) / 2;
	nodes[mid]->m_left = buildBST(nodes, start, mid - 1);
	nodes[mid]->m_right = buildBST(nodes, mid + 1, end);

	return nodes[mid];
}
