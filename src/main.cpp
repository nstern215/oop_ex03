#include <iostream>


#include "Poly.h"
#include "Rational.h"

int main()
{
	/*Poly p1(Rational(1));
	Poly p2;

	std::cout << (p1 == p2) << std::endl;
	std::cout << (p1 != p2) << std::endl;*/

	/*std::vector<Rational> poly = {(1,2), (2,3), (3,4), (4,5)};*/

	/*Poly p3(poly), p4(poly);*/

	std::vector<Rational> poly = {
		Rational(1,2),
		Rational(2),
		Rational(1,5),
		Rational(5)
	};
	//std::vector<Rational> poly;
	//poly.push_back(Rational(1, 2));
	//poly.push_back(Rational(2));
	//poly.push_back(Rational(1, 5));
	//poly.push_back(Rational(5));
	
	Poly p(poly);
	
	std::cout << p(2) << std::endl;
	
    return 0;
}
