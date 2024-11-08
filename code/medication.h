#pragma once
#include <iostream>
#include "date.h"
using namespace std;

class Medication
{
    private:
    int medication_ID, quantity_in_stock;
    string medication_name, description, barcode;
    Date expiry_date;
    double price;

    public:
    Medication(int i = 0, string m = "No Name", string des = "No Description", double p = 0.0, int q = 0, string b = "No Barcode", int day = 1, int month = 1, int year = 2000);
    Medication(const Medication &src);
    void setID(int);
    void setMedName(string);
    void setDes(string);
    void setPrice(double);
    void setQuantity(int);
    void setDate(int, int, int);
    void setBarcode(string);

    int getID() const;
    string getMedName() const;
    string getDes() const;
    double getPrice() const;
    int getQuantity() const;
    Date getDate() const;
    string getBarcode() const;

    void resetMed();

    void printInfo() const;
};