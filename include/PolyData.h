#pragma once

#include <vector>

#include "PolyNode.h"
#include "Rational.h"

class PolyData
{
public:
	PolyData();
	PolyData(std::vector<Rational> poly);
	~PolyData();
	
	PolyNode& operator[](const int degree);
	bool operator==(const PolyData& other) const;

	void add(const Rational& rational, const int degree);

	const PolyNode* getHead() const;

private:
	PolyNode* buildBST(PolyNode **nodes, const int start, const int end);
	PolyNode* searchNode(const int degree, PolyNode *head) const;

	bool isCompare(const PolyNode* a, const PolyNode* b) const;
	void add(PolyNode*& head, const Rational& rational, const int degree);
	
	void deleteNode(PolyNode* node);
	
	PolyNode* m_head;
};

bool operator!=(const PolyData& a, const PolyData& b);