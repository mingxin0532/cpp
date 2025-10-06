//============================================================================
// Name        : QuadratishceFunktionen.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

void Quadraticsolver(double a, double b, double c, double* roota, double* rootb){
	double discriminant = b*b -4*a*c;
	if(discriminant>0){
		*roota = (-b+sqrt(discriminant))/(2*a);
		*rootb = (-b-sqrt(discriminant))/(2*a);
		std::cout<<"x1 = "<<*roota<<std::endl;
		std::cout<<"x2 = "<<*rootb<<std::endl;
	}

	else if(discriminant==0){
		*roota = -b/(2*a);
		*rootb = -b/(2*a);
		std::cout<<"x1 = "<<*roota<<std::endl;
		std::cout<<"x2 = "<<*rootb<<std::endl;
	}

	else{
		std::cout<<"no root"<<std::endl;
	}
}

int main() {
	double a, b, c, roota, rootb;
	std::cout<<"please give a"<<std::endl;
	std::cin>>a;
	std::cout<<"please give b"<<std::endl;
	std::cin>>b;
	std::cout<<"please give c"<<std::endl;
	std::cin>>c;

	Quadraticsolver(a,b,c, &roota, &rootb);
	return 0;
}
