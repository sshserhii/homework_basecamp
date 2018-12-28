#include "wine.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[]){
  label_name=l;
  num_year=y;
  valarray<int> t1(yr,num_year);
  valarray<int> t2(bot,num_year);
  map_year_bottling.first = t1;
  map_year_bottling.second = t2;
}
Wine::Wine(const char* l, int y){
  label_name=l;
  num_year=y;
}
void Wine::show(){
  cout<<"----------------------------------"<<endl;
  cout<<"Label : "<<label_name<<" Year's : "<<num_year<<endl;
  for(int i=0;i<num_year;i++){
     cout<<" Year : "<<map_year_bottling.first[i]
     <<" Number : "<< map_year_bottling.second[i]<<endl;
  }

}
void Wine::getBottles(){
  int counter =0;
  int temp;
  valarray<int> t1(num_year);
  valarray<int> t2(num_year);
  while(counter<num_year){
    cout<<"Enter year "<<endl;
    cin>>temp;
    t1[counter] = temp;
    cout<<"Enter number of bottles "<<endl;
    cin>>temp;
    t2[counter] = temp;
    counter++;
  }
  map_year_bottling.first = t1;
  map_year_bottling.second = t2;
}
string& Wine::label(){
  return label_name;
}
int Wine::sum(){
  return map_year_bottling.second.sum();
}
