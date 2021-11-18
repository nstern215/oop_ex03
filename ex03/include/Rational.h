#pragma once

class Rational
{
public:
	Rational() = default;
	Rational(const Rational&);
	Rational(const int);
	Rational(const int, const int);

	Rational operator=(const Rational&);
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
	
	int get_numerrator() const;
	int get_denominator() const;

private:
	int m_numerator; //mone
	int m_denominator; //mechane
};
