/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the DeductionCoupon class.
*/
#include <string>
#include <iomanip>
#include <sstream>
#include "Coupon.h"
#include "DeductionCoupon.h"
using namespace std;

DeductionCoupon::DeductionCoupon(const string& str, unsigned deduction, unsigned minimum): Coupon(str){
  this->deduction_= deduction;
  this->minimumPurchase_=minimum;
}

double DeductionCoupon::calculateCost(double purchase) const{
  if (purchase >= minimumPurchase_){
    return (purchase - deduction_);
  }
  else{
    return purchase;
  }
}

string DeductionCoupon::toString() const{
  string s = "";
  stringstream t;
  t << this->expiration_ << " $" << to_string(deduction_) << " OFF above $" << to_string(minimumPurchase_);
  s = t.str();
  return s;
}