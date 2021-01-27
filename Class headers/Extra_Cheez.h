#ifndef EXTRA_CHEEZ
#define EXTRA_CHEEZ
#include "Toping.h"
#include <iostream>
using namespace std;
enum Extras { Macroni = 1, Cheese = 2};
class Extra_Cheez : public Toping
{
private:
    bool Red_Pepper_Flakes;
    Extras Extra;


public:
    Extra_Cheez();
    void setRPF(bool);
    bool getRPF() const;
    void setExtra(Extras);
    Extras getExtra()const;
    
};
#endif