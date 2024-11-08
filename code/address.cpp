#include <iostream>
#include <string>
#include "Address.h"
using namespace std;

//Defaulted Constuctor
    Address::Address(string e, string c, string m, string s)
    {
        setEmail(e);
        setCity(c);
        setMobileNo(m);
        setStreet(s);
    }

//Copy Constructor
    Address::Address(const Address &src)
    {
        email = src.email;
        city = src.city;
        mobile_no = src.mobile_no;
        street_name = src.street_name;
    }

//Setters
    void Address::setEmail(string e)
    {
        if(e!="")
        email = e;
        else e = "No Email";
    }
    void Address::setCity(string c)
    {
        if(c!="")
        city = c;
        else city = "No City Name";
    }
    void Address::setMobileNo(string n)
    {
        if(n!="") 
        mobile_no = n;
        else mobile_no = "No Mobile Number";
    }
    void Address::setStreet(string s)
    {
        if(s!="")
        street_name = s;
        else street_name = "No Street Name";
    }

//Getters
    string Address::getEmail() const {return email;}
    string Address::getCity() const {return city;}
    string Address::getMobile() const {return mobile_no;}
    string  Address::getStreet() const {return street_name;}
    
//Print
    void Address::print() const
    {
        cout << "Email: " << email<< endl;
        cout << "City: " << city<< endl;
        cout << "Mobile Number: " <<mobile_no << endl;
        cout << "Street Name: "<< street_name << endl;
    }

  
