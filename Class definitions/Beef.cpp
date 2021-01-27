#include "Toping.h"
#include "Beef.h"
#include <string.h>
Beef::Beef() :Cloves_Spice(false), pepper(Red)
{
    strcpy_s(name, "Beef");
    price = 380;
    strcpy_s(details, "In case you have not noticed the trend, meat is always popular on top of pizzas. No matter what the pizza is beef always has a place on pizza. ");

}
void Beef::setCS(bool n)
{
    Cloves_Spice = n;
    if (Cloves_Spice == true) price = price + 40;
}
bool Beef::getCS() const
{
    return Cloves_Spice;
}
void Beef::setpepper(peppers p)
{
    pepper = p;
}
peppers Beef::getpepper() const
{
    return pepper;
}
