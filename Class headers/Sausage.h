#ifndef SAUSAGE
#define SAUSAGE
#include "Toping.h"
#include <iostream>
using namespace std;
class Sausage : public Toping
{
private:
    bool Basil_Scattering;
    bool Red_Pepper_Flakes;


public:
    Sausage();
    void setRPF(bool);
    bool getRPF()const;
    void setBS(bool);
    bool getBS()const;
    
};
#endif