#include "Toping.h"
#include "Chicken.h"
#include <iostream>
#include <string.h>
using namespace std;
Chicken::Chicken(): Cheese(Shredded_Cheddar),BBQ_Sause(false) 
{
    strcpy_s(name, "Chicken");
    price = 170;
    strcpy_s(details, "The winner winner of weeknight meals goes well on pizzas, any kind of chicken pizza orders that contain this protein. ");

}

void Chicken::setCheese(Cheeses C)
{
    Cheese = C;
}
Cheeses Chicken::getCheese() const
{
    return Cheese;
}
void Chicken::setBS(bool n)
{
    BBQ_Sause = n;
    if (BBQ_Sause == true) price = price + 50;
}
bool Chicken::getBS() const
{
    return BBQ_Sause;
}
