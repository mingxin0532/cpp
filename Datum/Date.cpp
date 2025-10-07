// Date.cpp
#include "Date.h"

Date::Date(int day, int month, int year)
{
    m_day = day; m_month = month; m_year = year;
}

int Date::getDay() { return m_day; }
int Date::getMonth() { return m_month; }
int Date::getYear() { return m_year; }
bool Date::isEqual(Date dd)
{
    if(m_day==dd.m_day && m_month==dd.m_month && m_year==dd.m_year)
        return true;
    return false;
}