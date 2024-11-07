#include <iostream>
#include <ctime>
#include "offtheshelf.h"
using namespace std;

OffTheShelf::OffTheShelf(bool b, int d, int m, int y, int i, string n, string des, double p, int q, string bc, int day1, int month1, int year1) : Medication(i, n, des, p, q, bc, day1, month1, year1)
{
	setBOGOF(b);
	setOfferEnds(d, m, y);
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int day = ltm->tm_mday, month = 1 + ltm->tm_mon, year = 1900 + ltm->tm_year;
	today.setDay(day);
	today.setMonth(month);
	today.setYear(year);
}

void OffTheShelf::setBOGOF(bool s)
{
	BOGOF = s;
	if (BOGOF)
	{
		if ((today.getMonth()+3)<=12)
		setOfferEnds(today.getDay(), (today.getMonth()+3), today.getYear());
		else
		setOfferEnds(today.getDay(), ((today.getMonth()+3)-12), (today.getYear()+1));
	}
	else
	{
		setOfferEnds(today.getDay(), today.getMonth(), (today.getYear()+2));
	}
}

void OffTheShelf::setOfferEnds(int d, int m, int y)
{
	offer_ends.setDay(d);
	offer_ends.setMonth(m);
	offer_ends.setYear(y);
}

bool OffTheShelf::getBOGOF() const
{
	return BOGOF;
}

Date OffTheShelf::getOfferEnds() const
{
	return offer_ends;
}

Date OffTheShelf::getToday() const
{
    return Date();
}

void OffTheShelf::printInfo() const
{
	Medication::printInfo();
	cout << "Buy 1 get 1 free: " << BOGOF << endl;
	cout << "Offer ends: ";
	offer_ends.print();
}