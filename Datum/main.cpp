// main.cpp
// Was bewirken die einzelnen Zeilen? Finden Sie Fehler!
#include "Date.h" //mising include 

int main()
{
    Date d1 = Date(2,2,2011);
    // d1.m_day = 15;  //m_day is private cannot write
    
    Date d2 = Date(15,2,2011);
    // bool tf = d2.isequal(d1);//wrong spell  
    bool tf = d2.isEqual(d1); //correct

    return  0;
}