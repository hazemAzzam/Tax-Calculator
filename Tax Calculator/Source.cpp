#include <iostream>
#include <string>
#include <vector>
#include "number.h"
#include "functions.h"

using namespace std;

int main()
{
	number totalAmount;
	number totalBill;
	number net;
	vector<string> data;
	vector<string> resu;

	while (true) {
		
		cout << "|Total: "; cin >> totalAmount;

		totalBill = totalAmount * 14 / 100 + totalAmount;
		number net = totalBill - (totalAmount - 50) * taxsRatio(totalAmount) * 4 - totalAmount * 1 / 100;

		system("cls");

		data.push_back("Total");
		resu.push_back(convert(totalAmount));

		
		data.push_back(convert(totalAmount) + " * " + "14%"); // totalAmount  * 14%
		resu.push_back(convert(totalAmount * 14 / 100));

		data.push_back(convert(totalAmount) + " * " + "14%" + " + " + convert(totalAmount));// totalAmount  * 14% + totalAmount
		resu.push_back(convert(totalBill));		

		data.push_back(convert(totalAmount - 50) + " * " + convert(taxsRatio(totalAmount))); // (totalAmount - 50) * taxsRatio
		resu.push_back(convert((totalAmount - 50) * taxsRatio(totalAmount)));

		data.push_back(convert(totalAmount) + " * " + "1%"); // totalAmount  * 1%
		resu.push_back(convert(totalAmount * 1 / 100));

		data.push_back(convert(totalAmount - 50) + " * " + convert(taxsRatio(totalAmount)) + " * " + "4"); // (totalAmount - 50) * taxsRatio * 4
		resu.push_back(convert((totalAmount - 50) * taxsRatio(totalAmount) * 4));

		data.push_back("net"); // net
		resu.push_back(convert(net));

		print(data, resu);

		data.clear();
		resu.clear();
	}
}
