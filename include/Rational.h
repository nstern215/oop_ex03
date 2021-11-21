#pragma once

class Rational
{
public:
	Rational();
	Rational(const Rational& other);
	Rational(const int numerator);
	Rational(const int numerator, const int denominator);

	Rational& operator=(const Rational& other);
	//todo: add operators (check if relevant): <<
	//pay attention for reuse and global operators
	//<
	//>
	//!
	//<=
	//>=
	//==
	//+
	//-
	//*
	///
	//+=
	//-=
	//*=
	///=
	//%
	//gcd
	
	int getNumerator() const;
	int getDenominator() const;

private:
	void minimize_fraction();
	
	int m_numerator; //mone
	int m_denominator; //mechane
};
