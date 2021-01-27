#ifndef PEPPERONI
#define PEPPERONI
#include <iostream>
using namespace std;
#include "Toping.h"
enum TypeofTopping { Vegan = 1, Non_Vegan = 2 };
enum QuantityOfmozzarellecheese { Usual = 1, More = 2, Little = 3, Not_Include = 4 };
class Pepperoni : public Toping
{
private:
    enum TypeofTopping Type;
    QuantityOfmozzarellecheese QOFMC;

public:
    Pepperoni();
    void setType(TypeofTopping);
    TypeofTopping getType()const;
    void setQOFMC(QuantityOfmozzarellecheese);
    QuantityOfmozzarellecheese getQOFMC()const;

};
#endif