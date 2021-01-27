#pragma once
#include<string.h>
#include "crust.h"
#include "flavours.h"
#include "Toping.h"
#include"pizza.h"
#include"security.h"

enum status{confirmed,making,canceled,ready_for_delivery,delivering,delivered};

class Order : public secured
{
private:
    double bill;
    int no_of_pizzas;
    long int OrderCode;
    char FLAVOURS[5][30];
    char CRUSTS[5][30];
    char TOPPINGS[5][30];    
    int size[5];
    enum status orderstatus;
    static int TotalOrdersOfDay;
    static void IncrementTotalOrdersOfDay();
public:
    Order();
    static int GetTotalOrdersOfDay();
    void PlaceOrder(pizza *pizza,int pizzaamount);
    void FileOrder();
    void operator =(const Order& obj);
    void operator =(int);
    void operator -(const double DiscAmount);
    void setOrderCode(long int OrderCode);
    void setstatus(enum status);
    enum status getstatus();
    void setbill(double);
    int getpizzas()const;
    int* getsize();
    void setsize(int* s);
    char* getcrusts();
    char* getflavs();
    char* gettoppings();
    double ReturnBill();
    long int getOrderCode()const;
};

