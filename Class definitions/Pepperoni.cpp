#include "Toping.h"
#include "Pepperoni.h"
#include <iostream>
#include <string.h>
using namespace std;
Pepperoni::Pepperoni(): Type(Vegan),QOFMC(Usual)
{
    strcpy_s(name, "Pepperoni");
    strcpy_s(details, "Poll after poll, pepperoni always tops the list of Americas favorite pizza toppings. ");
    price = 150;

}
void Pepperoni::setType(TypeofTopping TOT)
{
    Type = TOT;
}
TypeofTopping Pepperoni::getType()const
{
    return Type;
}
void Pepperoni::setQOFMC(QuantityOfmozzarellecheese Q)
{
    QOFMC = Q;
    if (QOFMC == More) price = price + 50;
    else if (QOFMC == Little)  price = price - 30;
    else if (QOFMC == Not_Include) price = price - 50;
}
QuantityOfmozzarellecheese Pepperoni::getQOFMC() const
{
    return QOFMC;
}
