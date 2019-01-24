#include "date.h"
#include <cmath>
Date::Date():Day(0),Month(0),Year(0),Formatting('/'){}
Date::~Date(){}
Date::Date(int day,int month,int year,char formatting){
  Day=day;
  Month=month;
  Year=year;
  Formatting=formatting;
}
Date::Date(string str){
  istringstream i_str_stream(str);
  (i_str_stream >> Day).get();
  (i_str_stream >> Month).get();
  i_str_stream >> Year;
  Formatting = check_formating(str);
}
int Date::getDay() const noexcept{
  return Day;
}
int Date::getMonth() const noexcept{
  return Month;
}
int Date::getYear() const noexcept{
  return Year;
}
Date Date::operator-(const Date& date){
  Date temp_date;

  if(this->Year-date.Year<0)
  {
    temp_date.Month = date.Month - this->Month;
    temp_date.Day = date.Day - this->Day;
  }else {
    temp_date.Month =  this->Month - date.Month;
    temp_date.Day = this->Day - date.Day;
  }

  temp_date.Year = abs(this->Year-date.Year);

  if(temp_date.Month < 0){
    temp_date.Year -=1;
    temp_date.Month +=12;
  }
  if(temp_date.Day < 0){
      temp_date.Month -=1;
      temp_date.Day +=30;
  }
  temp_date.Formatting = this->Formatting;
  cout<<"differences "<<temp_date.Day<<" day's "<<temp_date.Month
                      <<" month's "<<temp_date.Year<<" year's "<<endl;
  return temp_date;
}
ostream& operator<<(ostream& os_stream,const Date& temp_date) {
  os_stream<<temp_date.Day<<temp_date.Formatting<<temp_date.Month
                  <<temp_date.Formatting<<temp_date.Year<<std::endl;
  return os_stream;
}
istream& operator>>(istream& is_stream,Date& temp_date){
  std::cout<<"Please Enter string date using one of separator's \n \
              from this list [ '/' , '.' , '-' ]"<<std::endl;
  string temp_str;
  is_stream>>temp_str;
  istringstream i_str_stream(temp_str);
  (i_str_stream >> temp_date.Day).get();
  (i_str_stream >> temp_date.Month).get();
  i_str_stream >> temp_date.Year;
  temp_date.Formatting = temp_date.check_formating(temp_str);
  return is_stream;
}
char Date::check_formating(string temp_str){
  smatch res1;
	regex pattern("\\b[-./]\\b");
	regex_search(temp_str, res1, pattern);
	string output;
  for (unsigned i=0; i<res1.size(); ++i) {
    output+= res1.str(i);
  }
  return static_cast<char>(output[0]);
}
