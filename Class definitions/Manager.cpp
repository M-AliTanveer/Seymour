#include "Staff.h"
#include "Manager.h"
#include <string.h>
#include <fstream>
#include "customer.h"
Manager::Manager(int a):Staff(a)
{
}


bool Manager::setID(string id)  { return true; }

bool Manager::setPass(string P)  
{
    return true;
}

void Manager::addDeliveryBoy(Delivery_Boy DB) const
{
    ofstream os("Delivery_Boy.dat", ios::app | ios::binary);
    os.write((char*)&DB, sizeof(DB));
    os.close();
}

void Manager::addchef(chef C) const
{

    ofstream os("chef.dat", ios::out | ios::app | ios::binary);
    os.write((char*)&C, sizeof(C));
    os.close();
  
}

double Manager::gettotalsales() const 
{
    double totalsales = 9;
    customer temp;
    ifstream is("accountdata.dat", ios::binary);
    is.seekg(0);
    while (is.read((char*)&temp, sizeof(temp)))
    {
        totalsales = totalsales + temp.gettotalamount();
    }
    is.close();
    return totalsales;
}
bool Manager::check(string, string)
{
    return false;
}

bool Manager::check(string id, string p) const
{
    if(p==Staff_Password && id==Staff_ID)
        return true;
    else
        return false;
}
bool Manager::updatesaleryofchef(string id,double s) const
{
    int flag = 0;
    chef temp;
    ifstream is("chef.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (temp.getID() == id)
        {
            flag = 1;
            temp.setsalary(s);
            os.write((char*)&temp, sizeof(temp));
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    is.close();
    os.close();
    remove("chef.dat");
    rename("temp.dat", "chef.dat");
    if (flag == 1) return true;
    else return false;
}
bool Manager::updatesaleryofDB(string id, double s) const
{
    int flag=0;
    Delivery_Boy temp;
    ifstream is("Delivery_Boy.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (is.read((char*)&temp, sizeof(temp)))
    {
        if (temp.getID() == id)
        {
            flag = 1;
            temp.setsalary(s);
            os.write((char*)&temp, sizeof(temp));
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
int Manager::TotalOrders_Chef(string id) const
{
    chef C;
    int Total_Orders=0;
    ifstream is("chef.dat", ios::binary);
    is.seekg(0);
    while (!is.eof())
    {
        is.read((char*)&C, sizeof(C));
        if (C.getID() == id)
        {
            Total_Orders = C.getTotalOrders();
        }
    }
    return Total_Orders;
}
int Manager::TotalOrders_DelvieryBoy(string id)const
{
    Delivery_Boy DB;
    int Total_Orders=0;
    ifstream is("Delivery_Boy.dat", ios::binary);
    is.seekg(0);
    while (is.read((char*)&DB, sizeof(DB)))
    {
        
        if (DB.getID() == id)
        {
            Total_Orders = DB.getTotalOrders();
        }
    }
    return Total_Orders;
}
bool Manager::DeleteChef(string id)const
{
    chef temp;
    int flag = 0;
    ifstream is("chef.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (!is.eof())
    {
        is.read((char*)&temp, sizeof(temp));
        if (temp.getID() == id && temp.getWorking()==false)
        {
            flag = 1;
            continue;
        }
        else
        {
            os.write((char*)&temp, sizeof(temp));
        }
    }
    is.close();
    os.close();
    remove("chef.dat");
    rename("temp.dat", "chef.dat");
    if (flag == 1) return true;
    else return false;
}
bool Manager::DeleteDeliveryBoy(string id)const
{
    Delivery_Boy temp;
    int flag = 0;
    ifstream is("Delivery_Boy.dat", ios::binary);
    ofstream os("temp.dat", ios::binary);
    is.seekg(0);
    while (!is.eof())
    {
        is.read((char*)&temp, sizeof(temp));
        if (temp.getID() == id && temp.getOnDelivery() == false)
        {
            flag = 1;
            continue;
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

