#include "Person.h"
#include <iostream>
#include <cstring>
Person::Person(){
    mLastName = "";
    mFirstName[0] = '\0';
}
Person::Person(const std::string& ln, const char *fn):mLastName(ln)
{
    strncpy(mFirstName, fn, sizeof(mFirstName) - 1);
}
void Person::Show() const {
    std::cout<<this->mLastName<<" "<<this->mFirstName<<std::endl;
}
void Person::FormalShow() const {
     std::cout<<this->mFirstName<<" "<<this->mLastName<<std::endl;
}
