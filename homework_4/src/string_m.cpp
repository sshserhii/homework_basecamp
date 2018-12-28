#include "string_m.h"

String::String(){
  str_ptr=nullptr;
  str_length=0;
}

String::String(char char_temp){
  str_length=1;
  str_ptr = new char(char_temp);
}

String::String(const char* char_str){
  if(char_str){
    int n=0;
    while(char_str[n]!='\0'){
      n++;
    }
    str_length = n;
    str_ptr = new char[str_length];
    for (int i=0;i<str_length;i++){
      str_ptr[i]=char_str[i];
    }
    str_ptr[n]='\0';
  }else{
    str_length=0;
    str_ptr=nullptr;
  }

}

String::String(String& str_temp){
  str_length = str_temp.length();
  str_ptr = new char[str_length];
  for (int i=0;i<str_length;i++){
    str_ptr[i]=str_temp.str_ptr[i];
  }
}

String::~String(){
  delete[] str_ptr;
}

int String::length() const noexcept {
  return str_length;
}

String& String::append(const String& str){

  int temp_length = str_length+str.str_length;
  char* temp_char_buffer = new char[temp_length];

  for (int i=0;i<str_length;i++){
    temp_char_buffer[i]=str_ptr[i];
  }

  for (int j=0;j<str.str_length;j++){
    temp_char_buffer[str_length+j]=str.str_ptr[j];
  }

  delete[] str_ptr;
  str_length = temp_length;
  temp_char_buffer[temp_length]='\0';
  str_ptr=temp_char_buffer;
  return *this;
}

ostream& operator<<(ostream& os,const String& str){
  os<<str.str_ptr<<" "<<str.str_length<<endl;
  return os;
}

istream& operator>>(istream& is,String& str){
    cout<<"Enter string :"<<endl;
    char* buffer = new char[1000];
    is>>buffer;
    str = String(buffer);
    delete[] buffer;
    return is;
}

void String::resize(int n){
  char* temp_char_buffer = new char[n];
  for(int i=0;i<n;i++){
    temp_char_buffer[i] = str_ptr[i];
  }
  delete[] str_ptr;
  temp_char_buffer[n] = '\0';
  str_ptr = temp_char_buffer;
  str_length = n;
}

void String::clear() noexcept {
  str_length = 0;
  delete[] str_ptr;
  str_ptr = new char('\0');
}

char* String::get_buffer(){
  return this->str_ptr;
}

void String::swap(String& str){
  String temp(str);
  str = *this;
  *this = temp;
}

bool String::operator!=(const String& right) noexcept {
  return !(*this == right);
}

bool String::operator==(const String& right) noexcept {
  if(str_length != right.str_length){
    return false;
  }
  int step =0;
  while((step<str_length) && (str_ptr[step]=right.str_ptr[step])){
    step++;
  }
  return (step==str_length);
}

String String::operator+ (const String& right){
  String temp;
  temp.append(*this);
  temp.append(right);
  return temp;
}

String& String::operator+= (const String& right){
*this=*this+right;
return *this;
}

String& String::operator=(const String& str){
  if(this == &str){
    return *this;
  }
  delete str_ptr;
  str_length = str.str_length;
  str_ptr = new char[str_length];
  for(int i=0;i<str_length;i++){
    str_ptr[i] = str.str_ptr[i];
  }
  str_ptr[str_length] = '\0';
  return *this;
}

void String::insert(char c,int position){
  if(str_length == 0){
    str_ptr[0]=c;
  }
  int temp_length = str_length + 1;
  char* temp_buffer = new char[temp_length];
  for (int i=0,j=0;i<temp_length;i++,j++){
    if(i==position){
      temp_buffer[j] = c;
      j++;
    }
    temp_buffer[j]=str_ptr[i];
  }

  delete[] str_ptr;
  temp_buffer[temp_length] = '\0';
  str_ptr = temp_buffer;
  str_length = temp_length;
}

void String::insert(String& str,int position){
  if(str_length == 0){
    this->append(str);
  }
  int temp_length = str_length + str.str_length;
  char* temp_buffer = new char[temp_length];

  for(int i=0,c=0;i<temp_length;i++,c++){
    if(i==position){
      for(int j=0;j<str.str_length;j++){
        temp_buffer[i+j]=str.str_ptr[j];
      }
      i+=str.str_length;
    }
    temp_buffer[i]=str_ptr[c];
  }
  delete[] str_ptr;
  temp_buffer[temp_length]='\0';
  str_ptr = temp_buffer;
  str_length = temp_length;
}

int String::compare(const String& right) const noexcept{
  if(this->str_length > right.str_length){
    return 1;
  }else if (this->str_length < right.str_length){
    return -1;
  }
  return 0;
}
int String::substr(String& sub_string){
  int index =-1; int step=0;
  for(int i=0;i<this->str_length;i++){
      if(this->str_ptr[i] == sub_string.str_ptr[step]){
        if(step==0){
          index =i;
        }
        step++;
        if(step == sub_string.str_length){
          return index;
        }
      }else {
        step=0;
      }
  }
    return -1;
}
