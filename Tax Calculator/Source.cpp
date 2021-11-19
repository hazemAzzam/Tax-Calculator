#include <iostream>
#include <string>
#include <vector>

#include "number.h"
using namespace std;

void print(vector<string> data, vector<string> resu);
int maxStringLength(vector<string> data);
void printLine(int width);
string printWhiteSpace(int width);
string convert(number n);

char bounds = '|';
char inside = '~';


int main()
{
	number totalAmount;
	number totalBill;
	number net;
	vector<string> data;
	vector<string> resu;

	while (true) {
		cout << "\nTotal: "; cin >> totalAmount;
		totalBill = totalAmount * 14 / 100 + totalAmount;
		number net = totalBill - (totalAmount - 50) * totalAmount.taxsRatio() * 4 - totalAmount * 1 / 100;
		system("cls");

		data.push_back("Total");
		resu.push_back(convert(totalAmount));

		
		data.push_back(convert(totalAmount) + " * " + "14%"); // totalAmount  * 14%
		resu.push_back(convert(totalAmount * 14 / 100));

		data.push_back(convert(totalAmount) + " * " + "14%" + " + " + convert(totalAmount));// totalAmount  * 14% + totalAmount
		resu.push_back(convert(totalBill));		

		data.push_back(convert(totalAmount - 50) + " * " + convert(totalAmount.taxsRatio())); // (totalAmount - 50) * taxsRatio
		resu.push_back(convert((totalAmount - 50) * totalAmount.taxsRatio()));

		data.push_back(convert(totalAmount) + " * " + "1%"); // totalAmount  * 1%
		resu.push_back(convert(totalAmount * 1 / 100));

		data.push_back(convert(totalAmount - 50) + " * " + convert(totalAmount.taxsRatio()) + " * " + "4"); // (totalAmount - 50) * taxsRatio * 4
		resu.push_back(convert((totalAmount - 50) * totalAmount.taxsRatio() * 4));

		data.push_back("net"); // net
		resu.push_back(convert(net));

		print(data, resu);

		data.clear();
		resu.clear();
	}
}

void print(vector<string> data, vector<string> resu)
{
	int maxLengthFirstRow = maxStringLength(data);
	int maxLengthSecondRow = maxStringLength(resu);
	int width = maxLengthFirstRow + maxLengthSecondRow + 6;

	printLine(width);
	for (int i = 0; i < data.size(); i++) {
		cout << "\n" << bounds;
		cout << data[i] << printWhiteSpace(maxLengthFirstRow - data[i].length()) << " | " << resu[i] << printWhiteSpace(maxLengthSecondRow - resu[i].length());
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