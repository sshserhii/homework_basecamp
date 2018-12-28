#include "wine.h"

int main() {

      cout << "Enter name of wine: ";
      char lab[50] = "";
      cin.getline(lab, 50);
      cout << "Enter number of years: ";
      int yrs{0};
      cin >> yrs;

      Wine holding(lab, yrs);
      holding.getBottles();
      holding.show();
      cout << "Total bottles for " << holding.label() << ": " << holding.sum() << endl;

      constexpr int kYears = 3;
      int y[kYears] = { 1993, 1995, 1998 };
      int b[kYears] = { 48, 60, 72 };

      Wine more("Chianti", kYears, y, b);
      more.show();
      cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    return 0;
}
