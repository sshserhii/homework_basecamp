#include <iostream>
#include "Person.h"
using namespace std;

int main()
{   string name = "Petya";
    char * fname = "homonds";
    Person p1(name,fname);
    p1.Show();
    p1.FormalShow();
    return 0;
}
