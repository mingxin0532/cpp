// Date.h
#ifndef DATE_H
#define DATE_H

class Date
{
    private:
    int m_day, m_month, m_year;
    // Date(int day, int month, int year);

    public:
    Date(int day, int month, int year);
    bool isEqual(Date dd);
    int getDay();
    int getMonth();
    int getYear();
};

#endif