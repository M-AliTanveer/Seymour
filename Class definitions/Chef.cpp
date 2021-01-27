#include "Chef.h"
#include <fstream>
chef::chef() :Total_Orders(0), Working(false)
{
    salary = 25000;
    Working_Order_Code = 0;
}

bool chef::setID(string id)
{
    try
    {
        chef C;
        int f = 0;
        ofstream test("chef.dat", ios::out | ios::app);
        test.close();
        ifstream is("chef.dat", ios::binary);
        is.seekg(0);
        bool empty = (is.get(), is.eof());
        if (empty != 1)
        {
            is.seekg(0);
            while (!is.eof())
            {
                is.read((char*)&C, sizeof(C));
                if (C.getID() == id)
                {
                    f = 1;
                    break;
                }
                else continue;
            }
        }
        if (f == 0)
        {
            if (id[0] == 'C' && id[1] == '_')
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


bool chef::addworkingorder()
{
    Order temp;
    int n = 0, flag1 = 0, flag2 = 0;
    ifstream is("Orders.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);

    //pos = (int)fs.tellg();
    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (temp.getstatus() == confirmed && n==0)
        {
            flag1 = 1;
            n++;
            Working_Order_Code = temp.getOrderCode();
            temp.setstatus(making);
            Chefs_Order = temp;
            Working = true;
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
    flag2 = updatechef();
    if (flag1 == 1 && flag2==1) return true;
    else return false;
}

long int chef::getworkingorder() const
{
    return Working_Order_Code;
}

bool chef::setorderready()
{
    Order temp;
    int n = 0, flag1 = 0, flag2 = 0;
    ifstream is("Orders.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);

    while (is.read((char*)&temp, sizeof(temp)))
    {        
        if (temp.getOrderCode() == Working_Order_Code && n==0)
        {
            flag1 = 1;
            n++;
            temp.setstatus(ready_for_delivery);
            Total_Orders++;
            Working_Order_Code = 0;
            Chefs_Order = 0;
            Working = false;
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
    flag2 = updatechef();
    if (flag1 == 1 && flag2 == 1) return true;
    else return false;
}
bool chef::check(string id, string p)
{
    int flag = 0;
    ifstream is("chef.dat", ios::binary);
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
bool chef::cancelorder()
{
    Order temp;
    int flag1 = 0,flag2=0;
    ifstream is("Orders.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);

    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (temp.getOrderCode() == Working_Order_Code)
        {
            flag1 = 1;
            temp.setstatus(canceled);
            Working_Order_Code = 0;
            Chefs_Order = 0;
            Working = false;
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
    flag2 = updatechef();
    if (flag1 == 1 && flag2==1) return true;
    else return false;
}
int chef::getTotalOrders() const
{
    return Total_Orders;
}
Order chef::getcurrOrder() const
{
    return Chefs_Order;
}
bool chef::updatechef()
{
    int flag = 0;
    chef temp;
    ifstream cheff("chef.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    cheff.seekg(0);
    while (cheff.read((char*)&temp, sizeof(temp)))
    {
        if (strcmp(Staff_ID, temp.getID()) == 0)
        {
            flag = 1;
            os.write((char*)this, sizeof(*this));
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    cheff.close();
    os.close();
    remove("chef.dat");
    rename("temp.dat", "chef.dat");
    if (flag == 1) return true;
    else return false;
}
bool chef::getWorking() const
{
    return Working;
}