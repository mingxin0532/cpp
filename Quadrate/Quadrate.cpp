#include "Quadrate.h"

square::square(double len):length(len){}

square::square(const square &another):length(another.length){}

double square::getLength() const{
	return length;
}
double square::getArea() const{
	return length*length;
}
double square::getPerimeter() const{
	return length*4;
}

square operator +(const square &a, const square &b){
	return square (a.getLength()+b.getLength());
}

square operator -(const square &a, const square &b){
	return square (a.getLength()-b.getLength());
}
std::ostream &operator<<(std::ostream& os,const square &a){
	os<<"Quadrat: Kantenlange="<<a.getLength() << std::endl;
	os<<",Flache="<<a.getArea()<< std::endl;
	os<<",Umfang="<<a.getPerimeter();
	return os;
}
