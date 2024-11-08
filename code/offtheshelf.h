#pragma once
#include <iostream>
#include "medication.h"
#include "date.h"
using namespace std;

class OffTheShelf : public Medication
{
    private:
    bool BOGOF;
    Date offer_ends;
    Date today;

    public:
    OffTheShelf(bool b = false, int d = 1, int m = 1, int y = 2000, int i = 0, string n = "No Name", string des = "No Description", double p = 0.0, int q = 0, string bc = "No Barcode", int day = 1, int month = 1, int year = 2000);
    void setBOGOF(bool s);
    void setOfferEnds(int, int, int);
    bool getBOGOF() const;
    Date getOfferEnds() const;
    Date getToday() const;
    void printInfo() const;
};