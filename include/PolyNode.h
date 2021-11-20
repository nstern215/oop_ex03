#pragma once

class Rational;

struct PolyNode
{
	int m_degree;
	Rational* m_data;
	PolyNode* m_left;
	PolyNode* m_right;
};
