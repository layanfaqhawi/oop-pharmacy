#include <iostream>
#include "Date.h"
using namespace std;

//Defaulted Constructor
    Date::Date(int d, int m, int y)
    {
        setDay(d);
        setMonth(m);
        setYear(y);
    }

//Copy Constructor
    Date::Date(const Date& src)
    {
        day = src.day;
        month = src.month;
        year = src.year;
    }

//Setters
    void Date::setDay(int d)
    {
        if (d >= 1 && d <= 31)
        day = d;
        else day = 1;
        
    }
    void Date::setMonth(int m)
    {
        if (m >= 1 && m <= 12)
        month = m;
        else month = 1;
    }
    void Date::setYear(int y)
    {
        if (y >= 2000)
        year = y;
        else year = 2000;
    }

//Getters
    int Date::getDay() const {return day;}
    int Date::getMonth() const {return month;}
    int Date::getYear() const {return year;}

//Print
    void Date::print() const
    {
        cout << day << "/" << month << "/" << year << endl;
    }
