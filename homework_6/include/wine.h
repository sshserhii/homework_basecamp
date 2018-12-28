#ifndef WINE_H
#define WINE_H
#include <string>
#include <utility>
#include <valarray>
#include <iostream>
using namespace std;
class Wine {
private:
string label_name;
int num_year;
pair<valarray<int>,valarray<int>> map_year_bottling;
public:
  Wine(const char* l, int y, const int yr[], const int bot[]);
  Wine(const char* l, int y);
  Wine() = default;
  ~Wine() = default;
  void getBottles();
  string& label();
  int sum();
  void show(); 
};
#endif
