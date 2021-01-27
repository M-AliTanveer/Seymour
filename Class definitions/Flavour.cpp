#include"flavours.h"
#include<string.h>
flavour::flavour()
{
	price = 0;
	strcpy_s(description, "");
	strcpy_s(name, "");
}
char* flavour::get_FlavName()
{
	return name;
}
double flavour::get_price() const
{
	return price;
}
double  flavour::set_price(double PRICE)
{
	price = PRICE;
	return 0;
}
char* flavour::get_description()
{
	return description;
}
char* flavour::set_description(char* desc)
{
	strcpy_s(description, desc);
	return 0;
}
void flavour::increaseprice(int size)
{
	price = price + ((size-6) * 30);
}
