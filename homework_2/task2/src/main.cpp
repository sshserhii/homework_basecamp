#include "Move.h"

int main(){
Move m1(2.1,3.2);
m1.showmove();
Move n1(1.5,2.1);
n1.showmove();
m1.reset();
Move* m2 = m1.add(n1);
m2->showmove();
m1.reset();
m1.showmove();
return 0;
}
