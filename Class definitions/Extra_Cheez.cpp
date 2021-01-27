#include "Toping.h"
#include "Extra_Cheez.h"
#include <string.h>
Extra_Cheez::Extra_Cheez() : Red_Pepper_Flakes(false),Extra(Macroni)
{
    strcpy_s(name, "Extra_Cheez");
    price = 140;
    strcpy_s(details, "Who does not love a little extra cheese for the perfect cheese-pull picture? We sure do. ");
}

void Extra_Cheez::setRPF(bool n)
{
    Red_Pepper_Flakes = n;
    if (Red_Pepper_Flakes == true)
    {
        price = (price + 50);
    }
}
bool Extra_Cheez::getRPF() const
{
    return Red_Pepper_Flakes;
}
void Extra_Cheez::setExtra(Extras E)
{
    Extra = E;
    if (Extra == Cheese)
    {
        price = (price + 150);
    }
}
Extras Extra_Cheez::getExtra() const
{
    return Extra;
}
