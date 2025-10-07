#include "Flaschen.h"
#include <string>
#include <iostream>


flaschen::flaschen() {
}
flaschen::~flaschen() {
}

double flaschen::getdVolumen() {
	return dVolumen;
}
std::string flaschen::getsMaterial() {
	return sMaterial;
}
bool flaschen::setdVolumen(double volumen) {
	dVolumen = volumen;
}
bool flaschen::setsMaterial(std::string Material) {
	sMaterial = Material;
}
void flaschen::printFlasche(flaschen thisflasche){
	std::cout<< "Volumen:"<< thisflasche.getdVolumen()<<"Liert"<<std::endl;
	std::cout<<"Material:"<<thisflasche.getsMaterial()<<std::endl;
}
void flaschen::adoptFlasche(flaschen& anotherFlasche){
	dVolumen = anotherFlasche.getdVolumen();
	sMaterial = anotherFlasche.getsMaterial();
}
