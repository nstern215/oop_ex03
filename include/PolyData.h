#pragma once

#include <vector>

#include "PolyNode.h"
#include "Rational.h"

class PolyData
{
public:
	PolyData();
	PolyData(std::vector<Rational> poly);
	PolyData(const PolyData&);
	~PolyData();
	
	PolyNode* operator[](const int degree) const;
	bool operator==(const PolyData& other) const;

	void add(const Rational& rational, const int degree);

	PolyNode* getHead() const;

private:
	bool isCompare(const PolyNode* a, const PolyNode* b) const;
	
	void deleteNode(PolyNode* node);
	
	PolyNode* m_head;
};

bool operator!=(const PolyData& a, const PolyData& b);
