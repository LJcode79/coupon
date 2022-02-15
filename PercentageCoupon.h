#ifndef PERCENTAGE_COUPON_H
#define PERCENTAGE_COUPON_H
#include <string>
#include "Coupon.h"
using namespace std;

class PercentageCoupon : public Coupon {
  private:
    unsigned discountPercent_;
  public:
    PercentageCoupon(const string& str, unsigned percent = 0);
    double calculateCost(double purchase) const;
    string toString() const;
};

#endif