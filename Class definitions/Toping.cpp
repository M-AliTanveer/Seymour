#include "Toping.h"
#include <iostream>
#include <string.h>
using namespace std;
Toping::Toping(){}

void Toping::setprice(int p)
{
    price = p;
}

char* Toping::getdetails()
{
    return details;
}

void Toping::setdetails(char I[])
{
    strcpy_s(details,I);
}
char* Toping::getToppingName()
{
    return name;
}
void Toping::increaseprice(int size)
{
    price = price + ((size-6) * 20);
}
int Toping::getprice() const
{
    return price;
}
