#ifndef CHEF
#define CHEF
#include "Staff.h"
#include "Order.h"
#include <string.h>

class chef : public Staff
{
    bool Working;
    int Total_Orders;
    long int Working_Order_Code;
    
    bool updatechef();
public:
    Order Chefs_Order;
    chef();
    bool setID(string);
    bool check(string, string);
    bool addworkingorder();
    long int getworkingorder() const;
    bool setorderready();
    bool cancelorder();
    int getTotalOrders() const;
    bool getWorking() const;
    Order getcurrOrder() const;
};
#endif