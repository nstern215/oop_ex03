#pragma once

#include <vector>

#include "PolyNode.h"
#include "Rational.h"

class PolyData
{
public:
	PolyData();
	PolyData(std::vector<Rational> poly);

private:
	PolyNode* buildBST(PolyNode **nodes, const int start, const int end);
	
	PolyNode* m_head;
};
