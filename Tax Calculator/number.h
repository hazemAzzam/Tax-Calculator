#pragma once
#include <iostream>
#include <string>

using namespace std;
class number
{
	double num;
	double inte(double r);
public:
	number(double r = 0);

	double taxsRatio();

	number operator-(double n);
	number operator+(double n);
	number operator*(double n);
	number operator/(double n);

	number operator-(int n);
	number operator+(int n);
	number operator*(int n);
	number operator/(int n);
	number operator=(double n);
	number operator=(int n);

	operator double();

	friend ostream& operator<<(ostream& out, const number& d);
	friend istream& operator>>(istream& in, number& d);
};

