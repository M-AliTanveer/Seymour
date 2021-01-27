#pragma once
#include "crust.h"
#include "flavours.h"
#include "Toping.h"
class pizza
{
protected:
	double final_price;
public:
	crust* cpoint;
	flavour* fpoint;
	Toping* tpoint;
	pizza();
	pizza(crust*, flavour*, Toping*);
	double getprice();
	void adjustpricing(int size);
};

