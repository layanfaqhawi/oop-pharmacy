#pragma once
#include <iostream>
#include "address.h"
using namespace std;

class Customer
{
    private:
    int customer_ID;
    string customer_name;
    Address customer_address;

    public:
    Customer(int i = 0, string n = "No Name", string e = "No Email", string c = "No City", string m = "No Mobile Number", string s = "No Street Name");
    Customer(const Customer &src);

    void setID(int);
    void setName(string);
    void setAddress(string, string, string, string);

    string getName() const;
    int getID() const;
    Address getAddress() const;

    void printInfo() const;
};