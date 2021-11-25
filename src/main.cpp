#include <iostream>
#include "Poly.h"
#include "Rational.h"

int main()
{
	std::vector<Rational> poly1;
	poly1.emplace_back(1, 2);
	poly1.emplace_back();
	poly1.emplace_back(8, 3);
	poly1.emplace_back(4);
	poly1.emplace_back(5);

	std::vector<Rational> poly2;
	poly2.emplace_back(3, 2);
	poly2.emplace_back(0);
	poly2.emplace_back(1);
	poly2.emplace_back();
	poly2.emplace_back(0);
	poly2.emplace_back();

	std::vector<Rational> poly3;
	poly3.emplace_back(1,4);
	poly3.emplace_back(0);
	poly3.emplace_back();

	Poly p1(poly1);
	Poly p2(poly2);
	Poly p3(poly3);
	Poly p4;

	std::cout << "Comparing tests: " << std::endl;
	
	bool a = p1 == p3;
	std::cout << (a ? "Test failed" : "Test pass") << std::endl;

	a = p2 != p4;
	std::cout <<( a ? "Test pass" : "Test Failed") << std::endl;

	std::cout << "Poly 1 \n" << p1 << std::endl;
	std::cout << "Poly 2 \n" << p2 << std::endl;
	std::cout << "Poly 3 \n" << p3 << std::endl;

	std::cout << "\n\n" << std::endl;

	std::cout << "evaluationa and arithmethic tests: " << std::endl;
	
	Rational result1(95, 3);
	Rational result2(263, 3);
	Rational result3(85);
	
	Rational result = p1(2);
	std::cout << (result == result1 ? "Test Pass" : "Test Failed") << std::endl;

	p1 += p2;
	result = p1(2);

	std::cout << (result == result2 ? "Test Pass" : "Test Failed") << std::endl;
	
	/*p4 = (p1 * p3);
	result = p4(2);
	std::cout << (result == result3 ? "Test Pass" : "Test Failed") << std::endl;*/

	p1 *= p3;
	result = p1(2);
	std::cout << (result == result3 ? "Test Pass" : "Test Failed") << std::endl;

	std::cout << "\n\nPoly 1 \n" << p1 << std::endl;
	
	return 0;
}
