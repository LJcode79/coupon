/*
  Visit https://bit.ly/2WlhC0A for detailed description of the project.
  You are encouraged to focus on implementing and testing the member functions before processing the "transactions.txt" file. 
*/
/* 
 * Name: Lawrence John Balanza
 * Course: CS 211
 * Date: 10/08/2021
 * Project 3: Coupon
 * Description:  Process two different types of coupons and determine how they may or may not affect the total of purchases.
*/
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "Date.h"
#include "Coupon.h"
#include "DeductionCoupon.h"
#include "PercentageCoupon.h"

int main() {
  ifstream file("transactions.txt");
  string str;
  getline(file,str);
  string date = str;

  string cDate;
  string typeCoupon = "x";
  string status = "Expired";
  double purchasePrice = 0.0;
  unsigned deductionAmount;
  unsigned minimum;
  unsigned percentAmount;
  int transaction = 1;

  cout << "TRANS" << setw(8) << "TOTAL" << setw(9) << "COUPON" << setw(25)
  <<  "STATUS" << setw(15) << "FINAL COST" << endl;
  
   if(file){
    while(getline(file,str)){
     string purchasePriceString = str.substr(0,str.find(" "));
     purchasePrice = stod(purchasePriceString);
     int firstSpace = str.find(" ");
     int secondSpace = str.find(" ",firstSpace+1);
     typeCoupon = str.substr(firstSpace+1,(secondSpace - firstSpace)-1);
     int thirdSpace = str.find(" ",secondSpace+1);
     cDate = str.substr(secondSpace + 1,(thirdSpace - secondSpace)-1);
      if (typeCoupon == "deduction"){
        int fourthSpace = str.find(" ",thirdSpace+1);
        deductionAmount = stoi(str.substr(thirdSpace+1,(fourthSpace - thirdSpace)-1));
        int fifthSpace = str.find(" ",fourthSpace+1);
        minimum = stoi(str.substr(fourthSpace+1,(fifthSpace - fourthSpace)-1));
        DeductionCoupon d(cDate, deductionAmount, minimum);
          if (d.hasExpired(date) == false){
            status = "In Effect";
            }
        if (status == "Expired"){
          cout << transaction << setw(12) << fixed 
          << setprecision(2)<< purchasePrice << setw(25)
          << d.toString() << setw(10) << status << setw(9)
          << purchasePrice << endl;
            }
        else{
          cout << transaction << setw(12) << purchasePrice << setw(25)
          << d.toString() << setw(12) << status << setw(7)
          << d.calculateCost(purchasePrice) << endl;
            }
     transaction++;
     status = "Expired";
        }
      else{
        int fourthSpace = str.find(" ",thirdSpace+1);
        percentAmount = stoi(str.substr(thirdSpace+1,(fourthSpace - thirdSpace)-1));
        PercentageCoupon p(cDate,percentAmount);

        if(p.hasExpired(date) == false){
          status = "In Effect";
          }
        if (status == "Expired"){
          cout << transaction << setw(12) << fixed 
          << setprecision(2) << purchasePrice << setw(16)
          << p.toString() << setw(19) << status << setw(9)
          << purchasePrice << endl;
          }
        else{
          cout << transaction <<setw(12) << fixed << setprecision(2) << purchasePrice << setw(16) << p.toString() << setw(21) << status 
          << setw(7) << p.calculateCost(purchasePrice) << endl;
        }
     transaction++;
     status = "Expired";
        }
      }
   }
}