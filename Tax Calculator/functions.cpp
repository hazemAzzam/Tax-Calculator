#include "functions.h"
#include <iostream>
#include <vector>
#include <string>
#include "number.h"

using namespace std;


char bounds = '|';
string separator = " | ";
char inside = '~';

void print(vector<string> data, vector<string> resu)
{
	int maxLengthFirstRow = maxStringLength(data);
	int maxLengthSecondRow = maxStringLength(resu);
	int width = maxLengthFirstRow + maxLengthSecondRow + 6;

	printLine(width);
	for (int i = 0; i < data.size(); i++) {
		cout << "\n" << bounds;
		cout << data[i] << printWhiteSpace(maxLengthFirstRow - data[i].length()) << separator << resu[i] << printWhiteSpace(maxLengthSecondRow - resu[i].length());
		cout << " " << bounds << "\n";
		printLine(width);
	}
	cout << endl;
}

int maxStringLength(vector<string> data)
{
	int maxLength = data[0].length();
	for (int i = 1; i < data.size(); i++)
		if (data[i].length() > maxLength)
			maxLength = data[i].length();
	return maxLength;
}

void printLine(int width)
{
	cout << bounds;

	for (int i = 1; i < width - 1; i++)
		cout << inside;

	cout << bounds;
}

string printWhiteSpace(int width)
{
	string result = "";
	for (int i = 0; i < width; i++)
		result += " ";
	return result;
}

string convert(number n)
{
	string result = "";
	string wrong = to_string(n);
	bool flag = true;
	int s = wrong.length() + 1;
	for (int i = 0; i < wrong.length(); i++) {
		if (wrong[i] == '.') {
			s = i;
			break;
		}
	}



	for (int i = wrong.length() - 1; i >= s; i--) {
		if (flag && wrong[i] == '0')
			wrong.pop_back();
		else if (flag && wrong[i] == '.') {
			wrong.pop_back();
		}
		else
			flag = false;
	}
	return wrong;
}

double taxsRatio(number num)
{
	vector<int> money = { 250, 500, 1000, 5000, 10000 };
	vector<double> ratio = { 0.012, 0.013, 0.014, 0.015, 0.016 };

	for (int i = 0; i < money.size(); i++) {
		if (num <= money[i])
			return ratio[i];
	}
	return 0.017;
}