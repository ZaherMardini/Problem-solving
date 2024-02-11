#pragma once
#include<iostream>
#include"clsInputValidation.h"
using namespace std;
class clsPerson{
  private:
  string _firstName;
  string _lastName;
  string _email;
  string _phone;
  public:
  clsPerson(string f, string l, string e, string p){
    this->_firstName = f;
    this->_lastName = l;
    this->_email = e;
    this->_phone = p;
  }
  //==========setters and getters==========
  void setFirst(string f){
    this->_firstName = f;
  }
  void setLast(string l){
    this->_lastName = l;
  }
  string getFirst(){
    return this->_firstName;
  }
  string getLast(){
    return this->_lastName;
  }
  void setEmail(string e){
    this->_email = e;
  }
  void setPhone(string p){
    this->_phone = p;
  }
  string getEmail(){
    return this->_email;
  }
  string getPhone(){
    return this->_phone;
  }
  //==========setters and getters==========
  string fullName(){
    return (this->_firstName + " " + this->_lastName);
  }
void print(){
  cout << "\nInfo:";
  cout << "\n___________________" << endl;
  cout << "\nFirstName: " << _firstName;
  cout << "\nLastName : " << _lastName;
  cout << "\nFull Name: " << fullName();
  cout << "\nEmail    : " << _email;
  cout << "\nPhone    : " << _phone;
  cout << "\n___________________\n";
}
};