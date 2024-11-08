#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int day, month, year;
public:
	Date(int d = 1, int m = 1, int y = 2000);
	Date(const Date& src);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void print()const;
};

