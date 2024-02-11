#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include"clsString.h"
using namespace std;
class clsDate{
private:
  short _day, _month, _year;
public:
  string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  string months[12] = {"Jan", "Feb", "Mar", "Apr","May",
  "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
// ==============constructors==============
  clsDate(){
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  this->_day = now->tm_mday;
  this->_month = now->tm_mon + 1;
  this->_year = now->tm_year + 1900;
  }
  clsDate(string d){
    clsDate date = stringToDate(d);
    this->_day = date._day;
    this->_month = date._month;
    this->_year = date._year;
  }
  clsDate(short day, short month, short year){
    this->_day = day;
    this->_month = month;
    this->_year = year;
  }
  clsDate(short days, short year){
    clsDate d(1,1,year);
    d = addDays(days, d);
    this->_day = --d._day;
    this->_month = d._month;
    this->_year = d._year;
  }
// ==============constructors==============

// ==============Setters and getters==============
void setDay(short day){
  this->_day = day;
}
void setMonth(short month){
  this->_month = month;
}
void setYear(short year){
  this->_year = year;
}
short getDay(){
  return this->_day;
}
short getMonth(){
  return this->_month;
}
short getYear(){
  return this->_year;
}
// ==============Setters and getters==============

// ==============drawing==============
void screenTitle(string title){
  drawing(10);
  cout << endl;
  tabs(2);
  cout << title << endl;
  drawing(10);
  cout << endl;
}
static void drawing(short num, string sh = "----"){
  for (short i = 0; i < num; i++)
  {
    cout << sh;
  }
}
void tabs(short num){
  for (short i = 0; i < num; i++)
  {
    cout << "\t";
  }
}
// ==============drawing==============
  void print(clsDate date){
    cout << date._day << "/" << date._month << "/" << date._year << endl;
  }
  void print(){
    print(*this);
  }
  static bool isLeapYear(short year){
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
  }
  bool isLeapYear(){
    return isLeapYear(this->_year);
  }
  void timeInYear(short year){
  short days;
  isLeapYear(year) ? days = 366 : days = 365;
  int hours = days * 24;
  int minutes = hours * 60;
  int seconds = minutes * 60;
  cout << "In the year: " << year << ":" << endl;
  cout << days << " :Days" << endl; 
  cout << hours << " :Hours" << endl; 
  cout << minutes << " :Minutes" << endl; 
  cout << seconds << " :Seconds" << endl; 
}
short daysInYear(short year){
  return isLeapYear(year) ? 366 : 365;
}
int hoursInYear(short year){
  return daysInYear(year) * 24;
}
int minutesInYear(short year){
  return hoursInYear(year) * 60;
}
int secondsInYear(short year){
  return minutesInYear(year) * 60;
}
int hoursInMonth(int month, int year){
  return daysInMonth(month, year) * 24;
}
int minutesInMonth(int month, int year){
  return hoursInMonth(month, year) * 60;
}
int secondsInMonth(int month, int year){
  return minutesInMonth(month, year) * 60;
}
void timeInMonth(int month, int year){
  cout << "In the Month: " << month << ":" << endl;
  cout << daysInMonth(month, year) << " :Days" << endl; 
  cout << hoursInMonth(month, year) << " :Hours" << endl; 
  cout << minutesInMonth(month, year) << " :Minutes" << endl; 
  cout << secondsInMonth(month, year) << " :Seconds" << endl; 
}
static short daysInMonth(short month, short year){
  return !(month > 0 && month <= 12) ? 0 : month == 2 ? isLeapYear(year) ? 29 : 28 : 
  (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}
static int inWeekOrder(short day, short month, short year){
  // cout << day << "/" << month << "/" << year << endl;
  int a = (14 - month) / 12;
  int y = year - a;
  int m = month + 12 * a - 2;
  int d = (day + y + (y/4) - (y/100) + (y/400) + (31*m/12)) % 7;
  // cout << days[d] << endl;
  return d;
}
int inWeekOrder(){
  return inWeekOrder(this->_day, this->_month, this->_year);
}
static void mCalinder(short month, short dInMonth, short start){
string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
string months[12] = {"Jan", "Feb", "Mar", "Apr","May",
"Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
  short room = 0;
  drawing(10,"+++");
  cout << months[month-1];
  drawing(10,"+++");
  cout << endl;
  for (short i = 0; i < 7; i++)
  {
    cout << setw(5) << days[i];
  }
  cout << endl;
  for (short i = 0; i < start; i++)
  {
    cout << setw(5) << " ";
    room++;
  }
  for (short ii = 1; ii <= dInMonth; ii++)
  {
    if(room > 6){
      cout << endl;
      room = 0;
    }
    cout << setw(5) << ii;
    room++;
  }
  cout << endl;
  drawing(10);
  cout << endl;
}
static void yCalinder(short year){
  drawing(10,"===");
  cout << endl;
  cout << "\tYear: " << year;
  cout << endl;
  drawing(10,"===");
  cout << endl << endl;
  for (short i = 1; i <= 12; i++)
  {
    mCalinder(i, daysInMonth(i, year), inWeekOrder(1,i,year));
    cout << endl;
  }
}
void yCalinder(){
  yCalinder(this->_year);
}
short daysSinceTheBeginningOfYear(clsDate d){
  short sum = 0;
    for (short i = 1; i < d._month; i++)
    {
      sum += daysInMonth(i, d._year);
    }
  return sum += d._day;
}
clsDate currentDateSinceTheBeginningOfYear(short order, short y){
  clsDate date;
  date._day = 1;
  date._month = 1;
  date._year = y;
  short remaining = order;
  short monthDays;
  while(true)
  {
    monthDays = daysInMonth(date._month, y);
    if(remaining > monthDays){
      remaining -= monthDays;
      date._month++;
    }else{
      date._day = remaining;
      break;
    }
  }
  return date; 
}
clsDate addDaysToDate(short add, clsDate d){
  clsDate dy;
  dy._day = 1;
  dy._month = 1;
  dy._year = d._year;
  short newOrder = add + daysSinceTheBeginningOfYear(d);
  short remaining = newOrder;
  short monthDays;
  while(true){
    monthDays = daysInMonth(dy._month, dy._year);
    if(remaining > monthDays){
      remaining -= monthDays;
      dy._month++;
      if(dy._month > 12){
        dy._month = 1;
        dy._year++;
      }
    }else{
      dy._day = remaining;
      break;
    }
  }
  return dy;
}
static bool date1Beforedate2(clsDate d1, clsDate d2){
  return ((d1._year < d2._year) ? true : 
  ((d1._year == d2._year)&&(d1._month < d2._month)) ? true :
  ((d1._year == d2._year) && (d1._month == d2._month) && (d1._day < d2._day)) ? true : false);
}
bool date1Beforedate2(clsDate d2){
  return date1Beforedate2(*this, d2);
}
static bool date1equalsdate2(clsDate d1, clsDate d2){
  return (d1._year == d2._year) ? ((d1._month == d2._month) ? ((d1._day == d2._day) ? true : false) : false) : false;
}
bool datedate1equalsdate2(clsDate d2){
  return date1equalsdate2(*this, d2);
}
static bool isLastDayInMonth(clsDate d){
  return d._day == daysInMonth(d._month, d._year);
}
static bool isLastMonthInYear(short month){
  return month == 12;
}
clsDate increaseDateByOneDay(clsDate d){
  if(isLastDayInMonth(d)){
    if(isLastMonthInYear(d._month)){
      d._day = 1;
      d._month = 1;
      d._year++;
    }else{
      d._day = 1;
      d._month++;
    }
  }else{
    d._day++;
  }
  return d;
}
short dateDiff(clsDate d1, clsDate d2, bool includeEndDay = false){
  short swaped = 1;
  if(!date1Beforedate2(d1, d2)){
    swaped = -1;
    swap(d1, d2);
  }
  short days = 0;
  while(date1Beforedate2(d1, d2)){
    days++;
    d1 = increaseDateByOneDay(d1);
  }
  return days = includeEndDay ? ++days * swaped: days * swaped;
}
clsDate systemDate(){
  clsDate sDate;
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  sDate._day = now->tm_mday;
  sDate._month = now->tm_mon + 1;
  sDate._year = now->tm_year + 1900;
  return sDate;
}
short dateInDays(clsDate d){
  clsDate d1 = systemDate();
  return dateDiff(d, d1);
}
clsDate addDays(short days, clsDate d){
  for (short i = 1; i <= days; i++)
  {
    d = increaseDateByOneDay(d);
  }
  return d;
}
clsDate addOneWeek(clsDate d){
  for (short i = 1; i <= 7; i++)
  {
    d = increaseDateByOneDay(d);
  }
  return d;
}
clsDate addWeeks(short weeks, clsDate d){
  for (short i = 1; i <= weeks; i++)
  {
    d = addOneWeek(d);
  }
  return d;
}
clsDate addOneMonth(clsDate d){
  if(d._month == 12){
    d._month = 1;
    d._year++;
  }else{
    d._month++;
  }
  short monthDays = daysInMonth(d._month, d._year);
  if(d._day > monthDays){
    d._day = monthDays;
  }
  return d;
}
clsDate addMonths(short months, clsDate d){
  for (short i = 1; i <= months; i++)
  {
    d = addOneMonth(d);
  }
  return d;
}
clsDate addOneYear(clsDate d){
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  d._year++;
  return d;
}
clsDate addYears(short years, clsDate d){
  d._year += years;
  return d;
}
clsDate addOneDecade(clsDate d){
  d._year += 10;
  return d;
}
clsDate addDecades(short decades, clsDate d){
  d._year += 10*decades;
  return d;
}
clsDate addOneCentury(clsDate d){
  d._year += 10;
  return d;
}
clsDate addCenturies(short centuries, clsDate d){
  d._year += 100*centuries;
  return d;
}
clsDate addOneMillennium(clsDate d){
  d._year += 1000;
  return d;
}
clsDate decreaseDateByOneDay(clsDate d){
  if(d._day == 1 && d._month == 1){
    d._month = 12;
    d._day = 31;
    d._year--;
  }else if(d._day == 1 && d._month != 1){
    d._month--;
    d._day = daysInMonth(d._month, d._year);
  }else{
    d._day--;
  }
  return d;
}
clsDate removeDays(short days, clsDate d){
  for (short i = 1; i <= days; i++)
  {
    d = decreaseDateByOneDay(d);
  }
  return d;
}
clsDate removeOneWeek(clsDate d){
  for (short i = 1; i <= 7; i++)
  {
    d = decreaseDateByOneDay(d);
  }
  return d;
}
clsDate removeWeeks(short weeks, clsDate d){
  for (short i = 1; i <= weeks; i++)
  {
    d = removeOneWeek(d);
  }
  return d;
}
clsDate removeOneMonth(clsDate d){
  if(d._month == 1){
    d._month = 12;
    d._year--;
  }else{
    d._month--;
  }
  short monthDays = daysInMonth(d._month, d._year);
  if(d._day > monthDays){
    d._day = monthDays;
  }
  return d;
}
clsDate removeMonths(short months, clsDate d){
  for (short i = 1; i <= months; i++)
  {
    d = removeOneMonth(d);
  }
  return d;
}
clsDate removeOneYear(clsDate d){
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  d._year--;
  return d;
}
clsDate removeYears(short years, clsDate d){
  d._year -= years;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
clsDate removeOneDecade(clsDate d){
  d._year -= 10;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
clsDate removeDecades(short decades, clsDate d){
  d._year -= 10*decades;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
clsDate removeOneCentury(clsDate d){
  d._year -= 100;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
clsDate removeCenturies(short centuries, clsDate d){
  d._year -= 100*centuries;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
clsDate removeOneMillennium(clsDate d){
  d._year -= 1000;
  if(d._month == 2 && d._day == 29){
    !isLeapYear(d._year) ? d._day = 28 : d._day;
  }
  return d;
}
bool isLastDayInYear(clsDate d){
  return (d._day == 31 && d._month == 12);
}
int inWeekOrder(clsDate d){
  return inWeekOrder(d._day, d._month, d._year);
}
bool isEndOfWeek(clsDate d){
  return days[inWeekOrder(d)] == "Sat";
}
bool isWeekEnd(clsDate d){
  return (days[inWeekOrder(d)] == "Fri" || days[inWeekOrder(d)] == "Sat");
}
bool isBusinessDay(clsDate d){
  return !isWeekEnd(d);
}
short daysToEndOfWeek(clsDate d){
  return 6 - inWeekOrder(d);
}
short daysToEndOfMonth(clsDate d){
  clsDate end;
  end._day = daysInMonth(d._month, d._year);
  end._month = d._month;
  end._year = d._year;
  return dateDiff(d, end, 1);
}
short daysToEndOfYear(clsDate d){
  clsDate end;
  end._day = 31;
  end._month = 12;
  end._year = d._year;
  return dateDiff(d, end, 1);
}
short vacationDays(clsDate from, clsDate to){
  short vac = 0;
  while(date1Beforedate2(from, to)){
    if(isBusinessDay(from)){
      vac++;
    }
    from = increaseDateByOneDay(from);
  }
  return vac;
}
clsDate vacationEndDate(short vac, clsDate date){
  while(vac){
    if(isWeekEnd(date)){
      vac++;
    }
    date = increaseDateByOneDay(date);
    vac--;
  }
  return date;
}
static bool date1AfterDate2(clsDate d1, clsDate d2){
  return !date1Beforedate2(d1,d2) && !date1equalsdate2(d1,d2);
}
bool date1AfterDate2(clsDate d2){
  return !date1Beforedate2(*this,d2) && !date1equalsdate2(*this,d2);
}
enum enResult {eBefore = -1, eAfter = 1, eEqual = 0};
short compareDates(clsDate d1, clsDate d2){
  if(date1Beforedate2(d1,d2)){
    return enResult::eBefore;
  }else if(date1AfterDate2(d1,d2)){
    return enResult::eAfter;
  }else{
    return enResult::eEqual;
  }
}
static bool isValidDate(clsDate d){
  if(d._year > 100){
    if(d._month >= 1 && d._month <= 12){
      if(d._month == 2){
        if(isLeapYear(d._year)){
          d._day <= 29 ? true : false;
        }
      }
      if(d._day > 0 && d._day <= daysInMonth(d._month, d._year)){
        return true;
      }
    }
  }
  return false;
}
clsDate stringToDate(string d){
  vector<string> data = clsString::split(d, "/");
  clsDate date;
  date._day = stoi(data[0]);
  date._month = stoi(data[1]);
  date._year = stoi(data[2]);
  return date;
}
string formatDate(string d, string format = "dd/mm/yyyy"){
  clsDate fDate = stringToDate(d);
  string formatted = "";
  formatted = clsString::nreplace(format, "dd", to_string(fDate._day));
  formatted = clsString::nreplace(formatted, "mm", to_string(fDate._month));
  formatted = clsString::nreplace(formatted, "yyyy", to_string(fDate._year));
  return formatted;
}
};