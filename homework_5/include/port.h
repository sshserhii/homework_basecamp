#include <iostream>
using namespace std;
class Port {
private:
    char* brand;
    char style[20]; // e.g. tawny, ruby, vintage
    int bottles;

public:
    Port(const char* br, const char* st, int b);
    Port(const Port& p);
    Port() = default;
    virtual ~Port();
    char* getBrand();
    char* getStyle();
    int getBottles();
    Port& operator= (const Port & p);
    Port& operator+= (int b) ; // adds b to bottles
    Port& operator-= (int b); // subtracts b from bottles, if possible

    int BottleCount() const;
    virtual void Show() const;
    friend std::ostream& operator<< (std::ostream& os, const Port& p);
};
