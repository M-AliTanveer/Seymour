#include "Toping.h"
#include "Sausage.h"
#include <string.h>
Sausage::Sausage() : Basil_Scattering(true), Red_Pepper_Flakes(true)
{
    strcpy_s(name, "Sausage");
    strcpy_s(details, "Some prefer mild, others spicy, and Southerners Conecuh, but sausage is consistently a favorite pizza topping of Americans. ");
    price = 175;
}

void Sausage::setRPF(bool RPF)
{
    Red_Pepper_Flakes = RPF;
    if (Red_Pepper_Flakes == true) price = price + 50;
}
bool Sausage::getRPF()const
{
    return Red_Pepper_Flakes;
}
void Sausage::setBS(bool BS)
{
    Basil_Scattering = BS;
}
bool Sausage::getBS()const
{
    return Basil_Scattering;
}
