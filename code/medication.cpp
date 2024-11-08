#include <iostream>
#include "medication.h"
using namespace std;

//Defaulted Constructor
    Medication::Medication(int i, string m, string des, double p, int q, string b, int day, int month, int year)
    {
        setID(i);
        setMedName(m);
        setDes(des);
        setPrice(p);
        setQuantity(q);
        setDate(day, month, year);
        setBarcode(b);
    }

//Copy Constructor
    Medication::Medication(const Medication &src) : expiry_date(src.expiry_date)
    {
        medication_ID = src.medication_ID;
        medication_name = src.medication_name;
        description = src.description;
        price = src.price;
        quantity_in_stock = src.quantity_in_stock;
        barcode = src.barcode;
    }

//Setters
    void Medication::setID(int i)
    {
        while (i<0)
        {
            cout << "ID must be positive, please re-en ID" << endl;
            cin >> i;
        }
        medication_ID = i;
    }
    void Medication::setMedName(string s)
    {
        if (s!="")
        medication_name = s;
        else medication_name = "No Name";
    }
    void Medication::setDes(string s)
    {
        if (s!="")
        description = s;
        else description = "No Description";
    }
    void Medication::setPrice(double x)
    {
        if (x>0)
        price = x;
        else price = 0;
    }
    void Medication::setQuantity(int x)
    {
        if (x>=0)
        quantity_in_stock = x;
        else quantity_in_stock = 0;
    }
    void Medication::setDate(int d, int m, int y)
    {
        expiry_date.setDay(d);
        expiry_date.setMonth(m);
        expiry_date.setYear(y);
    }
    void Medication::setBarcode(string s)
    {
        if (s!="")
        barcode = s;
        else barcode = "No Barcode";
    }

//Getters
    int Medication::getID() const {return medication_ID;}
    string Medication::getMedName() const {return medication_name;}
    string Medication::getDes() const {return description;}
    double Medication::getPrice() const {return price;}
    int Medication::getQuantity() const {return quantity_in_stock;}
    Date Medication::getDate() const {return expiry_date;}
    string Medication::getBarcode() const {return barcode;}


//Print
    void Medication::printInfo() const
    {
        cout << "Medication ID: " << medication_ID << endl;
        cout << "Medication Name: " << medication_name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity in Stock: " << quantity_in_stock << endl;
        cout << "Expiry Date: ";
        expiry_date.print();
        cout << "Barcode: " << barcode << endl;
    }
