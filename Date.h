#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
  private:
    unsigned days_;
    static const unsigned DAYS[12];
  public:
    Date();
    Date& operator=(const string& str);
    bool operator<(const Date& d) const;
    friend ostream& operator<<(ostream& output, const Date& d);
};

#endif