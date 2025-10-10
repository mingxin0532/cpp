#ifndef Quadrate_h
#define Quadrate_h

#include <iostream>

class square{

private:
	const double length;
public:
	//a
	square(double len);
	//b
	double getLength() const;
	double getArea() const;
	double getPerimeter() const;
	//c
	square(const square &another);

};

//d
square operator +(const square &a, const square &b);
square operator -(const square &a, const square &b);
//e
std::ostream &operator<<(std::ostream& os,const square &a);


#endif
