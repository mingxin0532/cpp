#include "Person.h"

Person::Person(std::string sName, std::string sSurname,int aAge):m_sName(sName),m_sSurname(sSurname),m_iAge(aAge){}
Person::~Person(){}

std::string Person::getName(){
	return m_sName;
}
std::string Person::getSurname(){
	return m_sSurname;
}
int Person::getAge(){
	return m_iAge;
}
bool Person::setAge(int Age){
	if(Age>0){
		m_iAge=Age;
		return true;
	}
	return false;
}



