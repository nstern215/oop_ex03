#pragma once

class Rational;

struct PolyNode
{
	int m_degree;
	Rational* m_data;
	PolyNode* m_next;
};

bool operator==(const PolyNode& a, const PolyNode& b);
bool operator!=(const PolyNode& a, const PolyNode& b);
