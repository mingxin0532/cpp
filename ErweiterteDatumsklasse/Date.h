#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int m_day, m_month, m_year;

    bool isValid(int d, int m, int y) const; 

public:
    Date(); 
    
    Date(int day, int month, int year);
    
    int getDay() const; 
    int getMonth() const;
    int getYear() const;

    int compare(const Date& dd) const;
    
    bool isEqual(const Date& dd) const; 
    
    std::string toString() const;
};

#endif // DATE_H