#ifndef CHICKEN
#define CHICKEN
#include "Toping.h"
#include <iostream>
using namespace std;
enum Cheeses { Shredded_Parmesan = 1, Shredded_Cheddar = 2 };
class Chicken : public Toping
{
private:
    Cheeses Cheese;
    bool BBQ_Sause;

public:
    Chicken();
    void setCheese(Cheeses);
    Cheeses getCheese() const;
    void setBS(bool);
    bool getBS() const;
    
};
#endif