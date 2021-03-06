#include <iostream>
#include "Poly.h"
#include "Rational.h"

int main()
{
	std::vector<Rational> poly1;
	poly1.emplace_back();
	poly1.emplace_back();
	poly1.emplace_back();
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
	poly3.emplace_back(1, 4);
	poly3.emplace_back(0);
	poly3.emplace_back();

	std::vector<Rational> poly5;
	poly5.emplace_back(-1, 2);
	poly5.emplace_back(1, 2);
	poly5.emplace_back();
	poly5.emplace_back(8, 3);
	poly5.emplace_back();
	poly5.emplace_back();

	Poly p1(poly1);
	Poly p2(poly2);
	Poly p3(poly3);
	Poly p4;
	Poly p5(poly5);

	std::cout << "Comparing tests: " << std::endl;

	bool a = p1 == p3;
	std::cout << (a ? "Test1 failed" : "Test1 pass") << std::endl;

	a = p2 != p4;
	std::cout <<( a ? "Test2 pass" : "Test2 Failed") << std::endl;

	std::cout << "Poly 1 \n" << p1 << std::endl;
	std::cout << "Poly 2 \n" << p2 << std::endl;
	std::cout << "Poly 3 \n" << p3 << std::endl;

	std::cout << p1.getDeg() << std::endl;
	std::cout << p2.getDeg() << std::endl;
	std::cout << p3.getDeg() << std::endl;
	std::cout << p4.getDeg() << std::endl;
	std::cout << p5.getDeg() << std::endl;

	std::cout << "\n\n" << std::endl;

	std::cout << "evaluationa and arithmethic tests: " << std::endl;

	Rational result1(95, 3);
	Rational result2(263, 3);
	Rational result3(85);
	
	Rational result = p1(2);
	std::cout << (result == result1 ? "Test3 Pass" : "Test3 Failed") << std::endl;

	std::cout << p1[2] << std::endl;
	std::cout << p1[3] << std::endl;

	p1 += p2;
	result = p1(2);

	std::cout << p1.getDeg() << std::endl;

	std::cout << (result == result2 ? "Test4 Pass" : "Test4 Failed") << std::endl;
	
	p1 -= p5;
	result = p1(2);

	std::cout << p1.getDeg() << std::endl;

	std::cout << (result == Rational(85) ? "Test5 Pass" : "Test5 Failed") << std::endl;
	
	p1 *= p3;
	result = p1(2);

	std::cout << p1.getDeg() << std::endl;
	std::cout << (result == result3 ? "Test6 Pass" : "Test6 Failed") << std::endl;

	std::cout << "\n\nPoly 1 \n" << p1 << std::endl;
	
	return 0;
}
