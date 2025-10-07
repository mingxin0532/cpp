#include "Student.h"
#include "Person.h"
#include <iostream>

int main(){
	Person p("Anty","VSIA",18);
	Student s("Max","Verstappen",27,33333);

	std::cout<<p.getName()<<std::endl;
	std::cout<<s.getName()<<std::endl;

	Person pReference = s;
	std::cout<<pReference.getName()<<std::endl;
	return 0;

}
