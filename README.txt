1.
ex03 poly

2.
Netanel Stern, ID 206342255
Daniel Yosef, ID 322017518

3.
In this excercise we made representation for polynomials.
The code support rational numbers to build the polynomial and airithmetic operations
on the polynomial (+-*).

The logic tries to use less memory as possible combined with the best time complexity

4.
Rational is an object used to represent a rational number with numerator and denominator.
PolyNode, a struct, is the very basic element of the polynomial data structure, it contains the degree and the rational
value of the element.
PolyData, an object, is a link list that used to store the PolyNodes elements
Poly is an object that used to represent the polynomial and provide varied operators.
It contains PolyData to store the polynomial

5.
Poly.h - header file of Poly class
PolyData.h - header file of PolyData class
PolyNode.h - header file contains PolyNode struct and signature of relevant operators
Rational.h - header file of Rational class

Poly.cpp - implementation of Poly class
PolyData.cpp - implementation of PolyData class and operators of PolyNode
Rational.cpp - implementation of Rational class

8.
PolyNode - a struct that store an element of the polynomial.
it contains a degree of the element, a pointer for the rational value and a pointer for the next node

PolyData - a link list of PolyNode that store the polynomial elements

7. 
while adding a node to the PolyData object, the add function check if there are already existing node with the same degree,
then connect the rational values.
If the new value is 0, the function remove it from the data structure

8.
To find the best solution for less memory and best time complexity we compared a balance BST \ RB Tree \ link list
for most of the required functionallity, the time complexity was similar, but in some other the link list has the best time complexity