//============================================================================
// Name        : Referenzen.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

void swap(int& a, int& b){
	int c;
	c = a;
	a = b;
	b = c;
}

int main() {
	int a, b;

	std::cout << "please give number a" << std::endl;
	std::cin>>a;
	std::cout << "please give number b" << std::endl;
	std::cin>>b;

	swap(a,b);

	std::cout << "value after swap" << std::endl;
	std::cout << "a = " <<a<< std::endl;
	std::cout << "b = " <<b<< std::endl;

	return 0;
}
