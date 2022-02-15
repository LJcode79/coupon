#ifndef COUPON_H
#define COUPON_H
#include <string>
#include "Date.h"
using namespace std;

class Coupon {
  protected:
    Date expiration_;
  public:
    Coupon(const string& str);
    bool hasExpired(const string& str) const;
    double calculateCost(double purchase) const;
    string toString() const;
};

#endif