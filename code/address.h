#pragma once
#include <iostream>
#include <string>

using namespace std;
class Address{
    
  private: 
  
  string email;
  string city;
  string mobile_no;
  string street_name;
  
  public:
  
  Address(string e = "No Email", string c = "No City Name", string m = "No Mobile Number", string s = "No Street Name");
  Address(const Address& src);
  void setEmail(string e);
  void setCity(string c);
  void setMobileNo(string n);
  void setStreet(string s);
  string getEmail() const;
  string getCity() const;
  string getMobile() const;
  string getStreet() const;
  void print() const;
  
};