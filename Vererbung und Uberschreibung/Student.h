#ifndef Student_h
#define Student_h

#include "Person.h"

class Student:public Person{
private:
	unsigned int m_uiStudentID;
public:
	Student( std::string sName, std::string sSurname,int aAge,unsigned int uiStudentID);
	~Student();
	unsigned int getStudentID();
	std::string getName() override;
};

#endif
