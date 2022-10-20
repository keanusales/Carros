#ifndef INCLUDE_H
#define INCLUDE_H

#include <ctime>
using std::time_t;
using std::tm;

#include <sstream>
using std::stringstream;

#include <iostream>
using std::ostream;
using std::getline;
using std::string;
using std::cout;
using std::cin;

class Date {
  friend ostream &operator<<(ostream &, const Date*);

  public:
    Date();
    ~Date();
    bool checkDate(const int) const;

  private:
    int dia, mes, ano;
};

#endif