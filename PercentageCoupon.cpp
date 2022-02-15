/*
  Visit https://bit.ly/2WlhC0A for detailed description of the functions to be implemented for the PercentageCoupon class.
*/
#include <string>
#include <iomanip>
#include <sstream>
#include "Coupon.h"
#include "PercentageCoupon.h"
using namespace std;

PercentageCoupon::PercentageCoupon(const string& str, unsigned percent)
:Coupon(str){
  this->discountPercent_ = percent;
}

double PercentageCoupon::calculateCost(double purchase) const{
  double dPerc = ((double)discountPercent_)/100;
  return purchase- (purchase * dPerc);
}

string PercentageCoupon::toString() const{
  string s = "";
  stringstream t;
  t << this->expiration_ << " " << to_string(discountPercent_) << "% OFF";
  s = t.str();
  return s;
}