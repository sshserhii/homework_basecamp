#include "vintage_port.h"
#include <string.h>
VintagePort::VintagePort():Port(){
  nickname = nullptr;
  year = 0;
}
VintagePort::VintagePort(const char* br, int b, const char* nn, int y):Port(br,"vintage",b){
  int step=0;
  while(nn[step]!='\0'){
    step++;
  }
  nickname = new char[step];
  strcpy(nickname,nn);
  year = y;
}
VintagePort::VintagePort(const VintagePort& vp):Port(vp){
  int step=0;
  while(vp.nickname[step]!='\0'){
    step++;
  }
  nickname = new char[step];
  strcpy(nickname,vp.nickname);
  year = vp.year;
}
char* VintagePort::getNickname(){
  return nickname;
}
int VintagePort::getYear(){
  return year;
}
VintagePort& VintagePort::operator=(const VintagePort &vp){
  int step =0;
  Port::operator=(vp);
  delete[] nickname;
  while(vp.nickname[step]!='\0'){
    step++;
  }
  nickname = new char[step];
  strcpy(nickname,vp.nickname);
  year = vp.year;
  return *this;
}
void VintagePort::Show() const {
  Port temp(*this);
  temp.Show();
  cout<<"nickname: "<<this->nickname<<endl;
  cout<<"year: "<<this->year<<endl;
}

ostream& operator<<(ostream& os,const VintagePort& p){
  os<<(const Port&) p;
  os<<p.nickname<<", "<<p.year<<endl;
  return os;
}
