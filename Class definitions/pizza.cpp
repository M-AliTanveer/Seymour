#include "pizza.h"

pizza::pizza()
{
	cpoint = NULL;
	fpoint = NULL;
	tpoint = NULL; 
	final_price = 0;
}
pizza::pizza(crust* a, flavour* b, Toping* c) :cpoint(a), fpoint(b), tpoint(c){}
void pizza::adjustpricing(int size)
{
	cpoint->setsize(size);
	tpoint->increaseprice(size);
}
double pizza::getprice()
{
	final_price = cpoint->get_price() + fpoint->get_price() + tpoint->getprice();
	return final_price;
}
//void pizza::FlavourMiscSet(char desc[30])
//{
//	strcpy_s(FlavourMisc, desc);
//
//}
//void pizza::CrustMiscSet(char desc[30])
//{
//	strcpy_s(CrustMisc, desc);
//}
//void pizza::SaveFlavour(flavour* ptr)
//{
//	fpoint = ptr;
//}
//void pizza::SaveCrust(crust* ptr)
//{
//	cpoint = ptr;
//}
//void pizza::SaveToping(Toping* ptr)
//{
//	tpoint = ptr;
//}
//crust* pizza::getCrustPointer()
//{
//	return cpoint;
//}
//flavour* pizza::getFlavourPointer()
//{
//	return fpoint;
//}