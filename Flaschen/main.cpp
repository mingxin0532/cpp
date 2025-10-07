#include "Flaschen.h"
#include <iostream>
int main(){

	flaschen flaschen_01;
	flaschen flaschen_02;

	flaschen_01.setdVolumen(10.0);
	flaschen_01.setsMaterial("Water");

	std::cout<<"Flasche 01"<<std::endl;

	flaschen_01.printFlasche(flaschen_01);

	std::cout<<"Flasche 02"<<std::endl;
	flaschen_02.adoptFlasche(flaschen_01);
	flaschen_02.printFlasche(flaschen_02);


}
