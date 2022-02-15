/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the Date class.
*/
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Date.h"
using namespace std;

//Do not change this initialization
const unsigned Date::DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Do not change this function
Date::Date() : days_(0) {
}

Date& Date:: operator=(const string& str){
   int month = stoi(str.substr(0,2));
   int day = stoi(str.substr(3,2));
   int totalDays = 0;
   for(int i = 0; i<month-1; i++){
     totalDays += Date::DAYS[i];
   }
   totalDays += day;
   totalDays -= 1;
   this->days_ = totalDays;
   return *this;
}

bool Date:: operator<(const Date& d) const{
  return this->days_ < d.days_;
}

//
ostream& operator<<(ostream& output, const Date& d){
  int days = d.days_;
  int month = 1;
  while(days >= 31){
    days -= Date::DAYS[month];
    month++;
  }
  days = days+1;
  string dayss;
  string monthName;

  if(month == 1){
    monthName = "01";
  }
  if(month == 2){
    monthName = "02";
    days-= 3; //February is off by 3
  }
  if(month == 3){
    monthName = "03";
  }
  if(month == 4){
    monthName = "04";
    days-= 1; //April is off by 1
  }
  if(month == 5){
    monthName = "05";
  }
  if(month == 6){
    monthName = "06";
    days-= 1; //June is off by 1
  }
  if(month == 7){
    monthName = "07";
  }
  if(month == 8){
    monthName = "08";
  }
  if(month == 9){
    monthName = "09";
    days -= 1; //September off by 1
  }
  if(month == 10){
    monthName = "10";
  }
  if(month == 11){
    monthName = "11";
    days-= 1; //November off by 1
  }
  if(month == 12){
    monthName = "12";
  }
  if (days < 10){
    dayss = "0" + (to_string(days));
  }
  else{
    dayss = to_string(days);
  }
  output <<monthName << "/" << dayss;
  return output;
}