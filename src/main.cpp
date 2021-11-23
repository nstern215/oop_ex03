#include <iostream>


#include "Poly.h"
#include "Rational.h"

int main()
{
	Poly p1(Rational(1));
	Poly p2;

	std::cout << (p1 == p2) << std::endl;
	std::cout << (p1 != p2) << std::endl;

	std::vector<Rational> poly = {(1,2), (2,3), (3,4), (4,5)};

	Poly p3(poly), p4(poly);

	std::cout << (p3 == p4) << std::endl;
	
    return 0;
}
