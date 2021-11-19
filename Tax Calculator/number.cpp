#include "number.h"
#include <vector>
#include <iostream>

using namespace std;

double number::inte(double r)
{
	string s = to_string(r);
	string num = "";
	string num1 = "0", num2 = "0";
	bool flag = false;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '.') {
			flag = true;
			continue;
		}
		if (flag) {
			for (int j = i; j < i + 2 && j < s.length(); j++) {
				if (j == i)
					num1 = s[j];
				else
					num2 = s[j];
			}
			break;
		}
		else {
			num += s[i];
		}
	}
	int n0 = stoi(num);
	int n1 = stoi(num1);
	int n2 = stoi(num2);

	if (n2 >= 1 && n2 <= 4) {
		n2 = 5;
	}
	else if (n2 >= 6 && n2 <= 9) {
		n2 = 0;
		n1++;
		if (n1 >= 10) {
			n0++;
			n1 = 0;
		}
	}
	return stod(to_string(n0) + '.' + to_string(n1) + to_string(n2));
}

number::number(double r)
{
	num = inte(r);
}

double number::taxsRatio()
{
	vector<int> money = {250, 500, 1000, 5000, 10000};
	vector<double> ratio = { 0.012, 0.013, 0.014, 0.015, 0.016 };

	for (int i = 0; i < money.size(); i++) {
		if (num <= money[i])
			return ratio[i];
	}
	return 0.017;
}

number number::operator-(double n)
{
	return num - n;
}

number number::operator+(double n)
{
	return num + n;
}

number number::operator*(double n)
{
	return num * n;
}

number number::operator/(double n)
{
	return num / n;
}

number number::operator-(int n)
{
	return num - n;
}

number number::operator+(int n)
{
	return num + n;
}

number number::operator*(int n)
{
	return num * n;
}

number number::operator/(int n)
{
	return num / n;
}

number number::operator=(double n)
{
	num = inte(n);
	return num;
}

number number::operator=(int n)
{
	num = inte(n);
	return num;
}

number::operator double()
{
	return num;
}

ostream& operator<<(ostream& out, const number& d)
{
	out << d.num;
	return out;
}

istream& operator>>(istream& in, number& d)
{
	in >> d.num;
	d.num = d.inte(d.num);
	return in;
}
