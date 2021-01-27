#pragma once
#include <string>
using namespace std;
class secured
{
protected:
	long long int contactno;
	long long int cnic;
	char address[200];
	bool cod;
	char card[15];
	long long int cardno;
	int monthc, yearc;
public:
	secured();
	bool setcontact(long long int);
	long long int getcontact();
	bool setcnic(long long int);
	long long int getcnic();
	void setaddress(string);
	char* getaddress();
	void setpaymentttype(bool);
	bool getpaymenttype()const;
	void setcardprovider(string);
	char* getcardprovider();
	bool setcardno(long long int i = 0);
	long long int getcardno();
	bool setexpiry(int, int);
	int* getexpiry();
	template <typename encrypt>
	encrypt encryption(encrypt);
	template <typename encrypt>
	encrypt decryption(encrypt);
	string encryption(char*);
	char* decryption(char*);
	string encryption(string);
	char* decryption(string);
	
};
