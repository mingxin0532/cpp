//============================================================================
// Name        : Taschenrechner.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	float num_1, num_2, output;
	char oper;

	std::cout << "pls type the first number:" << std::endl;
	if (!(std::cin >> num_1)) {
		std::cout << "unvalid number, pls type new number:" << std::endl;
	} else {
		std::cout << "confirm first number:" << num_1 << std::endl;

	}

	std::cout << "pls type the operator:" << std::endl;
	std::cin >> oper;
	if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {

	} else {
		std::cout << "unvalid operator, pls type new one:" << std::endl;
	}

	std::cout << "pls type the second number:" << std::endl;
	if (!(std::cin >> num_2) || (num_2 == 0 && oper == '/')) {
		std::cout << "unvalid number, pls type new number:" << std::endl;
	} else {
		std::cout << "confirm second number:" << num_2 << std::endl;
	}

	switch (oper) {
	case '*':
		output = num_1 * num_2;
		break;
	case '/':
		output = num_1 / num_2;
		break;
	case '-':
		output = num_1 - num_2;
		break;
	case '+':
		output = num_1 + num_2;
		break;
	}
	std::cout << "the result is::" << output << std::endl;
	return 0;

}
