#include <iostream>
#include "prescription.h"
using namespace std;

//Parameterized Constructor
    Prescription::Prescription(int fda, int d, int m, int y, int i, string n, string des, double p, int q, int day, int month, int year, string b): Medication(i, n, des, p, q, b, day, month, year), approval_date(d, m, y)
    {
        setFDA(fda);
    }

//Setters
    void Prescription::setFDA(int n)
    {
        if (n >= 0)
        FDA_number = n;
        else FDA_number = 0;
    }
    void Prescription::setAppDate(int d, int m, int y)
    {
        approval_date.setDay(d);
        approval_date.setMonth(m);
        approval_date.setYear(y);
    }

//Getters
    int Prescription::getFDA() const {return FDA_number;}
    Date Prescription::getAppDate() const {return approval_date;}

//Print
    void Prescription::printInfo() const 
    {
        Medication::printInfo();
        cout << "FDA number: " << FDA_number << endl;
        cout << "Approval Date: ";
        approval_date.print();
    }