#ifndef DEDUCTION_COUPON_H
#define DEDUCTION_COUPON_H
#include <string>
#include "Coupon.h"
using namespace std;

class DeductionCoupon : public Coupon {
  private:
    int deduction_;
    int minimumPurchase_;
  public:
    DeductionCoupon(const string& str, unsigned deduction = 0, unsigned minimum = 0);
    double calculateCost(double purchase) const;
    string toString() const;
};

#endif