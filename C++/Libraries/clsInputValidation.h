#pragma once
#include<iostream>
#include<ctime>
#include"clsString.h"
#include"clsDate.h"
#include"clsUtility.h"
using namespace std;

class clsInputValidation{
public:
static bool isValidDate(clsDate d){
  return clsDate::isValidDate(d);
}
static bool isNumberBetween(int number, int small, int big){
  if(small > big){
    clsUtility::swap(small, big);
  }
  return ((number >= small) && (number <= big));
}
static bool isNumberBetween(float number, float small, float big){
  if(small > big){
    clsUtility::swap(small, big);
  }
  return ((number >= small) && (number <= big));
}
static bool isNumberBetween(double number, double small, double big){
  if(small > big){
    clsUtility::swap(small, big);
  }
  return ((number >= small) && (number <= big));
}
static bool isDateBetween(clsDate date, clsDate first, clsDate second){
  if(first.date1AfterDate2(second)){
    clsUtility::swap(first, second);
  }
  return ((date.date1AfterDate2(first)) && (date.date1Beforedate2(second)));
}
static bool isOdd(int num){
  return num % 2 != 0;
}
static int readIntNumber(string msg="Enter a number: ")
{
  cout << msg;
  int number;
  while (!(cin >> number)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Number, Enter again\n" ;
  }
  return number;
}
static double readDblNumber(string msg="Enter a number: ")
{
  cout << msg;
  double number;
  while (!(cin >> number)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Number, Enter again\n" ;
  }
  return number;
}
static char readChar(string msg = "Enter a letter: "){
  return clsUtility::readChar(msg);
}
static string readString(string msg = "Enter some text: "){
  return clsUtility::readString(msg);
}
static int readIntNumberBetween(int n1, int n2){
  cout << "Enter a number between " << n1 << " and " << n2 << " : ";
  int number = readIntNumber("");
  while(!isNumberBetween(number, n1, n2)){
    cout << "Number is not between " << n1 << " and " << n2 << " try again\n";
    number = readIntNumberBetween(n1, n2);
  }
  return number;
}
static short readShortNumberBetween(short n1, short n2){
  cout << "Enter a number between " << n1 << " and " << n2 << " : ";
  short number = readIntNumber("");
  while(!isNumberBetween(number, n1, n2)){
    cout << "Number is not between " << n1 << " and " << n2 << " try again\n";
    number = readIntNumberBetween(n1, n2);
  }
  return number;
}
static double readDblNumberBetween(double n1, double n2){
  cout << "Enter a number between " << n1 << " and " << n2 << " : ";
  double number = readDblNumber("");
  while(!isNumberBetween(number, n1, n2)){
    cout << "Number is not between " << n1 << " and " << n2 << " try again\n";
    number = readDblNumberBetween(n1, n2);
  }
  return number;
}
};