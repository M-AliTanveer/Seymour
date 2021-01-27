#include "Toping.h"
#include "Mashroom.h"
#include <string.h>
Mashroom::Mashroom(): Creamlized_Onion(false),Creamy_Rosted_Garlic_Sause(true)
{
    strcpy_s(name, "Mashroom");
    strcpy_s(details, "This earthy topping can be divisive in the kitchen, but many agree that it fits right in on a pizza. Spoiler: You are going to love it. ");
    price = 200;
}
void Mashroom::setCO(bool n)
{
    Creamlized_Onion = n;
    if (Creamlized_Onion == true)
    {
        price= price + 40;
    }
}
bool Mashroom::getCO() const
{
    return Creamlized_Onion;
}
bool Mashroom::getCRGS() const
{
    return Creamy_Rosted_Garlic_Sause;
}
void Mashroom::setCRGS(bool n)
{
    Creamy_Rosted_Garlic_Sause = n;
}
