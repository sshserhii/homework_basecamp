#include "Move.h"

Move::Move(double a,double b):x(a),y(b)
{}
void Move::showmove() const {   
std::cout<<"Current value of X is = "<<this->x<<std::endl<<"Current value of Y is =  "<<this->y<<std::endl;
}
void Move::reset(double a,double b){
        this->x = a;
        this->y = b;
}     
Move* Move::add(const Move & m) const{   
return new Move(this->x+m.x,this->y+m.y);
}
