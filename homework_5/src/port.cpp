#include "port.h"
#include <string.h>
Port::Port(const char* br, const char* st, int b ){
  int step=0;
  while(br[step]!='\0'){
    step++;
  }
  brand = new char[step];
  strcpy(brand,br);
  strcpy(style,st);//check
  bottles = b;
}
char* Port::getBrand(){
  return brand;
}
char* Port::getStyle(){
  return style;
}
int Port::getBottles(){
  return bottles;
}
Port::Port(const Port& p){
  int step=0;
  while(p.brand[step]!='\0'){
    step++;
  }
  brand = new char[step];
  strcpy(brand,p.brand);
  strcpy(style,p.style);
  bottles=p.bottles;
}
Port& Port::operator=(const Port& p){
  int step=0;
  while(p.brand[step]!='\0'){
    step++;
  }
  delete [] brand;
  brand = new char[step];
  strcpy(brand,p.brand);
  strcpy(style,p.style);
  bottles=p.bottles;
  return *this;
}

Port::~Port() {
  delete[] brand;
 }
Port& Port::operator+=(int b){
  this->bottles+=b;
  return *this;
}
Port& Port::operator-=(int b){
  this->bottles-=b;
  return *this;
}
int Port::BottleCount() const {
  return bottles;
}
void Port::Show() const{
  cout<<"Brand: "<<this->brand<<endl;
  cout<<"Kind:"<<this->style<<endl;
  cout<<"Bottles: "<<this->bottles<<endl;
}
ostream& operator<<(ostream& os,const Port& p){
  os<<"Brand: "<<p.brand<<", "<<"Kind:"<<p.style<<", "<<"Bottles: "<<p.bottles<<endl;
  return os;
}
