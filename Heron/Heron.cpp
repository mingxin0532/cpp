/*
 * Heron.cpp
 *
 *  Created on: 06.10.2025
 *      Author: pi
 */

#include <iostream>

double heron_ite(double a, double b){
	double x = b;
	for(int i = 0; i< 10 ; i++){
		x = 0.5 *(x+a/x);
	}
	return x;
}

int main(){
	double a;
	std::cout<<"please give a number:"<<std::endl;
	std::cin>>a;

	double b =a/2.0;

	double c = heron_ite(a,b);

	std::cout<<"the approximate square root of "<<a<<" is: "<<c<<std::endl;

	return 0;
}

