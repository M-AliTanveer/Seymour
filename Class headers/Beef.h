#ifndef BEEF
#define BEEF

#include "Toping.h"
#include <iostream>
using namespace std;
enum peppers { Green = 1, Red = 2 };
class Beef : public Toping
{
private:
    bool Cloves_Spice;
    peppers pepper;

public:
    Beef();
    void setCS(bool);
    bool getCS()const;
    void setpepper(peppers);
    peppers getpepper()const;

};
#endif