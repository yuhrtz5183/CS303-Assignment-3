#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool balanced(const string& expression);
int getSymbol(char c);
string InToPost(const string& expression);
