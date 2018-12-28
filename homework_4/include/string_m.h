#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String{
private:
  char *str_ptr;
  int str_length;
public:
  //constructor's
  String();
  String(char char_temp);
  String(const char* char_str);
  String(String& str_temp);
  //destructor
  ~String();
  char* get_buffer();
  int length() const noexcept;
  String& append(const String& str);
  int compare(const String& str) const noexcept;
  void resize(int n);
  void clear() noexcept;
  void swap(String& str);
  void insert(String& str,int position);
  void insert(char c,int position);
  int substr(String& sub_string);

  //stream for output & input
  friend ostream& operator<<(ostream& os,const String& str);
  friend istream& operator>>(istream& is,String& str);
  //overloaded operator's
  bool operator==(const String& right) noexcept;
  bool operator!= (const String& right) noexcept;
  String operator+ (const String& right);
  String& operator= (const String& str);
  String& operator+= (const String& right);

};





#endif
