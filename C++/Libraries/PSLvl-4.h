#pragma once
#include<iostream>
#include"BankP.h"
#include<cmath>
#include<iomanip>
#include"PSLvl-3.h"
using namespace std;
//================ Declarations ================
string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
string months[12] = {"Jan", "Feb", "Mar", "Apr","May",
"Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
struct stDate{
  short day;
  short month;
  short year;
};
//================ Declarations ================
//================ Begin ================
// Problem #1
string numberToText(int num){
  if(num == 0){
    return "";
  }
  if (num > 0 && num < 20)
  {
    string text[] = {"", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
    "Eighteen", "Nineteen"};
    return text[num] + " ";
  }
  if(num >= 20 && num <= 99){
    string text[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"};
    return text[num/10] + " " + numberToText(num%10) + " ";
  }
  if(num >= 100 && num < 1000){
    return numberToText(num/100) + "Hundred " + numberToText(num%100);
  }
  if(num >= 1000 && num < 1000000){
    return numberToText(num/1000) + "Thousand " + numberToText(num%1000);
  }
  if(num >= 1000000 && num < 1000000000){
    return numberToText(num/1000000) + "Million " + numberToText(num%1000000);
  }
  if(num >= 1000000000 && num < 1000000000000){
    return numberToText(num/1000000000) + "Billion " + numberToText(num%1000000000);
  }
  return " ";
}
// Problem #1

// Problem #2
// bool isLeapYear0(short year){
//   if(year % 400 == 0){
//     return true;
//   }else if(year % 4 == 0 && year % 100 != 0){
//     return true;
//   }
// return false;
// }
// Problem #2

// Problem #3
bool isLeapYear(short year){
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
// Problem #3

// Problem #4
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
// Problem #4

// Problem #5
// int daysInMonth(int month, int year){
//   if(!(month > 0 && month <= 13)){
//     return 0;
//   }
//   if(month == 2){
//     return isLeapYear(year) ? 29 : 28;
//   }else{
//     int m[7] = {1,3,5,7,8,10,12};
//     for (short i = 0; i < 7; i++)
//     {
//       if(month == m[i]){
//         return 31;
//       }
//     }
//   }
//   return 30;
// }
int daysInMonth(int month, int year);
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
// Problem #5

// Problem #6
int daysInMonth(int month, int year){
  return !(month > 0 && month <= 12) ? 0 : month == 2 ? isLeapYear(year) ? 29 : 28 : 
  (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}
// Problem #6

// Problem #7
int inWeekOrder(short day, short month, short year){
  // cout << day << "/" << month << "/" << year << endl;
  int a = (14 - month) / 12;
  int y = year - a;
  int m = month + 12 * a - 2;
  int d = (day + y + (y/4) - (y/100) + (y/400) + (31*m/12)) % 7;
  // cout << days[d] << endl;
  return d;
}
// Problem #7

// Problem #8
void mCalinder(int month, int dInMonth, int start){
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
// Problem #8

// Problem #9
void yCalinder(short year){
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
// Problem #9

// Problem #10
short daysSinceTheBeginningOfYear(stDate d){
  short sum = 0;
    for (short i = 1; i < d.month; i++)
    {
      sum += daysInMonth(i, d.year);
    }
  return sum += d.day;
}
// Problem #10

// Problem #11
stDate date;
stDate currentDateSinceTheBeginningOfYear(short order, short y){
  date.day = 1;
  date.month = 1;
  date.year = y;
  short remaining = order;
  short monthDays;
  while(true)
  {
    monthDays = daysInMonth(date.month, y);
    if(remaining > monthDays){
      remaining -= monthDays;
      date.month++;
    }else{
      date.day = remaining;
      break;
    }
  }
  return date; 
}
// Problem #11

// Problem #12
stDate addDaysToDate(short add, stDate d){
  stDate dy;
  dy.day = 1;
  dy.month = 1;
  dy.year = d.year;
  short newOrder = add + daysSinceTheBeginningOfYear(d);
  short remaining = newOrder;
  short monthDays;
  while(true){
    monthDays = daysInMonth(dy.month, dy.year);
    if(remaining > monthDays){
      remaining -= monthDays;
      dy.month++;
      if(dy.month > 12){
        dy.month = 1;
        dy.year++;
      }
    }else{
      dy.day = remaining;
      break;
    }
  }
  return dy;
}
// Problem #12

// Problem #13
bool date1Beforedate2(stDate d1, stDate d2){
  // if(d1.year < d2.year){
  //   return true;
  // }else if((d1.year == d2.year)&&(d1.month < d2.month)){
  //   return true;
  // }else if((d1.year == d2.year) && (d1.month == d2.month)){
  //   if(d1.day < d2.day){
  //     return true;
  //   }
  // }
  return ((d1.year < d2.year) ? true : 
  ((d1.year == d2.year)&&(d1.month < d2.month)) ? true :
  ((d1.year == d2.year) && (d1.month == d2.month) && (d1.day < d2.day)) ? true : false);
}
// Problem #13

// Problem #14
bool date1equalsdate2(stDate d1, stDate d2){
  return (d1.year == d2.year) ? ((d1.month == d2.month) ? ((d1.day == d2.day) ? true : false) : false) : false;
}
// Problem #14

// Problem #15
bool isLastDayInMonth(stDate d){
  return d.day == daysInMonth(d.month, d.year);
}
bool isLastMonthInYear(short month){
  return month == 12;
}
// Problem #15

// Problem #16
stDate increaseDateByOneDay(stDate d){
  if(isLastDayInMonth(d)){
    if(isLastMonthInYear(d.month)){
      d.day = 1;
      d.month = 1;
      d.year++;
    }else{
      d.day = 1;
      d.month++;
    }
  }else{
    d.day++;
  }
  return d;
}
// Problem #16

// Problem #17
void swapDates(stDate &d1, stDate &d2);
short dateDiff(stDate d1, stDate d2, bool includeEndDay = false){
  short swaped = 1;
  if(!date1Beforedate2(d1, d2)){
    swaped = -1;
    swapDates(d1, d2);
  }
  short days = 0;
  while(date1Beforedate2(d1, d2)){
    days++;
    d1 = increaseDateByOneDay(d1);
  }
    return days = includeEndDay ? ++days * swaped: days * swaped;
}
// Problem #17

// Problem #18
stDate systemDate(){
  stDate sDate;
  time_t t = time(nullptr);
  tm* now = localtime(&t);
  sDate.day = now->tm_mday;
  sDate.month = now->tm_mon + 1;
  sDate.year = now->tm_year + 1900;
  return sDate;
}
short dateInDays(stDate d){
  stDate d1 = systemDate();
  return dateDiff(d, d1);
}
// Problem #18

// Problem #19
void swapDates(stDate &d1, stDate &d2){
  stDate temp = d2;
  d2 = d1;
  d1 = temp;
}
// short dateDiffn(stDate d1, stDate d2, bool includeEndDay = false){
//   short swaped = 1;
//   if(!date1Beforedate2(d1, d2)){
//     swaped = -1;
//     swapDates(d1, d2);
//   }
//   short days = 0;
//   while(date1Beforedate2(d1, d2)){
//     days++;
//     d1 = increaseDateByOneDay(d1);
//   }
//     return days = includeEndDay ? ++days * swaped: days * swaped;
// }
// Problem #19

// Problem #20 -> #32 
stDate addDays(short days, stDate d){
  for (short i = 1; i <= days; i++)
  {
    d = increaseDateByOneDay(d);
  }
  return d;
}
stDate addOneWeek(stDate d){
  for (short i = 1; i <= 7; i++)
  {
    d = increaseDateByOneDay(d);
  }
  return d;
}
stDate addWeeks(short weeks, stDate d){
  for (short i = 1; i <= weeks; i++)
  {
    d = addOneWeek(d);
  }
  return d;
}
stDate addOneMonth(stDate d){
  if(d.month == 12){
    d.month = 1;
    d.year++;
  }else{
    d.month++;
  }
  short monthDays = daysInMonth(d.month, d.year);
  if(d.day > monthDays){
    d.day = monthDays;
  }
  return d;
}
stDate addMonths(short months, stDate d){
  for (short i = 1; i <= months; i++)
  {
    d = addOneMonth(d);
  }
  return d;
}
stDate addOneYear(stDate d){
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  d.year++;
  return d;
}
stDate addYears(short years, stDate d){
  d.year += years;
  return d;
}
stDate addOneDecade(stDate d){
  d.year += 10;
  return d;
}
stDate addDecades(short decades, stDate d){
  d.year += 10*decades;
  return d;
}
stDate addOneCentury(stDate d){
  d.year += 10;
  return d;
}
stDate addCenturies(short centuries, stDate d){
  d.year += 100*centuries;
  return d;
}
stDate addOneMillennium(stDate d){
  d.year += 1000;
  return d;
}
// Problem #20 -> #32

// Problem #33 -> #46
stDate decreaseDateByOneDay(stDate d){
  if(d.day == 1 && d.month == 1){
    d.month = 12;
    d.day = 31;
    d.year--;
  }else if(d.day == 1 && d.month != 1){
    d.month--;
    d.day = daysInMonth(d.month, d.year);
  }else{
    d.day--;
  }
  return d;
}
stDate removeDays(short days, stDate d){
  for (short i = 1; i <= days; i++)
  {
    d = decreaseDateByOneDay(d);
  }
  return d;
}
stDate removeOneWeek(stDate d){
  for (short i = 1; i <= 7; i++)
  {
    d = decreaseDateByOneDay(d);
  }
  return d;
}
stDate removeWeeks(short weeks, stDate d){
  for (short i = 1; i <= weeks; i++)
  {
    d = removeOneWeek(d);
  }
  return d;
}
stDate removeOneMonth(stDate d){
  if(d.month == 1){
    d.month = 12;
    d.year--;
  }else{
    d.month--;
  }
  short monthDays = daysInMonth(d.month, d.year);
  if(d.day > monthDays){
    d.day = monthDays;
  }
  return d;
}
stDate removeMonths(short months, stDate d){
  for (short i = 1; i <= months; i++)
  {
    d = removeOneMonth(d);
  }
  return d;
}
stDate removeOneYear(stDate d){
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  d.year--;
  return d;
}
stDate removeYears(short years, stDate d){
  d.year -= years;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
stDate removeOneDecade(stDate d){
  d.year -= 10;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
stDate removeDecades(short decades, stDate d){
  d.year -= 10*decades;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
stDate removeOneCentury(stDate d){
  d.year -= 100;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
stDate removeCenturies(short centuries, stDate d){
  d.year -= 100*centuries;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
stDate removeOneMillennium(stDate d){
  d.year -= 1000;
  if(d.month == 2 && d.day == 29){
    !isLeapYear(d.year) ? d.day = 28 : d.day;
  }
  return d;
}
// Problem #33 -> #46

// Problem #47 -> #53
bool isLastDayInYear(stDate d){
  return (d.day == 31 && d.month == 12);
}
int inWeekOrder(stDate d){
  return inWeekOrder(d.day, d.month, d.year);
}
bool isEndOfWeek(stDate d){
  return days[inWeekOrder(d)] == "Sat";
}
bool isWeekEnd(stDate d){
  return (days[inWeekOrder(d)] == "Fri" || days[inWeekOrder(d)] == "Sat");
}
bool isBusinessDay(stDate d){
  return !isWeekEnd(d);
}
short daysToEndOfWeek(stDate d){
  return 6 - inWeekOrder(d);
}
short daysToEndOfMonth(stDate d){
  stDate end;
  end.day = daysInMonth(d.month, d.year);
  end.month = d.month;
  end.year = d.year;
  return dateDiff(d, end, 1);
}
short daysToEndOfYear(stDate d){
  stDate end;
  end.day = 31;
  end.month = 12;
  end.year = d.year;
  return dateDiff(d, end, 1);
}
// Problem #47 -> #53

// Problem #54
short vacationDays(stDate from, stDate to){
  short vac = 0;
  while(date1Beforedate2(from, to)){
    if(isBusinessDay(from)){
      vac++;
    }
    from = increaseDateByOneDay(from);
  }
  return vac;
}
// Problem #54

// Problem #55
stDate vacationEndDate(short vac, stDate date){
  while(vac){
    if(isWeekEnd(date)){
      vac++;
    }
    date = increaseDateByOneDay(date);
    vac--;
  }
  return date;
}
// Problem #55

// Problem #56
bool date1AfterDate2(stDate d1, stDate d2){
  return !date1Beforedate2(d1,d2) && !date1equalsdate2(d1,d2);
}
// Problem #56

// Problem #57
enum enResult {eBefore = -1, eAfter = 1, eEqual = 0};
short compareDates(stDate d1, stDate d2){
  if(date1Beforedate2(d1,d2)){
    return enResult::eBefore;
  }else if(date1AfterDate2(d1,d2)){
    return enResult::eAfter;
  }else{
    return enResult::eEqual;
  }
}
// Problem #57

// Problem #58
struct stPeriod {
  stDate start;
  stDate end;
};
bool periodsOverlaping(stPeriod period1, stPeriod period2){
  if((compareDates(period1.end, period2.start) == enResult::eBefore) ||
  (compareDates(period1.start, period2.end) == enResult::eAfter)){
    return false;
  }
  return true;
}
// Problem #58

// Problem #59
short daysInPeriod(stPeriod p, bool includeEnd = false){
  return dateDiff(p.start, p.end, includeEnd);
}
// Problem #59

// Problem #60
bool isDateInPeriod(stDate d, stPeriod p){
  return !(
  compareDates(d, p.start) == enResult::eBefore
  ||
  compareDates(d, p.end) == enResult::eAfter
  );
}
// Problem #60

// Problem #61
void swapPeriods(stPeriod &p1, stPeriod &p2){
  stPeriod p = p1;
  p1 = p2;
  p2 = p;
}
short overlapingCount(stPeriod shrt, stPeriod lng){
  if(!periodsOverlaping(shrt, lng)){
    return 0;
  }
  if(daysInPeriod(shrt) > daysInPeriod(lng)){
    swapPeriods(shrt,lng);
  }
  short count = 0;
  while(compareDates(shrt.start,shrt.end) != enResult::eAfter){
    isDateInPeriod(shrt.start, lng) ? count++ : count;
    shrt.start = increaseDateByOneDay(shrt.start);
  }
  return count;
}
// Problem #61

// Problem #62
bool isValidDate(stDate d){
  if(d.year > 100){
    if(d.month >= 1 && d.month <= 12){
      if(d.month == 2){
        if(isLeapYear(d.year)){
          d.day <= 29 ? true : false;
        }
      }
      if(d.day > 0 && d.day <= daysInMonth(d.month, d.year)){
        return true;
      }
    }
  }
  return false;
}
// Problem #62

// Problem #63 + #64
stDate stringToDate(string d){
  vector<string> data = zsplit(d, "/");
  stDate date;
  date.day = stoi(data[0]);
  date.month = stoi(data[1]);
  date.year = stoi(data[2]);
  return date;
}
string dateToString(stDate d){
  return (to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year));
}
// Problem #63 + #64

// Problem #65
string formatDate(string d, string format = "dd/mm/yyyy"){
  stDate fDate = stringToDate(d);
  string formatted = "";
  formatted = nreplace(format, "dd", to_string(fDate.day));
  formatted = nreplace(formatted, "mm", to_string(fDate.month));
  formatted = nreplace(formatted, "yyyy", to_string(fDate.year));
  return formatted;
}
// Problem #65