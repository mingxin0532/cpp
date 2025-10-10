#include "Quadrate.h"

int main(){
	square sq1(10.0);
	square sq2(4.0);
	std::cout<< "sq1:" << sq1 << std::endl;
	std::cout<< "sq2:" << sq2 << std::endl;

	square sq3(sq1);
	std::cout<< "sq3:" << sq3 << std::endl;
	square sq4 = sq1 +sq2;
	std::cout<< "sq4:" << sq4 << std::endl;
	square sq5 = sq1 -sq2;
	std::cout<< "sq5:" << sq5 << std::endl;
	std::cout<< "length:"<<sq1.getLength()<<std::endl;
	std::cout<< "Area:"<<sq1.getArea()<<std::endl;
	std::cout<< "Perimeter:"<<sq1.getPerimeter()<<std::endl;

}
