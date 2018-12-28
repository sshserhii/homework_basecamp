#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {
private:
    static constexpr int LIMIT = 25;
    std::string mLastName; // Person's last name
    char mFirstName[LIMIT]; // Person's first name
public:
    Person(); // #1
Person(const std::string & ln, const char * fn = "Heyyou"); // #2
// the following methods display mLastName and mFirstName
void Show() const; // firstname lastname format
void FormalShow() const; // lastname, firstname format
~Person() = default;
};


#endif // PERSON_H
