/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the Coupon class.
*/
#include <string>
#include "Coupon.h"
#include "Date.h"
using namespace std;


Coupon:: Coupon(const string& str){
   expiration_ = str;
}
//Returns true if expired
bool Coupon::hasExpired(const string& str) const{
  Date str1;
  str1 = str;
  return expiration_ < str1;
}

//Do not change this function
double Coupon::calculateCost(double purchase) const {
  return 0;
}

//Do not change this function
string Coupon::toString() const {
  return "TBD";
}


