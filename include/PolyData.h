#pragma once

#include <vector>

#include "PolyNode.h"
#include "Rational.h"

class PolyData
{
public:
	PolyData()=delete;
	PolyData(std::vector<Rational> poly);
	PolyNode& operator[](const int degree);

private:
	PolyNode* buildBST(PolyNode **nodes, const int start, const int end);
	PolyNode* searchNode(const int degree, PolyNode *head) const;
	
	PolyNode* m_head;
};
