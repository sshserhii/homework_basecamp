#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Date {
public:
  Date(int day,int month,int year,char formatting);
  Date();
  Date(string str);
  ~Date();
  char check_formating(string temp_str);
  friend ostream& operator<<(ostream& os_stream,const Date& temp_date);
  friend istream& operator>>(istream& is_stream,Date& temp_date);
  Date operator-(const Date& date);
  void modify_date(Date& date_1);
  int getDay() const noexcept;
  int getMonth() const noexcept;
  int getYear() const noexcept;
private:
  int Day;
  int Month;
  int Year;
  char Formatting;
};


#endif
