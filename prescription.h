#pragma once
#include <iostream>
#include "medication.h"
#include "date.h"
using namespace std;

class Prescription: public Medication
{
    private:
    int FDA_number;
    Date approval_date;
    public:
    Prescription(int fda = 0, int d = 1, int m = 1, int y = 2000, int i = 0, string n = "No Name", string des = "No Description", double p = 0, int q = 0, int day = 1, int month = 1, int year = 2000, string b = "No Barcode");
    void setFDA(int);
    void setAppDate(int, int, int);
    int getFDA() const;
    Date getAppDate() const;
    void printInfo() const;
};
