#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "number.h"

using namespace std;

void print(vector<string> data, vector<string> resu);
int maxStringLength(vector<string> data);
void printLine(int width);
string printWhiteSpace(int width);
string convert(number n); //convert to string, better with double than to_string(), such that it removes unwanted zeros
double taxsRatio(number n);