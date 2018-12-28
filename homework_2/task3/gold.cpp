#include <iostream>
#include <string.h>

constexpr int Len=40;
struct golf{
char fullname[Len];
int handicap;
};

void setGolf(golf& g,const char* name,int hc){
strcpy(g.fullname,name);
g.handicap = hc;
}
int  setGolf(golf& g){

if(std::cin.getline(g.fullname,Len,'\n')){
	std::cin>>g.handicap;
	return 1;
}
else{
	return 0;
	}
}

void handicap(golf &g,int hc){
g.handicap = hc;
}
void showGolf(const golf& g){
std::cout<<"FullName = "<<g.fullname<<" Handicap = "<<g.handicap<<std::endl;
}
int main(){
golf t;
char chr[] ="Hello";
//setGolf(t,chr,5);
setGolf(t);
//handicap(t,5);
showGolf(t);
return 0;
}
