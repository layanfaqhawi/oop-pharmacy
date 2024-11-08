#include <iostream>
#include "customer.h"
using namespace std;

//Defaulted Constructor
    Customer::Customer(int i, string n, string e, string c, string m, string s)
    {
        setID(i);
        setName(n);
        setAddress(e, c, m, s);
    }

//Copy Constructor
    Customer::Customer(const Customer &src) : customer_address(src.customer_address)
    {
        customer_ID = src.customer_ID;
        customer_name = src.customer_name;
    }

//Setters
    void Customer::setID(int i)
    {
        while (i<0)
        {
            cout << "ID must be positive, please re-enter ID" << endl;
            cin >> i;
        }
        customer_ID = i;
    }
    void Customer::setName(string s) 
    {
        if (s!="")
        customer_name = s;
        else customer_name = "No Name";
    }
    void Customer::setAddress(string e, string c, string m, string s) 
    {
        customer_address.setEmail(e);
        customer_address.setCity(c);
        customer_address.setMobileNo(m);
        customer_address.setStreet(s);
    }

//Getters
    string Customer::getName() const {return customer_name;}
    int Customer::getID() const {return customer_ID;}
    Address Customer::getAddress() const {return customer_address;}

//Print
    void Customer::printInfo() const 
    {
        cout << "Customer Name: " << customer_name << endl;
        cout << "Customer ID: " << customer_ID << endl;
        customer_address.print();
    }