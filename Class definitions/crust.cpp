#include "crust.h"
int crust::getsize() const
{
    return size;
}
double crust::get_price() const
{
    return price;
}
void crust::set_price(double p)
{
    price = p;
}
char* crust::get_description()
{
    return description;
}
void crust::set_description(string s)
{
    for (int i = 0; i < 350; i++)
    {
        description[i] = s[i];
    }
}
bool crust::getthickthin() const
{
    return thick;
}
void crust::setthickthin(bool b)
{
    thick = b;
    thin = !b;
}
bool crust::getgluten() const
{
    return gluten;
}
void crust::setgluten(bool g)
{
    gluten = g;
}
char* crust::get_CrustName()
{
    return name;
}