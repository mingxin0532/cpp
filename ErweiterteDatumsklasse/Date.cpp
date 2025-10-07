#include "Date.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

bool Date::isValid(int d, int m, int y) const {
    if (y < 1970 || y > 2030) return false;
    if (m < 1 || m > 12) return false;

    int maxDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    
    if (d < 1 || d > maxDays[m]) return false;

    return true;
}

Date::Date(int day, int month, int year) 
{
    if (!isValid(day, month, year)) {
        m_day = 1; m_month = 1; m_year = 1970;
        std::cerr << "Warnung: Ungültiges Datum korrigiert auf 01.01.1970." << std::endl;
    } else {
        m_day = day; 
        m_month = month; 
        m_year = year;
    }
}

Date::Date() {
    srand(static_cast<unsigned int>(time(NULL))); 

    int randDay, randMonth, randYear;
    
    do {
        randYear = 1970 + (rand() % 61); 
        
        randMonth = 1 + (rand() % 12);
        
        randDay = 1 + (rand() % 31);
        
    } while (!isValid(randDay, randMonth, randYear)); 
    
    m_day = randDay;
    m_month = randMonth;
    m_year = randYear;
}

int Date::getDay() const { return m_day; }
int Date::getMonth() const { return m_month; }
int Date::getYear() const { return m_year; }

int Date::compare(const Date& dd) const {
    if (m_year < dd.m_year) return 1; 
    if (m_year > dd.m_year) return -1; 

    if (m_month < dd.m_month) return 1;
    if (m_month > dd.m_month) return -1;

    if (m_day < dd.m_day) return 1;
    if (m_day > dd.m_day) return -1;

    return 0;
}

bool Date::isEqual(const Date& dd) const {
    return compare(dd) == 0;
}

std::string Date::toString() const {
    return std::to_string(m_day) + "." + std::to_string(m_month) + "." + std::to_string(m_year);
}