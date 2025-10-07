#include "Student.h"
#include "Person.h"
#include <iostream>
#include <vector>

int main(){

	//a
	std::vector<Person*> people;

	people.push_back(new Student("Max","mmmmm",22,12345));
	people.push_back(new Student("Andy","aaaaaaaaa",21,54321));
	// b
	std::cout<< "b:"<<std::endl;
	for(Person* pointP :people){
		std::cout<< pointP ->Person::getName()<<std::endl;
	}
	//c
	std::cout<< "c:"<<std::endl;
	for(Person* pointP :people){
		std::cout<< pointP ->getName()<<std::endl;
	}
	std::cout<< "clean memory"<<std::endl;
	for(Person* pointP :people){
		delete pointP;
	}


}
