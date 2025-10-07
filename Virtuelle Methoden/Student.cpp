#include "Student.h"

Student::Student( std::string sName, std::string sSurname,int aAge,unsigned int uiStudentID)
	:Person(sName,sSurname,aAge),m_uiStudentID(uiStudentID){}
Student::~Student(){}

unsigned int Student::getStudentID(){
	return m_uiStudentID;

}
std::string Student::getName(){
	return "Student: "+ Person::getName();
}

