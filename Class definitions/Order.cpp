#include "Order.h"
#include<fstream>
#include<string.h>
using namespace std;
int Order::TotalOrdersOfDay = 0;
Order::Order()
{
	int i;
	no_of_pizzas = 0;
	bill = 0;
	for (i = 0; i < 5; i++)
	{
		strcpy_s(CRUSTS[i], "");
		strcpy_s(FLAVOURS[i], "");
		strcpy_s(TOPPINGS[i], "");
	}
	strcpy_s(address, "");
	
}
void Order::PlaceOrder(pizza* pizza, int pizzaamount)
{
	int i;
	no_of_pizzas = pizzaamount;
	for (i = 0; i < no_of_pizzas; i++)
	{
		strcpy_s(FLAVOURS[i], (pizza + i)->fpoint->get_FlavName());
		strcpy_s(CRUSTS[i], (pizza + i)->cpoint->get_CrustName());
		strcpy_s(TOPPINGS[i], (pizza + i)->tpoint->getToppingName());
	}
	fstream yourorder("Receipt.txt",ios::in| ios::out | ios::app);
	yourorder << "Total pizzas ordered: " << pizzaamount <<endl;
	for (i = 0; i < no_of_pizzas; i++)
	{
		yourorder << "Pizza Number " << i + 1 <<endl;
		yourorder << CRUSTS[i] << " With the Flavor " << FLAVOURS[i] << " topped with a layering of " << TOPPINGS[i] << " ." <<endl;
	}
	yourorder << "Total Billed Amount is: Rs " << bill <<endl <<endl;
	yourorder << "X----------------------------------------------------X" << endl;
	yourorder.close();
	orderstatus = confirmed;
	IncrementTotalOrdersOfDay();
}
int Order::getpizzas()const
{
	return no_of_pizzas;
}
char* Order::getcrusts()
{
	return CRUSTS[0];
}
char* Order::getflavs()
{
	return FLAVOURS[0];
}
char* Order::gettoppings()
{
	return TOPPINGS[0];
}
double Order::ReturnBill()
{
	return bill;
}
void Order::FileOrder()
{
	fstream f;
	f.open("Orders.dat", ios::out | ios::app | ios::binary);
	f.write(reinterpret_cast<char*>(&*this), sizeof(*this));
	f.close();
}
void Order::operator=(const Order& obj)
{
	this->bill = obj.bill;
	for (int i = 0; i < 5; i++)
	{
		strcpy_s(FLAVOURS[i], obj.FLAVOURS[i]);
		strcpy_s(CRUSTS[i], obj.CRUSTS[i]);
		strcpy_s(TOPPINGS[i], obj.TOPPINGS[i]);
	}
	this->OrderCode = obj.OrderCode;
	this->no_of_pizzas = obj.no_of_pizzas;
	this->orderstatus = obj.orderstatus;
	for ( int i = 0; i < 5; i++)
	{
		this->size[i] = obj.size[i];
	}
	strcpy_s(this->address, obj.address);
}
void Order::operator =(int a)
{
	this->bill = 0;
	for (int i = 0; i < 5; i++)
	{
		strcpy_s(FLAVOURS[i], "");
		strcpy_s(CRUSTS[i], "");
		strcpy_s(TOPPINGS[i], "");
	}
	this->OrderCode = 0;
	this->no_of_pizzas = 0;
	for (int i = 0; i < 5; i++)
	{
		this->size[i] = 0;
	}
	strcpy_s(this->address, "");
}
void Order::operator-(const double DiscAmount)
{
	double TempDisc = DiscAmount;
	double TempBill = bill;
	if ((5 * TempDisc / 100) >= 500)
		TempBill = TempBill - 500;
	else
		TempBill = TempBill -  (5*TempDisc / 100);
	bill = TempBill;
}
void Order::setOrderCode(long int OrderCode)
{
	this->OrderCode = OrderCode;
}
void Order::setstatus(enum status stat)
{
	orderstatus = stat;
}
enum status Order::getstatus()
{
	return orderstatus;
}
void Order::setbill(double b)
{
	bill = b;
}
int* Order::getsize()
{
	return size;
}
void Order::setsize(int* s)
{
	for (int i = 0; i < 5; i++)
	{
		size[i] = s[i];
	}
}
long int Order::getOrderCode()const
{
	return OrderCode;
}
 void Order::IncrementTotalOrdersOfDay() 
{
	 TotalOrdersOfDay++;
}
 int Order::GetTotalOrdersOfDay()
 {
	 return TotalOrdersOfDay;
 }