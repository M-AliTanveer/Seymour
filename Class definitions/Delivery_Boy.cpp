#include "Person.h"
#include "Staff.h"
#include "Delivery_Boy.h"
#include <fstream>
#include <string.h>
Delivery_Boy::Delivery_Boy() :On_Delivery(false)
{
    Total_Orders = 0;
    Working_Order_Code = 0;
}

bool Delivery_Boy::setID(string id)
{
    try
    {
        Delivery_Boy DB;
        int f = 0;
        ofstream test("Delivery_Boy.dat", ios::app);
        test.close();
        ifstream is("Delivery_Boy.dat", ios::binary);
        is.seekg(0);
        bool empty = (is.get(), is.eof());
        if (empty != 1)
        {
            is.seekg(0);
            while (!is.eof())
            {
                is.read((char*)&DB, sizeof(DB));
                if (DB.getID() == id)
                {
                    f = 1;
                    break;
                }
                else continue;
            }
        }
        if (f == 0)
        {
            if (id[0] == 'D' && id[1] == '_')
            {
                strcpy_s(Staff_ID, id.c_str());
                return true;
            }
            else
            {
                throw(1);
            }
        }
        else
        {
            throw(1);
        }
        is.close();
    }
    catch (...)
    {
        strcpy_s(Staff_ID, "");
        return false;
    }
}

bool Delivery_Boy::addworkingorder(long int ordercode)
{
    Order temp;
    int n = 0, flag1 = 0, flag2 = 0;
    ifstream is("Orders.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);

    //pos = (int)fs.tellg();
    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (temp.getstatus() == ready_for_delivery && n == 0)
        {
            flag1 = 1;
            n++;
            Working_Order_Code = temp.getOrderCode();
            temp.setstatus(delivering);
            Delivery_Order = temp;
            On_Delivery = true;
            os.write((char*)&temp, sizeof(temp));
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    is.close();
    os.close();
    remove("Orders.dat");
    rename("temp.dat", "Orders.dat");
    flag2 = updateBoy();
    if (flag1 == 1 && flag2 == 1) return true;
    else return false;
}
bool Delivery_Boy::deleteorder()
{
    Order temp;
    int flag = 0,flag2=0;
    ifstream is("Orders.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (!is.eof())
    {
        is.read((char*)&temp, sizeof(temp));
        if (temp.getOrderCode() == Working_Order_Code)
        {
            temp.setstatus(delivered);
            flag = 1;
            os.write((char*)&temp, sizeof(temp));
            Delivery_Order = 0;
            continue;
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    is.close();
    os.close();
    remove("Orders.dat");
    rename("temp.dat", "Orders.dat");
    Total_Orders++;
    Working_Order_Code = 0;
    On_Delivery = false; 
    flag2 = updateBoy();
    if (flag == 1 && flag2 == 1) return true;
    else return false;
}
long int Delivery_Boy::getworkingorder() const
{
    return Working_Order_Code;
}
bool Delivery_Boy::check(string id, string p)
{
    int flag = 0;
    ifstream is("Delivery_Boy.dat", ios::binary);
    is.seekg(0);
    while (!is.eof())
    {
        is.read((char*)this, sizeof(*this));
        if (this->getID() == id && this->getPass() == p)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1) return true;
    else return false;
}

int Delivery_Boy::getTotalOrders() const
{
    return Total_Orders;
}
bool Delivery_Boy::updateBoy()
{
    int flag = 0;
    Delivery_Boy temp;
    ifstream is("Delivery_Boy.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (strcmp(temp.getID(), Staff_ID) == 0)
        {
            flag = 1;
            os.write((char*)this, sizeof(*this));
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    is.close();
    os.close();
    remove("Delivery_Boy.dat");
    rename("temp.dat", "Delivery_Boy.dat");
    if (flag == 1) return true;
    else return false;
}
bool Delivery_Boy::getOnDelivery() const
{
    return On_Delivery;
}