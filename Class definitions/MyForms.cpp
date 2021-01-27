#include "MyForm.h"
#include<ctime>
#include<cstdlib>
#include<fstream>
#define backtostring msclr::interop::marshal_as<std::string>
#define gotoString msclr::interop::marshal_as<String^>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

//******************************USER LOGIN AND RELATED FUNCTIONS**********************
void breeze::MyForm::customerbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = UserLogin;
}

void breeze::MyForm::staff_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Staaf_Main_Page;
}

void breeze::MyForm::PreMade_Enter(System::Object^ sender, System::EventArgs^ e) {
	sizeofpizzabox5->Text = "0";
	sizeofpizzabox4->Text = "0";
	sizeofpizzabox3->Text = "0";
	sizeofpizzabox2->Text = "0";
	sizeofpizzabox->Text = "0";
	sizeofpremadepizzabox->Text = "0";
	pizzaamountbox->Text = "0";
}

void breeze::MyForm::pizzaamountbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Convert::ToInt16(pizzaamountbox->Text) > 0)
		sizeofpremadepizzabox->Text = "0";
}

void breeze::MyForm::startmenubox_Click(System::Object^ sender, System::EventArgs^ e) {

	if(Convert::ToInt32(sizeofpremadepizzabox->Text)>0)
	{
		pizz = new pizza;
		total_no_of_pizzas = 1;
		size = new int;
		*size = Convert::ToInt32(sizeofpremadepizzabox->Text);
		if (fajitablastbox->Checked == true)
		{
			italian* a = new italian;
			a->setherbs(onions);
			a->setcookstyle(oven);
			fajita* b = new fajita;
			b->set_meat("MEXICAN STYLE");
			b->increaseprice(*size);

			Chicken* c = new Chicken;
			pizz->cpoint = a;
			pizz->fpoint = b;
			pizz->tpoint = c;

			pizz->adjustpricing(*size);
			tabControl1->SelectedTab = CheckoutPage;

		}
		else if (chickensupremebox->Checked == true)
		{
			newyork *a = new newyork;
			a->setherbs(garlic);
			a->setmineralized(true);
			bbq_buzz* b = new bbq_buzz;
			b->set_sauce("BBQ SAUCE");
			b->set_chicken(true);
			b->increaseprice(*size);
			Chicken* c = new Chicken;
			c->setCheese(Shredded_Parmesan);
			pizz->cpoint = a;
			pizz->fpoint = b;
			pizz->tpoint = c;

			pizz->adjustpricing(*size);
			tabControl1->SelectedTab = CheckoutPage;

		}
		else if (westsidegarlicbox->Checked == true)
		{
			focacia* a = new focacia;
			a->setherbs(garlicpowder);
			a->setcoating(oliveoil);
			tikka* b = new tikka;
			b->set_beef(true);
			b->increaseprice(*size);

			Mashroom* c = new Mashroom;
			c->setCO(true);
			c->setCRGS(true);
			pizz->cpoint = a;
			pizz->fpoint = b;
			pizz->tpoint = c;

			pizz->adjustpricing(*size);
			tabControl1->SelectedTab = CheckoutPage;

		}
		else if (allcheesebox->Checked == true)
		{
			stuffed* a = new stuffed;
			a->setcheese(american);
			a->setfilling(whole);
			a->setlayer(thincut);
			The_cheese* b = new The_cheese;
			b->set_cheese("GOUDA");
			b->increaseprice(*size);

			Extra_Cheez* c = new Extra_Cheez;
			c->setExtra(Macroni);
			c->setRPF(true);
			pizz->cpoint = a;
			pizz->fpoint = b;
			pizz->tpoint = c;

			pizz->adjustpricing(*size);
			tabControl1->SelectedTab = CheckoutPage;

		}
	}
	else if (Convert::ToInt16(pizzaamountbox->Text) > 0)
	{
		total_no_of_pizzas = Convert::ToInt16(pizzaamountbox->Text);
		loop = 1;
		size = new int[total_no_of_pizzas];
		pizz = new pizza[total_no_of_pizzas];
		int i=0;

		if (Convert::ToInt16(pizzaamountbox->Text) > 4)
		{
			if(Convert::ToInt16(sizeofpizzabox5->Text) != 0)
			{
				i++;
				size[4] = Convert::ToInt16(sizeofpizzabox5->Text);
			}
		}
		if (Convert::ToInt16(pizzaamountbox->Text) > 3)
		{
			if (Convert::ToInt16(sizeofpizzabox4->Text) != 0)
			{
				i++;
				size[3] = Convert::ToInt16(sizeofpizzabox4->Text);
			}
		}
		if (Convert::ToInt16(pizzaamountbox->Text) > 2)
		{
			if (Convert::ToInt16(sizeofpizzabox3->Text) != 0)
			{
				i++;
				size[2] = Convert::ToInt16(sizeofpizzabox3->Text);
			}
		}
		if (Convert::ToInt16(pizzaamountbox->Text) > 1)
		{
			if (Convert::ToInt16(sizeofpizzabox2->Text) != 0)
			{
				i++;
				size[1] = Convert::ToInt16(sizeofpizzabox2->Text);
			}
		}
		if (Convert::ToInt16(pizzaamountbox->Text) > 0)
		{
			if (Convert::ToInt16(sizeofpizzabox->Text) != 0)
			{
				i++;
				size[0] = Convert::ToInt16(sizeofpizzabox->Text);
			}
		}
		if (i != Convert::ToInt16(pizzaamountbox->Text))
		{
			sizereq->Visible = true;
		}
		else
		{
			tabControl1->SelectedTab = CrustSelect;
			Crustheading->Text = Crustheading->Text + Convert::ToString(total_no_of_pizzas);
		}
	}
	else
	{
		pizzareq->Visible = true;
	}
}

void breeze::MyForm::sizeofpremadepizzabox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Convert::ToInt16(sizeofpremadepizzabox->Text) > 0)
		pizzaamountbox->SelectedIndex = pizzaamountbox->FindString("0");
}

void breeze::MyForm::Previous_Enter(System::Object^ sender, System::EventArgs^ e) {
	prevorder1->Text = "";
	prevorder2->Text = "";
	prevorder3->Text = "";
	prevorder4->Text = "";
	prevorder5->Text = "";
	labelusername->Text = "Name: " + gotoString(acc->getname());
	labeluserfname->Text = "Father Name: " + gotoString(acc->getF_Name());
	labelusercontactno->Text = "Contact No: " + Convert::ToString(acc->getcontact());
	labeluserusername->Text = "Username: " + gotoString(acc->getusername());
	labeluseremail->Text = "Email: " + gotoString(acc->getemail());
	labelusertotalamount->Text = "Amount Spent: " + Convert::ToString(acc->gettotalamount());
	Order* ord = acc->getprevious();
	if ((ord + 0)->ReturnBill() == 0)
		prevorder1->Enabled = false;
	else
		prevorder1->Enabled = true;
	if ((ord + 1)->ReturnBill() == 0)
		prevorder2->Enabled = false;
	else
		prevorder2->Enabled = true;
	if ((ord + 2)->ReturnBill() == 0)
		prevorder3->Enabled = false;
	else
		prevorder3->Enabled = true;
	if ((ord + 3)->ReturnBill() == 0)
		prevorder4->Enabled = false;
	else
		prevorder4->Enabled = true;
	if ((ord + 4)->ReturnBill() == 0)
		prevorder5->Enabled = false;
	else
		prevorder5->Enabled = true;
	int i = 0, j;
	for (j = 0; j < ord[i].getpizzas(); j++)
	{
		prevorder1->Text = prevorder1->Text + "Crust: " + gotoString(ord[i].getcrusts() + j * 30) + " + " + "Flavor: " + gotoString(ord[i].getflavs() + j * 30) + " + " + "Topping: " + gotoString(ord[i].gettoppings() + j * 30) + Environment::NewLine;
	}
	prevorder1->Text = prevorder1->Text + Environment::NewLine + "Rs " +Convert::ToString(ord[i].ReturnBill());
	i++;
	for (j = 0; j < ord[i].getpizzas(); j++)
	{
		prevorder2->Text = prevorder2->Text + "Crust: " + gotoString(ord[i].getcrusts() + j * 30) + " + " + "Flavor: " + gotoString(ord[i].getflavs() + j * 30) + " + " + "Topping: " + gotoString(ord[i].gettoppings() + j * 30) + Environment::NewLine;
	}
	prevorder2->Text = prevorder2->Text + Environment::NewLine + "Rs " +Convert::ToString(ord[i].ReturnBill());
	i++;
	for (j = 0; j < ord[i].getpizzas(); j++)
	{
		prevorder3->Text = prevorder3->Text + "Crust: " + gotoString(ord[i].getcrusts() + j * 30) + " + " + "Flavor: " + gotoString(ord[i].getflavs() + j * 30) + " + " + "Topping: " + gotoString(ord[i].gettoppings() + j * 30) + Environment::NewLine;
	}
	prevorder3->Text = prevorder3->Text + Environment::NewLine + "Rs " +Convert::ToString(ord[i].ReturnBill());
	i++;
	for (j = 0; j < ord[i].getpizzas(); j++)
	{
		prevorder4->Text = prevorder4->Text + "Crust: " + gotoString(ord[i].getcrusts() + j * 30) + " + " + "Flavor: " + gotoString(ord[i].getflavs() + j * 30) + " + " + "Topping: " + gotoString(ord[i].gettoppings() + j * 30) + Environment::NewLine;
	}
	prevorder4->Text = prevorder4->Text + Environment::NewLine + "Rs " +Convert::ToString(ord[i].ReturnBill());
	i++;
	for (j = 0; j < ord[i].getpizzas(); j++)
	{
		prevorder5->Text = prevorder5->Text + "Crust: " + gotoString(ord[i].getcrusts() + j * 30) + " + " + "Flavor: " + gotoString(ord[i].getflavs() + j * 30) + " + " + "Topping: " + gotoString(ord[i].gettoppings() + j * 30) + Environment::NewLine;
	}
	prevorder5->Text = prevorder5->Text + Environment::NewLine + "Rs " +Convert::ToString(ord[i].ReturnBill());
}

void breeze::MyForm::prevorder1_CheckedChanged(System::Object^ sender, System::EventArgs^ e){
	if (prevorder1->Checked == true)
	{
		prevorder2->Checked = false;
		prevorder3->Checked = false;
		prevorder4->Checked = false;
		prevorder5->Checked = false;
	}
}

void breeze::MyForm::prevorder2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (prevorder2->Checked == true)
	{
		prevorder1->Checked = false;
		prevorder3->Checked = false;
		prevorder4->Checked = false;
		prevorder5->Checked = false;
	}
}

void breeze::MyForm::prevorder3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (prevorder3->Checked == true)
	{
		prevorder1->Checked = false;
		prevorder2->Checked = false;
		prevorder4->Checked = false;
		prevorder5->Checked = false;
	}

}

void breeze::MyForm::prevorder4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (prevorder4->Checked == true)
	{
		prevorder1->Checked = false;
		prevorder2->Checked = false;
		prevorder3->Checked = false;
		prevorder5->Checked = false;
	}
}

void breeze::MyForm::prevorder5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (prevorder5->Checked == true)
	{
		prevorder1->Checked = false;
		prevorder2->Checked = false;
		prevorder3->Checked = false;
		prevorder4->Checked = false;
	}
}

void breeze::MyForm::tomenu_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = PreMade;
}

void breeze::MyForm::confirmorder_Click(System::Object^ sender, System::EventArgs^ e) {
	if (prevorder1->Checked == true || prevorder2->Checked == true || prevorder3->Checked == true || prevorder4->Checked == true || prevorder5->Checked == true)
	{
		int j;
		prevorder1->Checked == true ? (j = 0) : (prevorder2->Checked == true ? (j = 1) : (prevorder3->Checked == true ? (j = 2) : (prevorder4->Checked == true ? (j = 3) : (prevorder5->Checked == true ? (j = 4) : (0)))));
		Order* ord = acc->getprevious();
		total_no_of_pizzas = ord[j].getpizzas();
		size = new int[total_no_of_pizzas];
		size = ord[j].getsize();
		pizz = new pizza[total_no_of_pizzas];
		for (int i = 0; i < total_no_of_pizzas; i++,pizz = pizz +1)
		{
			//crust
			if (!strcmp((ord[j].getcrusts() + i * 30),"DeepDish"))
			{
				pizz->cpoint = new deepdish;
			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Focacia"))
			{
				pizz->cpoint = new focacia;

			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Italian"))
			{
				pizz->cpoint = new italian;

			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Neapolitan"))
			{
				pizz->cpoint = new neapolitan;

			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Newyork"))
			{
				pizz->cpoint = new newyork;
			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Sicilian"))
			{
				pizz->cpoint = new sicilian;
			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Stlouis"))
			{
				pizz->cpoint = new stlouis;

			}
			else if (!strcmp((ord[j].getcrusts() + i * 30),"Stuffed"))
			{
				pizz->cpoint = new stuffed;
			}
			//flavour
			if (!strcmp((ord[j].getflavs() + i * 30),"BBQ buzz"))
			{
				pizz->fpoint = new bbq_buzz;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30),"chilli delight"))
			{
				pizz->fpoint = new chilli_delight;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30), "fajita"))
			{
				pizz->fpoint = new fajita;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30) , "seekh kebab"))
			{
				pizz->fpoint = new seekh_kebab;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30) , "The cheese"))
			{
				pizz->fpoint = new The_cheese;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30) , "tikka"))
			{
				pizz->fpoint = new tikka;
			}
			else if (!strcmp((ord[j].getflavs() + i * 30) , "Veggie Delight"))
			{
				pizz->fpoint = new veggie_delight;
			}
			pizz->fpoint->increaseprice(size[i]);
			//topping
			if (!strcmp((ord[j].gettoppings() + i * 30), "Beef"))
			{
				pizz->tpoint = new Beef;
			}
			else if (!strcmp((ord[j].gettoppings() + i * 30), "Chicken"))
			{
				Chicken* a = new Chicken;
				pizz->tpoint = a;
			}
			else if (!strcmp((ord[j].gettoppings() + i * 30), "Extra_Cheez"))
			{
				pizz->tpoint = new Extra_Cheez;
			}
			else if (!strcmp((ord[j].gettoppings() + i * 30), "Mashroom"))
			{
				pizz->tpoint = new Mashroom;
			}
			else if (!strcmp((ord[j].gettoppings() + i * 30), "Pepperoni"))
			{
				pizz->tpoint = new Pepperoni;
			}
			else if (!strcmp((ord[j].gettoppings() + i * 30), "Sausage"))
			{
				pizz->tpoint = new Sausage;
			}
			pizz->adjustpricing(size[i]);
		}
		pizz = pizz - 1;

		tabControl1->SelectedTab = CheckoutPage;

	}
	else
	err->Visible = true;

}

void breeze::MyForm::backtomain_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = MainMenu;
}

//******************************USER LOGIN AND RELATED FUNCTIONS**********************



//******************************SIGNUP RELATED FUNCTIONS*****************************
void breeze::MyForm::backtologinbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = UserLogin;
}

void breeze::MyForm::GuesetOrderButton_Click(System::Object^ sender, System::EventArgs^ e) {
	acc->setguest(true);
	tabControl1->SelectedTab = PreMade;
}

void breeze::MyForm::Login_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!acc->import(backtostring(UsernameBox->Text), backtostring(PasswordBox->Text)))
	{
		incorrect->Visible = true;
	}
	else if(acc->import(backtostring(UsernameBox->Text), backtostring(PasswordBox->Text))==true)
	{
		acc->import(backtostring(UsernameBox->Text), backtostring(PasswordBox->Text));
		tabControl1->SelectedTab = Previous;
		UsernameBox->Text = "";
		PasswordBox->Text = "";
	}

	//function incomplete
}

void breeze::MyForm::Signup_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = SignUpPage;
}

void breeze::MyForm::signup2_Click(System::Object^ sender, System::EventArgs^ e) {
	using namespace System;
	int i = 0;
	if (!acc->setname(backtostring(Namebox->Text)))
	{
		namereq->Visible = true;
		Namebox->Text = Convert::ToString("0");
		i++;
	}

	if (!acc->setF_Name(backtostring(FNamebox->Text)))
	{
		fnamereq->Visible = true;
		FNamebox->Text = Convert::ToString("0");
		i++;
	}
	try {
		if (!acc->setage(Convert::ToInt32(agebox->Text)))
		{
			agebox->Text = Convert::ToString("0");
			i++;
		}
	}
	catch (FormatException ^os)
	{
		os;
		agebox->Text = "0";
		i++;
	}
	string gen = backtostring(genderbox->Text);
	if (gen == "Male")
		acc->setGender(Male);
	else if (gen == "Female")
		acc->setGender(Female);
	else if (gen == "Other")
		acc->setGender(Other);
	try
	{
		if (!acc->setcontact(long long int(Convert::ToInt64(contactbox->Text))))
		{
			contactbox->Text = Convert::ToString("0");
		}

		if (!acc->setcnic(long long int(Convert::ToInt64(cnicbox->Text))))
		{
			cnicbox->Text = Convert::ToString("0");
		}
	}
	catch (FormatException^ os)
	{
		os;
		contactbox->Text = "0";
		cnicbox->Text = "0";
		i++;
	}

	acc->setaddress(backtostring(addressbox->Text));

	acc->setpaymentttype(codcheckbox->Checked);

	if (codcheckbox->Checked == false && cardcheckbox->Checked == false)
	{
		codlabel->Visible = true;
		i++;
	}

	acc->setcardprovider(backtostring(cardproviderbox->Text));
	try
	{
		if (!acc->setcardno(long long int(Convert::ToInt64(cardnobox->Text))))
		{
			cardnobox->Text = Convert::ToString("0");
			i++;
		}

		if (!acc->setexpiry(Convert::ToInt32(cardexpmonth->Text), Convert::ToInt32(cardexpyear->Text)))
		{
			expreq->Visible = true;
			cardexpmonth->Text = Convert::ToString("0");
			cardexpyear->Text = Convert::ToString("0");
			i++;
		}
	}
	catch (FormatException^ os)
	{
		os;
		cardnobox->Text = "0";
		cardexpmonth->Text = Convert::ToString("0");
		cardexpyear->Text = Convert::ToString("0");
		i++;
	}

	if (!acc->setemail(backtostring(emailbox->Text)))
	{
		emailreq->Visible = true;
		emailbox->Text = Convert::ToString("0");
		i++;
	}

	if (!acc->setusername(backtostring(usernamebox2->Text)))
	{
		usernamereq2->Visible = true;
		usernamebox2->Text = Convert::ToString("0");
		i++;
	}

	if (!acc->setpassword(backtostring(passwordbox2->Text)))
	{
		passwordbox2->Text = Convert::ToString("0");
		i++;
	}

	if (i == 0)
	{
		acc->writetofile();
		tabControl1->SelectedTab = PreMade;
	}

	else if (i > 0)
	{
		errorlabel->Visible = true;
	}
}

void breeze::MyForm::codcheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (codcheckbox->Checked == true)
	{
		cardcheckbox->Checked = false;
		cardproviderbox->Enabled = false;
		cardnobox->Enabled = false;
		cardnobox->Text = "0";
		cardexpmonth->Enabled = false;
		cardexpmonth->Text = "0";
		cardexpyear->Enabled = false;
		cardexpyear->Text = "0";

	}
}

void breeze::MyForm::cardcheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (cardcheckbox->Checked == true)
	{
		codcheckbox->Checked = false;
		cardproviderbox->Enabled = true;
		cardnobox->Enabled = true;
		cardexpmonth->Enabled = true;
		cardexpyear->Enabled = true;
	}
}

void breeze::MyForm::usernameavailability_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (acc->checkavailable(backtostring(usernamebox2->Text)))
	{
		availablelabel->Visible = true;
		notavailablelabel->Visible = false;
	}
	else
	{
		notavailablelabel->Visible = true;
		availablelabel->Visible = false;
	}

}



//******************************SIGNUP RELATED FUNCTIONS*****************************


//******************************CRUST SELECTION FUNCTIONS*****************************
void breeze::MyForm::CrustSelect_Enter(System::Object^ sender, System::EventArgs^ e) {
	pizz->cpoint = new italian;
	italiancheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new neapolitan;
	neapolitancheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new newyork;
	newyorkcheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new stlouis;
	stlouischeckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new deepdish;
	deepdishcheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new sicilian;
	siciliancheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new focacia;
	focaciacheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
	pizz->cpoint = new stuffed;
	stuffedcheckbox->Text = gotoString(pizz->cpoint->get_description());
	delete pizz->cpoint;
}

void breeze::MyForm::toflavormenu_Click(System::Object^ sender, System::EventArgs^ e) {
	
	TikkaCheckbox->Checked = false;
	FajitaCheckbox->Checked = false;
	BbqBuzzCheckbox->Checked = false;
	ChilliDelightCheckbox->Checked = false;
	VeggieDelightCheckBox->Checked = false;
	SeekhKebabCheckbox->Checked = false;
	TheCheeseCheckbox->Checked = false;
	if (italiancheckbox->Checked == true)
	{
		italian *a = new italian;
		if (backtostring(italianherbbox->Text) == "None")
			a->setherbs(none);
		else if (backtostring(italianherbbox->Text) == "Onions")
			a->setherbs(onions);
		else if (backtostring(italianherbbox->Text) == "Garlic")
			a->setherbs(garlic);
		if (backtostring(italiancookstylebox->Text) == "Pan")
			a->setcookstyle(pan);
		else if (backtostring(italiancookstylebox->Text) == "Wood Fire")
			a->setcookstyle(wood_fired);
		else if (backtostring(italiancookstylebox->Text) == "Oven")
			a->setcookstyle(oven);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (neapolitancheckbox->Checked == true)
	{
		neapolitan* a = new neapolitan;
		if (neapolitanhand->Checked == true)
			a->sethand(true);
		if (backtostring(italiancookstylebox->Text) == "Pan")
			a->setcookstyle(pan);
		else if (backtostring(italiancookstylebox->Text) == "Wood Fire")
			a->setcookstyle(wood_fired);
		else if (backtostring(italiancookstylebox->Text) == "Oven")
			a->setcookstyle(oven);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (newyorkcheckbox->Checked == true)
	{
		newyork* a = new newyork;
		if (newyorkmineral->Checked == true)
			a->setmineralized(true);
		if (backtostring(newyorkherbbox->Text) == "None")
			a->setherbs(none);
		else if (backtostring(newyorkherbbox->Text) == "Onions")
			a->setherbs(onions);
		else if (backtostring(newyorkherbbox->Text) == "Garlic")
			a->setherbs(garlic);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (stlouischeckbox->Checked == true)
	{
		stlouis* a = new stlouis;
		if (stlouiscutbox->Checked == false)
			a->settavern(false);
		if (stlouischeesebox->Checked == true)
			a->setcheese(true);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (deepdishcheckbox->Checked == true)
	{
		deepdish* a = new deepdish;
		if (backtostring(deepdishthicknessbox->Text) == "Two ``")
			a->setthick(two);
		else if (backtostring(deepdishthicknessbox->Text) == "Two and a half ``")
			a->setthick(twohalf);
		else if (backtostring(deepdishthicknessbox->Text) == "Three ``")
			a->setthick(three);
		if (backtostring(deepdishsaucebox->Text) == "Ketchup")
			a->setsauce(ketchup);
		else if (backtostring(deepdishsaucebox->Text) == "Chilli")
			a->setsauce(chilli);
		else if (backtostring(deepdishsaucebox->Text) == "Special Sauce")
			a->setsauce(special);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (focaciacheckbox->Checked == true)
	{
		focacia* a = new focacia;
		if (backtostring(focaciaherbbox->Text) == "Onions")
			a->setherbs(onions);
		else if (backtostring(focaciaherbbox->Text) == "Garlic")
			a->setherbs(garlic);
		else if (backtostring(focaciaherbbox->Text) == "Scallion")
			a->setherbs(scallion);
		else if (backtostring(focaciaherbbox->Text) == "Garlic Powder")
			a->setherbs(garlicpowder);
		if (backtostring(focaciaoilbox->Text) == "Olive Oil")
			a->setcoating(oliveoil);
		else if (backtostring(focaciaoilbox->Text) == "Scented Oil")
			a->setcoating(scentedoil);
		else if (backtostring(focaciaoilbox->Text) == "Flavored Oil")
			a->setcoating(flavoured);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (siciliancheckbox->Checked == true)
	{
		sicilian* a = new sicilian;
		if (backtostring(sicilianpanbox->Text) == "Standard")
			a->setpan(standard);
		else if (backtostring(sicilianpanbox->Text) == "Deep")
			a->setpan(deep);
		else if (backtostring(sicilianpanbox->Text) == "High Temp")
			a->setpan(hightemp);
		if (backtostring(sicilianoilbox->Text) == "Olive")
			a->setoil(olive);
		else if (backtostring(sicilianoilbox->Text) == "Canola")
			a->setoil(canola);
		else if (backtostring(sicilianoilbox->Text) == "Flavored")
			a->setoil(flavored);
		else if (backtostring(sicilianoilbox->Text) == "Cooking")
			a->setoil(cooking);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else if (stuffedcheckbox->Checked == true)
	{
		stuffed* a = new stuffed;
		if (backtostring(stuffedcheezebox->Text) == "Cheddar")
			a->setcheese(cheddar);
		else if (backtostring(stuffedcheezebox->Text) == "American")
			a->setcheese(american);
		else if (backtostring(stuffedcheezebox->Text) == "Mozerralla")
			a->setcheese(mozeralla);
		if (backtostring(stuffedfillingbox->Text) == "Edge")
			a->setfilling(edge);
		else if (backtostring(stuffedfillingbox->Text) == "Base")
			a->setfilling(base);
		else if (backtostring(stuffedfillingbox->Text) == "Whole")
			a->setfilling(whole);
		if (backtostring(stuffedlayeringbox->Text) == "Single")
			a->setlayer(single);
		else if (backtostring(stuffedcheezebox->Text) == "Thincut")
			a->setlayer(thincut);
		else if (backtostring(stuffedcheezebox->Text) == "Double")
			a->setlayer(doubled);
		pizz->cpoint = a;
		tabControl1->SelectedTab = FlavourSelect;
	}
	else
	{
	crustreq->Visible = true;
	}
	italiancheckbox->Checked = false;
	neapolitancheckbox->Checked = false;
	newyorkcheckbox->Checked = false;
	stlouischeckbox->Checked = false;
	deepdishcheckbox->Checked = false;
	focaciacheckbox->Checked = false;
	siciliancheckbox->Checked = false;
	stuffedcheckbox->Checked = false;
}

void breeze::MyForm::italiancheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (italiancheckbox->Checked == true)
	{
		italiancooklabel->Visible = true;
		italiancookstylebox->Visible = true;
		italianherbbox->Visible = true;
		italianherblabel->Visible = true;

		stuffedcheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		italian* a = new italian;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (italiancheckbox->Checked == false)
	{
		italiancooklabel->Visible = false;
		italiancookstylebox->Visible = false;
		italianherbbox->Visible = false;
		italianherblabel->Visible = false;
	}
}

void breeze::MyForm::neapolitancheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (neapolitancheckbox->Checked == true)
	{
		neapolitanhand->Visible = true;
		neapolitancooklabel->Visible = true;
		neapolitancookstylebox->Visible = true;

		italiancheckbox->Checked = false;
		stuffedcheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		neapolitan* a = new neapolitan;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (neapolitancheckbox->Checked == false)
	{
		neapolitanhand->Visible = false;
		neapolitancooklabel->Visible = false;
		neapolitancookstylebox->Visible = false;
	}
}

void breeze::MyForm::newyorkcheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (newyorkcheckbox->Checked == true)
	{
		newyorkherblabel->Visible = true;
		newyorkherbbox->Visible = true;
		newyorkmineral->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		stuffedcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		newyork* a = new newyork;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (newyorkcheckbox->Checked == false)
	{
		newyorkherblabel->Visible = false;
		newyorkherbbox->Visible = false;
		newyorkmineral->Visible = false;
	}
}

void breeze::MyForm::stlouischeckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (stlouischeckbox->Checked == true)
	{
		stlouischeesebox->Visible = true;
		stlouiscutbox->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stuffedcheckbox->Checked = false;
		focaciacheckbox->Checked = false;

		stlouis* a = new stlouis;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (stlouischeckbox->Checked == false)
	{
		stlouischeesebox->Visible = false;
		stlouiscutbox->Visible = false;
	}
}

void breeze::MyForm::deepdishcheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (deepdishcheckbox->Checked == true)
	{
		deepdishsaucelabel->Visible = true;
		deepdishsaucebox->Visible = true;
		deepdishthicknessbox->Visible = true;
		deepdishthicknesslabel->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		stuffedcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		deepdish* a = new deepdish;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (deepdishcheckbox->Checked == false)
	{
		deepdishsaucelabel->Visible = false;
		deepdishsaucebox->Visible = false;
		deepdishthicknessbox->Visible = false;
		deepdishthicknesslabel->Visible = false;
	}
}

void breeze::MyForm::focaciacheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (focaciacheckbox->Checked == true)
	{
		focaciaherbbox->Visible = true;
		focaciaherblabel->Visible = true;
		focaciaoilbox->Visible = true;
		focaciaoillabel->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		stuffedcheckbox->Checked = false;

		focacia* a = new focacia;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (focaciacheckbox->Checked == false)
	{
		focaciaherbbox->Visible = false;
		focaciaherblabel->Visible = false;
		focaciaoilbox->Visible = false;
		focaciaoillabel->Visible = false;
	}
}

void breeze::MyForm::siciliancheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (siciliancheckbox->Checked == true)
	{
		sicilianoilbox->Visible = true;
		sicilianoillabel->Visible = true;
		sicilianpanbox->Visible = true;
		sicilianpanlabel->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		stuffedcheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		sicilian* a = new sicilian;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;
	}
	if (siciliancheckbox->Checked == false)
	{
		sicilianoilbox->Visible = false;
		sicilianoillabel->Visible = false;
		sicilianpanbox->Visible = false;
		sicilianpanlabel->Visible = false;
	}
}

void breeze::MyForm::stuffedcheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {

	if (stuffedcheckbox->Checked == true)
	{
		stuffedcheezebox->Visible = true;
		stuffedcheeselbel->Visible = true;
		stuffedfillingbox->Visible = true;
		stuffedfillinglabel->Visible = true;
		stuffedlayeringbox->Visible = true;
		stuffedlayerlabel->Visible = true;

		italiancheckbox->Checked = false;
		neapolitancheckbox->Checked = false;
		siciliancheckbox->Checked = false;
		newyorkcheckbox->Checked = false;
		deepdishcheckbox->Checked = false;
		stlouischeckbox->Checked = false;
		focaciacheckbox->Checked = false;

		stuffed* a = new stuffed;
		a->setsize(size[loop - 1]);
		crustpricebox->Text = "CURRENT PRICE \n= Rs " + Convert::ToString(a->get_price());
		delete a;

	}
	if (stuffedcheckbox->Checked == false)
	{
		stuffedcheezebox->Visible = false;
		stuffedcheeselbel->Visible = false;
		stuffedfillingbox->Visible = false;
		stuffedfillinglabel->Visible = false;
		stuffedlayeringbox->Visible = false;
		stuffedlayerlabel->Visible = false;
	}
}

//******************************CRUST SELECTION FUNCTIONS*****************************




//*****************************FLAVOUR SELECTION OPTIONS****************************//
void breeze::MyForm::MovetoToping_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (TikkaCheckbox->Checked == false && FajitaCheckbox->Checked == false && BbqBuzzCheckbox->Checked == false && ChilliDelightCheckbox->Checked == false && VeggieDelightCheckBox->Checked == false && SeekhKebabCheckbox->Checked == false && TheCheeseCheckbox->Checked == false)
	{
		FlavourWarningLabel->Visible = true;
	}
	else if(TikkaCheckbox->Checked == true || FajitaCheckbox->Checked == true || BbqBuzzCheckbox->Checked == true || ChilliDelightCheckbox->Checked == true || VeggieDelightCheckBox->Checked == true || SeekhKebabCheckbox->Checked == true || TheCheeseCheckbox->Checked == true)
	{
		tabControl1->SelectedTab = ToppingSelect;
	}
	
	
}
void breeze::MyForm::VeggieDelightCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (VeggieDelightCheckBox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new veggie_delight;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price()+pizz->fpoint->get_price()));
		TheCheeseCheckbox->Checked = false;
		FajitaCheckbox->Checked = false;
		TikkaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;
	}
	else if (VeggieDelightCheckBox->Checked == false)
	{	
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
	
	
}
void breeze::MyForm::TheCheeseCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TheCheeseCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new The_cheese;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		FajitaCheckbox->Checked = false;
		TikkaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = true;
		TheCheeseMisc2->Visible = true;
		TheCheeseMisc3->Visible = true;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;
	}
	else if (TheCheeseCheckbox->Checked == false)
	{
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		TheCheeseMisc3->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::SeekhKebabCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (SeekhKebabCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new seekh_kebab;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		FajitaCheckbox->Checked = false;
		TikkaCheckbox->Checked = false;
		TheCheeseCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = true;
		SeekhKebabMisc2->Visible = true;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;
	}
	else if (SeekhKebabCheckbox->Checked == false)
	{
		SeekhKebabMisc1->Visible=false;
		SeekhKebabMisc2->Visible = false;
		SeekhKebabMisc1->Checked = false;
		SeekhKebabMisc2->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::TikkaCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TikkaCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new tikka;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		FajitaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		TheCheeseCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		TikkaMisc1->Visible = true;
		TikkaMisc2->Visible = true;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;
	}
	else if (TikkaCheckbox->Checked == false)
	{
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::FajitaCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (FajitaCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new fajita;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		TikkaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		TheCheeseCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = true;
		FajitaMisc2->Visible = true;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;
	}
	else if (FajitaCheckbox->Checked == false)
	{
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::ChilliDelightCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ChilliDelightCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new chilli_delight;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		TikkaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		TheCheeseCheckbox->Checked = false;
		BbqBuzzCheckbox->Checked = false;
		FajitaCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = true;
		ChilliDelightMisc2->Visible = true;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = false;
		BBQBuzzMisc2->Visible = false;

	}	
	else if (ChilliDelightCheckbox->Checked == false)
	{
		ChilliDelightMisc1->Visible =false;
		ChilliDelightMisc2->Visible = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::BbqBuzzCheckbox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (BbqBuzzCheckbox->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		pizz->fpoint = new bbq_buzz;
		pizz->fpoint->increaseprice(size[loop - 1]);
		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		VeggieDelightCheckBox->Checked = false;
		TikkaCheckbox->Checked = false;
		SeekhKebabCheckbox->Checked = false;
		TheCheeseCheckbox->Checked = false;
		ChilliDelightCheckbox->Checked = false;
		FajitaCheckbox->Checked = false;
		TikkaMisc1->Visible = false;
		TikkaMisc2->Visible = false;
		FajitaMisc1->Visible = false;
		FajitaMisc2->Visible = false;
		TheCheeseMisc1->Visible = false;
		TheCheeseMisc2->Visible = false;
		TheCheeseMisc3->Visible = false;
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;
		SeekhKebabMisc1->Visible = false;
		SeekhKebabMisc2->Visible = false;
		BBQBuzzMisc1->Visible = true;
		BBQBuzzMisc2->Visible = true;

	}
	else if (BbqBuzzCheckbox->Checked == false)
	{
		BBQBuzzMisc1->Visible =false;
		BBQBuzzMisc2->Visible =false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		//FlavourPriceBox->Text = "CURRENT PRICE = Rs";
	}
}
void breeze::MyForm::TikkaMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	 if (TikkaMisc1->Checked == true)
	 {
		 FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		 tikka* Tikka = new tikka;
		 Tikka->set_chicken(true);
		 pizz->fpoint = Tikka;
		 Tikka->increaseprice(size[loop - 1]);
		 FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		 TheCheeseMisc3->Checked = false;
		 TheCheeseMisc1->Checked = false;
		 TheCheeseMisc2->Checked = false;
		 SeekhKebabMisc2->Checked = false;
		 ChilliDelightMisc2->Checked = false;
		 FajitaMisc2->Checked = false;
		 FajitaMisc1->Checked = false;
		 TikkaMisc2->Checked = false;
		 BBQBuzzMisc1->Checked = false;
		 SeekhKebabMisc1->Checked = false;
		 BBQBuzzMisc2->Checked = false;
		 ChilliDelightMisc1->Checked = false;

	 }
	 else if(TikkaMisc1->Checked==false)
	 {
		 //FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	 }
 }
void breeze::MyForm::TikkaMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TikkaMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		tikka* Tikka = new tikka;
		Tikka->set_beef(true);
		pizz->fpoint = Tikka;
		Tikka->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));

		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		ChilliDelightMisc2->Checked = false;
		FajitaMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		TikkaMisc1->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;


	}
	else if(TikkaMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::FajitaMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (FajitaMisc1->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		fajita* Fajita = new fajita;
		Fajita->set_meat("mexican style");
		pizz->fpoint = Fajita;
		Fajita->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		ChilliDelightMisc2->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;

	}
	else if(FajitaMisc1->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::FajitaMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (FajitaMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		fajita* Fajita = new fajita;
		Fajita->set_meat("traditional style");
		pizz->fpoint = Fajita;
		Fajita->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		ChilliDelightMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;

	}
	else if(FajitaMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::ChilliDelightMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ChilliDelightMisc1->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		chilli_delight* ChilliDelight = new chilli_delight;
		ChilliDelight->set_chilli("red");
		pizz->fpoint = ChilliDelight;
		ChilliDelight->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc2->Checked = false;

	}
	else if(ChilliDelightMisc1->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::ChilliDelightMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ChilliDelightMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		chilli_delight* ChilliDelight = new chilli_delight;
		ChilliDelight->set_chilli("green");
		pizz->fpoint = ChilliDelight;
		ChilliDelight->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;

	}
	else if(ChilliDelightMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::BBQBuzzMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if(BBQBuzzMisc1->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		bbq_buzz* BBQ_BUZZ = new bbq_buzz;
		BBQ_BUZZ->set_sauce("bbq sauce");
		pizz->fpoint = BBQ_BUZZ;
		BBQ_BUZZ->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc2->Checked = false;
		SeekhKebabMisc1->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;

	}
	else if(BBQBuzzMisc1->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::BBQBuzzMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (BBQBuzzMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		bbq_buzz* BBQ_BUZZ = new bbq_buzz;
		BBQ_BUZZ->set_sauce("ranch sauce");
		pizz->fpoint = BBQ_BUZZ;
		BBQ_BUZZ->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
	}
	else if(BBQBuzzMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::SeekhKebabMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (SeekhKebabMisc1->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		seekh_kebab* SeekhKebab = new seekh_kebab;
		SeekhKebab->set_meat("lamb");
		pizz->fpoint = SeekhKebab;
		SeekhKebab->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc2->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
	}
	else if(SeekhKebabMisc1->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::SeekhKebabMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (SeekhKebabMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		seekh_kebab* SeekhKebab = new seekh_kebab;
		SeekhKebab->set_meat("beef");
		pizz->fpoint = SeekhKebab;
		SeekhKebab->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc2->Checked = false;
		TheCheeseMisc1->Checked = false;
		TheCheeseMisc3->Checked = false;
		SeekhKebabMisc1->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
	}
	else if(SeekhKebabMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::TheCheeseMisc1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TheCheeseMisc1->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		The_cheese* TheCheese = new The_cheese;
		TheCheese->set_cheese("MOZARELLA");
		pizz->fpoint = TheCheese;
		TheCheese->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc2->Checked = false;
		TheCheeseMisc3->Checked = false;
		SeekhKebabMisc1->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
	}
	else if(TheCheeseMisc1->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::TheCheeseMisc2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TheCheeseMisc2->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		The_cheese* TheCheese = new The_cheese;
		TheCheese->set_cheese("gouda");
		pizz->fpoint = TheCheese;
		TheCheese->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc3->Checked = false;
		TheCheeseMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;

	}
	else if(TheCheeseMisc2->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}

}
void breeze::MyForm::TheCheeseMisc3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (TheCheeseMisc3->Checked == true)
	{
		FlavourPriceBox->Text = "CURRENT PRICE = Rs";
		The_cheese* TheCheese = new The_cheese;
		TheCheese->set_cheese("cheddar");
		pizz->fpoint = TheCheese;
		TheCheese->increaseprice(size[loop - 1]);

		FlavourPriceBox->AppendText(Convert::ToString(pizz->cpoint->get_price() + pizz->fpoint->get_price()));
		TheCheeseMisc2->Checked = false;
		TheCheeseMisc1->Checked = false;
		SeekhKebabMisc1->Checked = false;
		SeekhKebabMisc2->Checked = false;
		FajitaMisc1->Checked = false;
		FajitaMisc2->Checked = false;
		TikkaMisc1->Checked = false;
		TikkaMisc2->Checked = false;
		BBQBuzzMisc1->Checked = false;
		BBQBuzzMisc2->Checked = false;
		ChilliDelightMisc1->Checked = false;
		ChilliDelightMisc2->Checked = false;
	}
	else if(TheCheeseMisc3->Checked==false)
	{
		//FlavourPriceBox->Text = "CURRENT PRICE = RS ";
	}
}
void breeze::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	tabControl1->SelectedTab = CrustSelect;
}
void breeze::MyForm::ChilliDelightCheckbox_CheckStateChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ChilliDelightCheckbox->Checked == false)
	{
		ChilliDelightMisc1->Visible = false;
		ChilliDelightMisc2->Visible = false;

	}
}
//*****************************FLAVOUR SELECTION OPTIONS****************************//



//*****************************TOPPING RELATED FUNCTION*****************************//
void breeze::MyForm::ToppingSelect_Enter(System::Object^ sender, System::EventArgs^ e) {
	pizz->tpoint = new Chicken;
	ChickenCheck->Text = "'CHICKEN'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

	pizz->tpoint = new Pepperoni;
	PepperoniCheck->Text = "'PEPPERONI'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

	pizz->tpoint = new Beef;
	BeefCheck->Text = "'BEEF'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

	pizz->tpoint = new Mashroom;
	MashroomCheck->Text = "'MASHROOMS'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

	pizz->tpoint = new Extra_Cheez;
	Extra_CheezCheck->Text = "'EXTRA_CHEESE'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

	pizz->tpoint = new Sausage;
	SausageCheck->Text = "'SAUSAGE'\n" + gotoString(pizz->tpoint->getdetails());
	delete pizz->tpoint;

}
void breeze::MyForm::ChickenCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ChickenCheck->Checked == true)
	{
		CheckBBQ_Sause->Visible = true;
		CheeseLabel->Visible = true;
		ChooseCheeseBox->Visible = true;

		PepperoniCheck->Checked = false;
		BeefCheck->Checked = false;
		MashroomCheck->Checked = false;
		Extra_CheezCheck->Checked = false;
		SausageCheck->Checked = false;
	
		Chicken* C = new Chicken;
		C->increaseprice(size[loop - 1]);

		ToppingPriceBox->Text = "CURRENT PRICE\nRs: " + Convert::ToString(C->getprice()+pizz->cpoint->get_price()+pizz->fpoint->get_price());
		delete C;
	}
	else if (ChickenCheck->Checked == false)
	{
		CheckBBQ_Sause->Visible = false;
		ChooseCheeseBox->Visible = false;
		CheeseLabel->Visible = false;
	}
}
void breeze::MyForm::PepperoniCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (PepperoniCheck->Checked == true)
	{
		TypeLabel->Visible = true;
		ChooseTypeBox->Visible = true;
		QuantityOfCheeseLabel->Visible = true;
		ChooseQuantityOfCheezBox->Visible = true;

		ChickenCheck->Checked = false;
		BeefCheck->Checked = false;
		MashroomCheck->Checked = false;
		Extra_CheezCheck->Checked = false;
		SausageCheck->Checked = false;

		Pepperoni* P = new Pepperoni;
		P->increaseprice(size[loop - 1]);

		ToppingPriceBox->Text = "CURRENT PRICE\nRS: " + Convert::ToString(P->getprice()+pizz->cpoint->get_price()+pizz->fpoint->get_price());
		delete P;
	}
	else if (PepperoniCheck->Checked == false)
	{
		TypeLabel->Visible = false;
		ChooseTypeBox->Visible = false;
		QuantityOfCheeseLabel->Visible = false;
		ChooseQuantityOfCheezBox->Visible = false;
	}
}
void breeze::MyForm::BeefCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (BeefCheck->Checked == true)
	{
		CheckClovesSpice->Visible = true;
		PeppersLabel->Visible = true;
		ChoosePeppersBox->Visible = true;

		ChickenCheck->Checked = false;
		PepperoniCheck->Checked = false;
		MashroomCheck->Checked = false;
		Extra_CheezCheck->Checked = false;
		SausageCheck->Checked = false;

		Beef* B = new Beef;
		B->increaseprice(size[loop - 1]);

		ToppingPriceBox->Text = "CURRENT PRICE\nRS: " + Convert::ToString(B->getprice()+pizz->cpoint->get_price()+pizz->fpoint->get_price());
		delete B;
	}
	else if (BeefCheck->Checked == false)
	{
		CheckClovesSpice->Visible = false;
		PeppersLabel->Visible = false;
		ChoosePeppersBox->Visible = false;
	}
}
void breeze::MyForm::MashroomCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (MashroomCheck->Checked == true)
	{
		CheckCreamlized_Onion->Visible = true;
		CheckCreamyGarlicSause->Visible = true;

		ChickenCheck->Checked = false;
		PepperoniCheck->Checked = false;
		BeefCheck->Checked = false;
		Extra_CheezCheck->Checked = false;
		SausageCheck->Checked = false;

		Mashroom* M = new Mashroom;
		M->increaseprice(size[loop - 1]);

		ToppingPriceBox->Text = "CURRENT PRICE\nRS: " + Convert::ToString(M->getprice()+pizz->cpoint->get_price()+pizz->fpoint->get_price());
		delete M;
	}
	else if (MashroomCheck->Checked == false)
	{
		CheckCreamlized_Onion->Visible = false;
		CheckCreamyGarlicSause->Visible = false;
	}
}
void breeze::MyForm::Extra_CheezCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Extra_CheezCheck->Checked == true)
	{
		CheckRedPepperFlakes->Visible = true;
		ExtraLabel->Visible = true;
		ChooseExtraBox->Visible = true;

		ChickenCheck->Checked = false;
		PepperoniCheck->Checked = false;
		BeefCheck->Checked = false;
		MashroomCheck->Checked = false;
		SausageCheck->Checked = false;

		Extra_Cheez* E = new Extra_Cheez;
		E->increaseprice(size[loop - 1]);
		ToppingPriceBox->Text = "CURRENT PRICE\nRS: " + Convert::ToString(E->getprice()+pizz->cpoint->get_price()+pizz->fpoint->get_price());
		delete E;
	}
	else if (Extra_CheezCheck->Checked == false)
	{
		CheckRedPepperFlakes->Visible = false;
		ExtraLabel->Visible = false;
		ChooseExtraBox->Visible = false;
	}
}
void breeze::MyForm::SausageCheck_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (SausageCheck->Checked == true)
	{
		CheckRedPepperFlakes1->Visible = true;
		CheckBasilScattering->Visible = true;

		ChickenCheck->Checked = false;
		PepperoniCheck->Checked = false;
		BeefCheck->Checked = false;
		MashroomCheck->Checked = false;
		Extra_CheezCheck->Checked = false;

		Sausage* S = new Sausage;
		S->increaseprice(size[loop - 1]);
		ToppingPriceBox->Text = "CURRENT PRICE\nRS: " + Convert::ToString(S->getprice() + pizz->cpoint->get_price() + pizz->fpoint->get_price());
		delete S;
	}
	else
	{
		CheckRedPepperFlakes1->Visible = false;
		CheckBasilScattering->Visible = false;
	}
}
void breeze::MyForm::ProceedToCheckOutButton_Click(System::Object^ sender, System::EventArgs^ e) {

	
	if (ChickenCheck->Checked == true)
	{
		Chicken* C = new Chicken;
		if (CheckBBQ_Sause->Checked == true)
			C->setBS(true);
		else if (CheckBBQ_Sause->Checked == false)
			C->setBS(false);

		if (backtostring(ChooseCheeseBox->Text) == "Shredded_Parmesan")
			C->setCheese(Shredded_Parmesan);
		else if (backtostring(ChooseCheeseBox->Text) == "Shredded_Cheddar")
			C->setCheese(Shredded_Cheddar);
		pizz->tpoint = C;
		
		pizz->adjustpricing(size[loop - 1]);

		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else if (PepperoniCheck->Checked == true)
	{
		Pepperoni* P = new Pepperoni;
		if (backtostring(ChooseTypeBox->Text) == "Vegan")
			P->setType(Vegan);
		else if (backtostring(ChooseTypeBox->Text) == "Non_Vegan")
			P->setType(Non_Vegan);

		if (backtostring(ChooseQuantityOfCheezBox->Text) == "Usual")
			P->setQOFMC(Usual);
		else if (backtostring(ChooseQuantityOfCheezBox->Text) == "More (Extra Charges)")
			P->setQOFMC(More);
		else if (backtostring(ChooseQuantityOfCheezBox->Text) == "Less (Less Charges)")
			P->setQOFMC(Little);
		else if (backtostring(ChooseQuantityOfCheezBox->Text) == "Don't Include (Less Charges)")
			P->setQOFMC(Not_Include);
		pizz->tpoint = P;

		pizz->adjustpricing(size[loop - 1]);
		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
			
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else if (BeefCheck->Checked == true)
	{
		Beef* B = new Beef;
		if (CheckClovesSpice->Checked == true)
			B->setCS(true);
		else if (CheckClovesSpice->Checked == false)
			B->setCS(false);

		if (backtostring(ChoosePeppersBox->Text) == "Green")
			B->setpepper(Green);
		else if (backtostring(ChoosePeppersBox->Text) == "Red")
			B->setpepper(Red);

		pizz->tpoint = B;

		pizz->adjustpricing(size[loop - 1]);
		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
			
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else if (MashroomCheck->Checked == true)
	{
		Mashroom* M = new Mashroom;
		if (CheckCreamlized_Onion->Checked == true)
			M->setCO(true);
		else if (CheckCreamlized_Onion->Checked == false)
			M->setCO(false);

		if (CheckCreamyGarlicSause->Checked == true)
			M->setCRGS(true);
		else if (CheckCreamyGarlicSause->Checked == false)
			M->setCRGS(false);

		pizz->tpoint = M;

		pizz->adjustpricing(size[loop - 1]);
		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
			
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else if (Extra_CheezCheck->Checked == true)
	{
		Extra_Cheez* EC = new Extra_Cheez;
		if (CheckRedPepperFlakes->Checked == true)
			EC->setRPF(true);
		else if (CheckRedPepperFlakes->Checked == false)
			EC->setRPF(false);

		if (backtostring(ChooseExtraBox->Text) == "Macroni")
			EC->setExtra(Macroni);
		else if (backtostring(ChooseExtraBox->Text) == "Cheese (Extra Charges)")
			EC->setExtra(Cheese);



		pizz->tpoint = EC;

		pizz->adjustpricing(size[loop - 1]);
		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
			
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else if (SausageCheck->Checked == true)
	{
		Sausage* S = new Sausage;
		if (CheckRedPepperFlakes->Checked == true)
			S->setRPF(true);
		else if (CheckRedPepperFlakes->Checked == false)
			S->setRPF(false);

		if (CheckBasilScattering->Checked == true)
			S->setBS(true);
		else if (CheckBasilScattering->Checked == false)
			S->setBS(true);


		pizz->tpoint = S;

		pizz->adjustpricing(size[loop - 1]);
		if (loop < total_no_of_pizzas)
		{
			loop++;
			pizz = pizz + 1;
			tabControl1->SelectedTab = CrustSelect;
			
		}
		else
			tabControl1->SelectedTab = CheckoutPage;
	}
	else
	{
		ToppingChooseNotice->Text = "Please Choose One";
		ToppingChooseNotice->Visible = true;
	}
	ChickenCheck->Checked = false;
	PepperoniCheck->Checked = false;
	BeefCheck->Checked = false;
	MashroomCheck->Checked = false;
	Extra_CheezCheck->Checked = false;
	SausageCheck->Checked = false;
	ToppingPriceBox->Text = "";
	crustpricebox->Text = "";
	FlavourPriceBox->Text = "";
	
}
//*****************************TOPPING RELATED FUNCTION*****************************//


//*****************************CHECKOUT RELATED FUNCTIONS***************************//
void breeze::MyForm::CashCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (CashCheckBox->Checked == true)
	{
		CardProviderCheckOutLabel->Visible = false;
		CardCheckOutComboBox->Visible = false;
		CardNumberCheckOutLabel->Visible = false;
		CardNumberCheckOutTextBox->Visible = false;
		CreditCardCheckBox->Checked = false;
	}
}
void breeze::MyForm::CreditCardCheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (CreditCardCheckBox->Checked == true)
	{
		CardProviderCheckOutLabel->Visible = true;
		CardCheckOutComboBox->Visible = true;
		CardNumberCheckOutLabel->Visible = true;
		CardNumberCheckOutTextBox->Visible = true;
		CashCheckBox->Checked = false;
	}
}
void breeze::MyForm::CheckoutPage_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (acc->getguest() == true)
	{
		NameCheckOutText->Text = "";
		AddressCheckOutTextBox->Text = "";
		PhoneNoTextBox->Text = "";
		long int OrderCode;
		UserCheckOutIntro->Visible = false;
		srand(int(time(0)));
		OrderCode = (rand() % 10000) + 1000;
		OrderNoCheckOutTextBox->Text = Convert::ToString(OrderCode);
		int i;
		double price = 0;
		pizz = pizz - (total_no_of_pizzas-1);
		for (i = 0; i < total_no_of_pizzas; i++)
		{
			FlavourCheckOutTextBox->Text = FlavourCheckOutTextBox->Text + "Flavour Number " + (i+1) + ": " + gotoString((pizz + i)->fpoint->get_FlavName()) + Environment::NewLine ;
			CrustCheckOutTextBox->Text = CrustCheckOutTextBox->Text + "Crust Number " + (i + 1) + ": " + gotoString((pizz + i)->cpoint->get_CrustName()) + Environment::NewLine;
			ToppingsCheckOutTextBox->Text = ToppingsCheckOutTextBox->Text + "Topping Number " + (i + 1) + ": " + gotoString((pizz + i)->tpoint->getToppingName()) + Environment::NewLine;
			price = price + (pizz + i)->getprice();
		}
		order->setOrderCode(OrderCode);
		TotalPriceCheckOutTextBox->Text = Convert::ToString(price);
	}
	else if (acc->getguest() == false)
	{
		double price = 0; int i;
		GuestCheckOutIntro->Visible = false;
		srand(int(time(0)));
		long int OrderCode;
		OrderCode = (rand() % 10000) + 1000;
		OrderNoCheckOutTextBox->Text = Convert::ToString(OrderCode);
		order->setOrderCode(OrderCode);
		NameCheckOutText->Text = gotoString(acc->getname());
		AddressCheckOutTextBox->Text = gotoString(acc->getaddress());
		PhoneNoTextBox->Text = Convert::ToString(acc->getcontact());
		PaymentModeCheckOutLabel->Visible = true;
		CardProviderCheckOutLabel->Visible = false;
		CardCheckOutComboBox->Visible = false;
		CardNumberCheckOutLabel->Visible = false;
		CardNumberCheckOutTextBox->Visible = false;
		pizz = pizz - (total_no_of_pizzas-1);
		for (i = 0; i < total_no_of_pizzas; i++)
		{
			
			FlavourCheckOutTextBox->Text = FlavourCheckOutTextBox->Text + "Flavour Number " + (i + 1) + ": " + gotoString((pizz + i)->fpoint->get_FlavName()) + Environment::NewLine;
			CrustCheckOutTextBox->Text = CrustCheckOutTextBox->Text + "Crust Number " + (i + 1) + ": " + gotoString((pizz + i)->cpoint->get_CrustName()) + Environment::NewLine;
			ToppingsCheckOutTextBox->Text = ToppingsCheckOutTextBox->Text + "Topping Number " + (i + 1) + ": " + gotoString((pizz + i)->tpoint->getToppingName()) + Environment::NewLine;
			price = price + (pizz + i)->getprice();
		}
		discbox->Visible = true;
		disclabel->Visible = true;
		double disc = (5 * acc->gettotalamount()) / 100;
		disc > 500 ? (disc = 500) : (1);
		discbox->Text = Convert::ToString(disc);
		order->setbill(price);
		*order - acc->gettotalamount();
		TotalPriceCheckOutTextBox->Text = System::Convert::ToString(order->ReturnBill());
	}
}
void breeze::MyForm::ConfirmCheckOutButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (acc->getguest() == false)
	{
		acc->setaddress(backtostring(AddressCheckOutTextBox->Text));
		ToppingsCheckOutTextBox->Text = "";
		FlavourCheckOutTextBox->Text = "";
		CrustCheckOutTextBox->Text = "";
		*acc + order->ReturnBill();
		order->setsize(size);
		fstream yourorder("Receipt.txt", ios::in | ios::out | ios::app);
		yourorder << "X----------------------------------------------------X" << endl;
		yourorder << "Name: " << acc->getname() <<endl;
		yourorder << "Contact No: 0" << acc->getcontact() <<endl;
		yourorder << "Address: " << acc->getaddress() <<endl <<endl;
		if (CashCheckBox->Checked == true)
		{
			order->setpaymentttype(true);
		}
		else
		{
			order->setpaymentttype(false);
		}
		order->PlaceOrder(pizz,total_no_of_pizzas);
		order->FileOrder();
		acc->setprevious(*order);
		acc->SaveChanges();
		MessageBox::Show("Your Order Has Been Confirmed!\nPlease Note this Order Number For Tracking Purposes. \nOrder Number: " + OrderNoCheckOutTextBox->Text, "Order Confirmed!");
		tabControl1->SelectedTab = UserLogin;
	}
	else
	{

	try{
		if (AddressCheckOutTextBox->Text == ""  )
		{
			AddressCheckOutWarningLabel->Visible = true;
			CheckOutWarningLabel->Visible = true;
		}
		else if (!acc->setcontact(long long int(System::Convert::ToInt64(PhoneNoTextBox->Text))))
		{
			PhoneNoCheckOutWarning->Visible = true;
			CheckOutWarningLabel->Visible = true;
		}
		else if (CreditCardCheckBox->Checked==true && !acc->setcardno(long long int(System::Convert::ToInt64(CardNumberCheckOutTextBox->Text))))
		{
			 CardNoWarningCheckOutLabel->Visible = true;
			 CheckOutWarningLabel->Visible = true;
		}
		else
		{
			acc->setname(backtostring(NameCheckOutText->Text));
			order->setsize(size);
			acc->setaddress(backtostring(AddressCheckOutTextBox->Text));
			order->setaddress(backtostring(AddressCheckOutTextBox->Text));
			if (CashCheckBox->Checked == true)
			{
				acc->setcardprovider(backtostring(CardCheckOutComboBox->Text));
				acc->setcardno(0);
				order->setpaymentttype(true);
			}
			else
			{
				acc->setcardprovider(backtostring(CardCheckOutComboBox->Text));
				order->setpaymentttype(false);
			}
			fstream yourorder("Receipt.txt", ios::in | ios::out | ios::app);
			yourorder << "X----------------------------------------------------X" << endl;
			yourorder << "Name: " << acc->getname() << endl;
			yourorder << "Contact No: 0" << acc->getcontact() << endl;
			yourorder << "Address: " << acc->getaddress() << endl << endl;
			order->PlaceOrder(pizz, total_no_of_pizzas);
			order->setstatus(confirmed);
			order->FileOrder();
			MessageBox::Show("Your Order Has Been Confirmed!\nPlease Note this Order Number For Tracking Purposes. \nOrder Number: " + OrderNoCheckOutTextBox->Text, "Order Confirmed");
			tabControl1->SelectedTab = UserLogin;
			NameCheckOutText->Text = "";
			PhoneNoTextBox->Text = "";
			AddressCheckOutTextBox->Text = "";
			CardNumberCheckOutTextBox->Text = "";
			ToppingsCheckOutTextBox->Text = "";
			FlavourCheckOutTextBox->Text = "";
			CrustCheckOutTextBox->Text = "";
			acc->setguest(false);
		}
	}
	catch (FormatException^ os)
	{
			os;
			PhoneNoCheckOutWarning->Visible = true;
			CheckOutWarningLabel->Visible = true;
			CardNoWarningCheckOutLabel->Visible = true;
			CheckOutWarningLabel->Visible = true;
	}
		
	}

	//tabControl1->SelectedTab = UserLogin;
}
//*****************************CHECKOUT RELATED FUNCTIONS***************************//


//*****************************STAFF RELATED FUNCTIONS***************************//
void breeze::MyForm::BackToFrontpage_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = MainMenu;
}
void breeze::MyForm::BackToStaafMain_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Staaf_Main_Page;
}
void breeze::MyForm::Managermain_Enter(System::Object^ sender, System::EventArgs^ e) {
	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::Add_Chef_Button_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Addnewchef;
}
void breeze::MyForm::addcheffinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	chef* C = new chef;
	int f = 1;
	
	if (!C->setname(backtostring(chefnametextbox->Text)))
	{
		chefnametextbox->Text = Convert::ToString("");
		f--;
	}
	
	if (!C->setF_Name(backtostring(cheffnametextbox->Text)))
	{
		cheffnametextbox->Text = Convert::ToString("");
		f--;
	}
	try {
		if (!C->setage(Convert::ToInt32(chefagetextbox->Text)))
		{
			chefagetextbox->Text = "0";
			f--;
		}
	}
	catch (FormatException^ os)
	{
		os;
		f--;
	}
	if (backtostring(chefgenderbox->Text) == "Male")
	{
		C->setGender(Male);
	}
	else if (backtostring(chefgenderbox->Text) == "Female")
	{
		C->setGender(Female);
	}
	else if (backtostring(chefgenderbox->Text) == "Other")
	{
		C->setGender(Other);
	}
	try {
		C->setsalary(Convert::ToDouble(chefsalerytextbox->Text));
	}
	catch (FormatException^ os)
	{
		os;
		f--;
	}
	if (!C->setID(backtostring(chefidtextbox->Text)))
	{
		chefidtextbox->Text = "";
		chefidnotice->Visible = true;
		f--;
	}
	if (!C->setPass(backtostring(chefpassbox->Text)))
	{
		chefpassbox->Text = "";
		chefpassnotice->Visible = true;
		f--;
	}	
	
	if (f == 1)
	{
		manager->addchef(*C);
		Addchefnotice->Visible = false;
		tabControl1->SelectedTab = Managermain;
	}
	else
	{
		Addchefnotice->Visible = true;
	}
}
void breeze::MyForm::backtomainmenu_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Managermain;
}
void breeze::MyForm::DeliveryBoyMain_Enter_1(System::Object^ sender, System::EventArgs^ e)
{
	Delivery_Boy* DeliveryBoy = new Delivery_Boy;
	DeliveryBoy->check(emp->getID(), emp->getPass());
	DeliveryBoyNameLabel->Text = "WELCOME, MR " + gotoString(DeliveryBoy->getname());
	DeliveryBoySalaryLabel->Text = "SALARY : RS " + Convert::ToString(DeliveryBoy->getsalary());
	ReadyForDeliveryOrdersComboBox->Items->Clear();
	ifstream infile("Orders.dat", ios::binary);
	Order temp;
	for (; infile.read(reinterpret_cast<char*>(&temp), sizeof(temp));)
	{
		if (temp.getstatus() == ready_for_delivery)
		{
			ReadyForDeliveryOrdersComboBox->Items->Add((temp.getOrderCode()));
			
			
		}
	}
	infile.clear();
	infile.seekg(0);
	

}
void breeze::MyForm::ReadyForDelivery_Click(System::Object^ sender, System::EventArgs^ e)
{
	Delivery_Boy* DeliveryBoy = new Delivery_Boy;
	DeliveryBoy->check(emp->getID(), emp->getPass());
	if (DeliveryBoy->Delivery_Order.getstatus() == delivering)
	{
		MessageBox::Show("Order NO : " + DeliveringOrderTextBox->Text + " has been delivered");
		DeliveryBoy->deleteorder();
		ReadyForDelivery->Visible = false;
		DeliveringOrderTextBox->Text = Convert::ToString(DeliveryBoy->getworkingorder());
		ReadyForDeliveryOrdersComboBox->Items->Remove(ReadyForDeliveryOrdersComboBox->SelectedIndex);
		DeliveryBoyAddressTextBox->Text = "";
	}
	
	
}
void breeze::MyForm::DeliveryBoyPickUpOrderButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	int checker = 0;
	ifstream infile("Orders.dat", ios::binary);
	Order temp;
	for (; infile.read(reinterpret_cast<char*>(&temp), sizeof(temp));)
	{
		if (temp.getstatus() == ready_for_delivery)
		{
			checker++;

		}
	}
	if (checker > 0)
	{

		if (DeliveringOrderTextBox->Text == "" || DeliveringOrderTextBox->Text == "0" || DeliveringOrderTextBox->Text == "")
		{
			Delivery_Boy* DeliveryBoy = new Delivery_Boy;
			DeliveryBoy->check(emp->getID(), emp->getPass());
			long int PlaceHolder;
			bool checker;
			PlaceHolder = (long int)(System::Convert::ToInt64(ReadyForDeliveryOrdersComboBox->SelectedItem));
			checker = DeliveryBoy->addworkingorder(PlaceHolder);
			if (checker = true)
			{
				if (DeliveryBoy->Delivery_Order.getpaymenttype() == true)
				{
					DeliveryBoyCashCheckBox->Checked = true;
					DeliveryBoyCardCheckbox->Checked = false;
				}
				else if (DeliveryBoy->Delivery_Order.getpaymenttype() == false)
				{
					DeliveryBoyCashCheckBox->Checked = false;
					DeliveryBoyCardCheckbox->Checked = true;
				}
				DeliveringOrderTextBox->Text = Convert::ToString(DeliveryBoy->getworkingorder());
				DeliveryBoyAddressTextBox->Text = gotoString(DeliveryBoy->Delivery_Order.getaddress());
				ReadyForDelivery->Visible = true;
				MessageBox::Show("Order NO : " + DeliveringOrderTextBox->Text + " has been picked up for delivery");
				delete DeliveryBoy;
			}

		}
		else
		{
			MessageBox::Show("Please deliver the current order before picking up another one ");
		}
	}
	else if (checker == 0)
	{
		MessageBox::Show("There are currently no orders available for pickup");
	}
}
void breeze::MyForm::ReadyForDeliveryOrdersComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ifstream infile("Orders.dat", ios::binary);
	Order temp;
	string placeholder;
	infile.seekg(0);
	for (; infile.read(reinterpret_cast<char*>(&temp), sizeof(temp));)
	{
		if(temp.getOrderCode()== (long long int(System::Convert::ToInt64(ReadyForDeliveryOrdersComboBox->SelectedItem))))
		{
			
			DeliveryBoyAddressTextBox->AppendText(gotoString(temp.getaddress()));
			if (temp.getpaymenttype()==true)
			{
				DeliveryBoyCashCheckBox->Checked = true;
				DeliveryBoyCardCheckbox->Checked = false;
			}
			else if (temp.getpaymenttype() == false)
			{
				DeliveryBoyCashCheckBox->Checked = false;
				DeliveryBoyCardCheckbox->Checked = true;
			}

		}
	}
}

void breeze::MyForm::Chefmain_Enter(System::Object^ sender, System::EventArgs^ e) {
	
	pendingorders->Items->Clear();
	chef* cheff = new chef;
	int i = 0;
	cheff->check(emp->getID(), emp->getPass());
	chefusrenamelabel->Text = "Logged in as: " + gotoString(cheff->getID()) + Environment::NewLine + gotoString(cheff->getname());
	chefordercount->Text = "Cooked Orders: " + Convert::ToString(cheff->getTotalOrders());
	chefsalary->Text = "Salary: Rs " + Convert::ToString(cheff->getsalary());
	if (cheff->Chefs_Order.getpizzas() == 0)
	{
		cancelorderbox->Visible = false;
		cancelorderlabl->Visible = false;
		ifstream ord("Orders.dat", ios::binary);
		Order temp;
		for (; ord.read((char*)&temp, sizeof(temp));)
		{
			if (temp.getstatus() == confirmed)
			{
				pendingorders->Items->Add("Order # " + temp.getOrderCode() + ". " + temp.getpizzas() + " Pizza(s)");
				i++;
			}
		}

		Crustbox->Text = "";
		Flavorbox->Text = "";
		Toppingbox->Text = "";
		ord.clear();
		ord.seekg(0);
		for (; ord.read((char*)&temp, sizeof(temp));)
		{
			if (temp.getstatus() == confirmed)
			{
				int* size = new int[temp.getpizzas()];
				size = temp.getsize();
				for (int i = 0; i < temp.getpizzas(); i++)
				{
					Crustbox->Text = Crustbox->Text + "Crust " + (i + 1) + " " + gotoString((temp.getcrusts() + i * 30)) + " Size: " + Convert::ToString(size[i]) + Environment::NewLine;
					Flavorbox->Text = Flavorbox->Text + "Flavor " + (i + 1) + " " + gotoString((temp.getflavs() + i * 30)) + Environment::NewLine;
					Toppingbox->Text = Toppingbox->Text + "Topping " + (i + 1) + " " + gotoString((temp.gettoppings() + i * 30)) + Environment::NewLine;
				}
				break;
			}
		}
		ord.close();
		cookdonebox->Text = "Start Cooking!";
	}
	else if (cheff->getcurrOrder().getpizzas() != 0)
	{
		cancelorderbox->Visible = true;
		cancelorderlabl->Visible = true;
		Crustbox->Text = "";
		Flavorbox->Text = "";
		Toppingbox->Text = "";
		pendingorders->Items->Clear();
		cheflabelorders->Text = "Following are the details of the order you are cooking: ";
		pendingorders->Items->Add("Order # " + cheff->getcurrOrder().getOrderCode() + ". " + cheff->getcurrOrder().getpizzas() + " Pizza(s)");
		for (int i = 0; i < cheff->getcurrOrder().getpizzas(); i++)
		{
			Crustbox->Text = Crustbox->Text + "Crust " + (i + 1) + " " + gotoString((cheff->getcurrOrder().getcrusts() + i * 30)) + Environment::NewLine;
			Flavorbox->Text = Flavorbox->Text + "Flavor " + (i + 1) + " " + gotoString((cheff->getcurrOrder().getflavs() + i * 30)) + Environment::NewLine;
			Toppingbox->Text = Toppingbox->Text + "Topping " + (i + 1) + " " + gotoString((cheff->getcurrOrder().gettoppings() + i * 30)) + Environment::NewLine;
		}
		cookdonebox->Text = "Order Cooked!";

	}
	delete cheff;
}
void breeze::MyForm::staffloginbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = 1;
	chef* cheff = new chef;
	Delivery_Boy* boy = new Delivery_Boy;
	if (manager->check(backtostring(staffidtextbox->Text), backtostring(staffpasstextbox->Text)))
	{
		i = 0;
		delete boy;
		delete cheff;
		tabControl1->SelectedTab = Managermain;
		IncorrectPassNotice->Visible = false;
		totalordersofdaybox->Text = Convert::ToString(Order::GetTotalOrdersOfDay());
	}
	else if (cheff->check(backtostring(staffidtextbox->Text), backtostring(staffpasstextbox->Text)))
	{
		emp = cheff;
		delete boy;
		i = 0;
		tabControl1->SelectedTab = Chefmain;
		IncorrectPassNotice->Visible = false;
	}
	else if (boy->check(backtostring(staffidtextbox->Text), backtostring(staffpasstextbox->Text)))
	{
		i = 0;
		emp = boy;
		delete cheff;
		
		tabControl1->SelectedTab = DeliveryBoyMain;
		IncorrectPassNotice->Visible = false;
	}
	if (i == 1)
	{
		IncorrectPassNotice->Visible = true;
	}
	staffidtextbox->Text = "";
	staffpasstextbox->Text = "";
}
void breeze::MyForm::cookdonebox_Click(System::Object^ sender, System::EventArgs^ e)
{
	chef* cheff = new chef;
	cheff->check(emp->getID(), emp->getPass());
	if (cheff->getcurrOrder().getpizzas() == 0)
	{
		if (cheff->addworkingorder())
			tabControl1->SelectedTab = Staaf_Main_Page;

			 
	}
	else if (cheff->getcurrOrder().getpizzas() != 0)
	{
		cheff->setorderready();
		tabControl1->SelectedTab = Staaf_Main_Page;
	}
	delete cheff;
}
void breeze::MyForm::AddDBButton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = AddnewDB;
	chefdeletedbox->Visible = false;
	chefdeletetextbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;
	DBdeletedbox->Visible = false;
	DBdeletetextbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;
}
void breeze::MyForm::backtomainbutton1_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Managermain;
}
void breeze::MyForm::addDBfinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	Delivery_Boy* DB=new Delivery_Boy;
	int f = 1;

	if (!DB->setname(backtostring(DBnametextbox->Text)))
	{
		DBnametextbox->Text = Convert::ToString("");
		f--;
	}

	if (!DB->setF_Name(backtostring(DBfnametextbox->Text)))
	{
		DBfnametextbox->Text = Convert::ToString("");
		f--;
	}
	try {
		if (!DB->setage(Convert::ToInt32(DBagetextbox->Text)))
		{
			DBagetextbox->Text = "0";
			f--;
		}
	}
	catch (FormatException^ os)
	{
		os;
		f--;
	}

	if (backtostring(DBgenderbox->Text) == "Male")
	{
		DB->setGender(Male);
	}
	else if (backtostring(DBgenderbox->Text) == "Female")
	{
		DB->setGender(Female);
	}
	else if (backtostring(DBgenderbox->Text) == "Other")
	{
		DB->setGender(Other);
	}
	try {
		DB->setsalary(Convert::ToDouble(DBsalerytextbox->Text));
	}
	catch (FormatException^ os)
	{
		os;
		f--;
	}
	if (!DB->setID(backtostring(DBidtextbox->Text)))
	{
		DBidtextbox->Text = "";
		DBidnotice->Visible = true;
		f--;
	}
	if (!DB->setPass(backtostring(DBpasstextbox->Text)))
	{
		DBpasstextbox->Text = "";
		DBpassnotice->Visible = true;
		f--;
	}

	if (f == 1)
	{
		manager->addDeliveryBoy(*DB);
		Addchefnotice->Visible = false;
		tabControl1->SelectedTab = Managermain;
	}
	else
	{
		DBaddnotice->Visible = true;
	}
}
void breeze::MyForm::Managerlogout_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Staaf_Main_Page;
}
void breeze::MyForm::DeliveryBoyLogOut_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = Staaf_Main_Page;
}
void breeze::MyForm::deletechefbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	chefdeletetextbox->Visible = true;
	chefdeletefinalbutton->Visible = true;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	DBnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::chefdeletefinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!manager->DeleteChef(backtostring(chefdeletetextbox->Text)))
	{
		chefdeleteidnotice->Visible=true;
		chefdeletedbox->Visible=false;
	}
	else
	{
		chefdeletedbox->Visible = true;
		chefdeleteidnotice->Visible = false;
		chefdeletetextbox->Visible = false;
		chefdeletetextbox->Text = "ID";
		chefdeletefinalbutton->Visible = false;
	}
}
void breeze::MyForm::DeleteDBbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	DBdeletetextbox->Visible = true;
	DBdeletefinalbutton->Visible = true;

	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::DBdeletefinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!manager->DeleteDeliveryBoy(backtostring(DBdeletetextbox->Text)))
	{
		DBdeleteidnotice->Visible = true;
		DBdeletedbox->Visible = false;
	}
	else
	{
		DBdeletedbox->Visible = true;
		DBdeleteidnotice->Visible = false;
		DBdeletetextbox->Visible = false;
		DBdeletetextbox->Text = "ID";
		DBdeletefinalbutton->Visible = false;
	}
}
void breeze::MyForm::cancelorderbox_Click(System::Object^ sender, System::EventArgs^ e)
{
	chef* cheff = new chef;
	cheff->check(emp->getID(), emp->getPass());
	cheff->cancelorder();
	delete cheff;
	tabControl1->SelectedTab = Staaf_Main_Page;
}

void breeze::MyForm::Updatechefsalerybutton_Click(System::Object^ sender, System::EventArgs^ e) {
	Updatechefsalerytextbox->Visible = true;
	chefnewsalerytextbox->Visible = true;
	Updatechefsaleryfinalbutton->Visible = true;
	chefnewsalerylabel->Visible = true;

	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	DBnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::Updatechefsaleryfinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (!manager->updatesaleryofchef(backtostring(Updatechefsalerytextbox->Text), Convert::ToDouble(chefnewsalerytextbox->Text)))
		{
			Updatechefsaleryidnotice->Visible = true;
		}
		else
		{
			Updatechefsalerytextbox->Visible = false;
			chefnewsalerytextbox->Visible = false;
			Updatechefsalerytextbox->Text = "ID";
			chefnewsalerytextbox->Text = "0";
			Updatechefsaleryidnotice->Visible = false;
			Updatechefsaleryfinalbutton->Visible = false;
			chefsaleryupdatednotice->Visible = true;
			chefnewsalerylabel->Visible = false;
			
		}
	}
	catch (FormatException^ os)
	{
		os;
		Updatechefsaleryidnotice->Visible = true;
	}
}

void breeze::MyForm::cheflogout_Click(System::Object^ sender, System::EventArgs^ e) {
	delete emp;
	tabControl1->SelectedTab = Staaf_Main_Page;
}
void breeze::MyForm::trackorderbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = 0;
	long order;
	try
	{
		order = Convert::ToInt32(ordernumberbox->Text);
	}
	catch (FormatException^ os)
	{
		os;
		ordernumberbox->Text = "0";
		i = 1;
	}
	Order temp;
	ifstream orderfile("Orders.dat", ios::binary);
	for (; orderfile.read((char*)&temp, sizeof(temp)) ;)
	{
		if (temp.getOrderCode() == order)
		{
			i = 1;
			enum status stat = temp.getstatus();
			switch (stat)
			{
			case confirmed:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nWe will soon start cooking Your Order. It is our top priority to provide you the best customer service!";
				break;
			case making:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nYour Order is currently being cooked in our kitchen with the best care and we will ensure that the best quality is served to you! Estimated Time of Arrival: 45-55 Minutes";
				break;
			case canceled:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nUnfortunately we had to cancel your Order due to shortage of ingredients. Seymour Pizzeria prides itself on its quality and taste. An incomplete pizza can not be cooked. You are welcome to Order again.";
				break;
			case ready_for_delivery:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nYour Order has been Cooked and is awaiting delivery. It will soon be picked up by one of our riders and delivered to your address. Estimated Time of Arrival: 20-30 minutes.";
				break;
			case delivering:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nThe Rider is on his way with your order. The Pizza(s) will arrive hot and cheesy! Estimated Time of arrival: 10-20 minutes.";
				break;
			case delivered:
				trackedinfolabel->Text = "Order Number: " + temp.getOrderCode() + "\nPizza count: " + temp.getpizzas()  + "\nYour Order has been Delivered Already to your Address. WE hope you enjoyed the Order. Seymour Pizzeria will always strive to make you happy! Please Leave any Feedback or Suggestions you have below. Thanks!";
				break;
			default:
				break;
			}
		}
	}
	if (i == 0)
		trackedinfolabel->Text = "No Such Order Exists. Are You Sure You entered the correct Order Number? ";

	orderfile.close();
}
void breeze::MyForm::UpdateDBsalerybutton_Click(System::Object^ sender, System::EventArgs^ e) {
	UpdateDBsalerytextbox->Visible = true;
	DBnewsalerytextbox->Visible = true;
	UpdateDBsaleryfinalbutton->Visible = true;
	DBnewsalerylabel->Visible = true;
	
	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::UpdateDBsaleryfinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		if (!manager->updatesaleryofDB(backtostring(UpdateDBsalerytextbox->Text), Convert::ToDouble(DBnewsalerytextbox->Text)))
		{
			UpdateDBsalerynotice->Visible = true;
		}
		else
		{
			UpdateDBsalerytextbox->Visible = false;
			DBnewsalerytextbox->Visible = false;
			UpdateDBsalerytextbox->Text = "";
			DBnewsalerytextbox->Text = "0";
			UpdateDBsaleryfinalbutton->Visible = false;
			DBsaleryupdatednotice->Visible = true;
			DBnewsalerylabel->Visible = false;
		}
	}
	catch (FormatException^ os)
	{
		os;
		UpdateDBsalerynotice->Visible = true;
	}
}
void breeze::MyForm::TotalOrdersofchefbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	Cheftotalordersidbox->Visible = true;
	cheftotalordersdisplaybox->Visible = true;
	Cheftotalorderslable->Visible = true;
	cheftotalordersdisplayfinalbutton->Visible = true;

	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;

	totalsalestextbox->Visible = false;

}
void breeze::MyForm::DBtotalordersdisplaybutton_Click(System::Object^ sender, System::EventArgs^ e) {
	DBtotalordersidbox->Visible = true;
	DBtotalordersdisplaybox->Visible = true;
	DBdisplayorderslabel->Visible = true;
	DBdisplayordersfinalbutton->Visible = true;

	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	totalsalestextbox->Visible = false;
}
void breeze::MyForm::cheftotalordersdisplayfinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	cheftotalordersdisplaybox->Text = Convert::ToString(manager->TotalOrders_Chef(backtostring(Cheftotalordersidbox->Text)));
}
void breeze::MyForm::DBdisplayordersfinalbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		DBtotalordersdisplaybox->Text = Convert::ToString(manager->TotalOrders_DelvieryBoy (backtostring(DBtotalordersidbox->Text)));
}
void breeze::MyForm::submitfeedbackbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	char feedback[500];
	strcpy_s(feedback, backtostring(feedbackbox->Text).c_str());
	ofstream feedbackfile("Feedback.txt", ios::app);
	feedbackfile << "\n" <<feedback;
	feedbackfile << "\n" << "^";
	feedbackfile.close();
	submittedlabel->Visible = true;
	feedbackbox->Text = "";
}
void breeze::MyForm::Ordertrackingbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = TrackingFeedback;
}
void breeze::MyForm::backtouser_Click(System::Object^ sender, System::EventArgs^ e) {
	tabControl1->SelectedTab = UserLogin;
}
void breeze::MyForm::feedbacklist_Enter(System::Object^ sender, System::EventArgs^ e) {
	ifstream feedbackfile("Feedback.txt");
	static int feedbackcount = 0, pos = 0;
	int i, max;
	feedbackfile.seekg(0, ios::end);
	max = (int)feedbackfile.tellg();
	feedbackfile.seekg(0, ios::beg);
	char feedback[500];
	if (feedbackcount != 0)
		feedbackfile.seekg(pos);
	feedbackfile.get(feedback[0]);
	try{
	for (i = 0; feedback[i] != '^' && feedbackfile.tellg() != max; i++)
	{
		feedbackfile.get(feedback[i + 1]);
	}
	feedback[i] = '\0';
	feedbackcount++;
	pos = (int)feedbackfile.tellg();
	feedbackfile.close();
	string feed = feedback;
	feebackbox2->Text = gotoString(feed);
}
	catch (AccessViolationException^ os)
	{
		os;
		feebackbox2->Text = "NO MORE AVAILABLE!";
	}
}
void breeze::MyForm::Addnewchef_Enter(System::Object^ sender, System::EventArgs^ e) {
	chefnametextbox->Text = "";
	cheffnametextbox->Text = "";
	chefagetextbox->Text = "0";
	chefsalerytextbox->Text = "0";
	chefidtextbox->Text = "";
	chefpassbox->Text = "";
}
void breeze::MyForm::AddnewDB_Enter(System::Object^ sender, System::EventArgs^ e) {
	DBnametextbox->Text = "";
	DBfnametextbox->Text = "";
	DBagetextbox->Text = "0";
	DBsalerytextbox->Text = "0";
	DBidtextbox->Text = "";
	DBpasstextbox->Text = "";
}
void breeze::MyForm::Viewtotalsalesbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	totalsalestextbox->Visible = true;
	totalsalestextbox->Text = Convert::ToString(manager->gettotalsales());

	chefdeletetextbox->Visible = false;
	chefdeletetextbox->Text = "ID";
	chefdeletedbox->Visible = false;
	chefdeleteidnotice->Visible = false;
	chefdeletefinalbutton->Visible = false;

	DBdeletetextbox->Visible = false;
	DBdeletetextbox->Text = "ID";
	DBdeletedbox->Visible = false;
	DBdeleteidnotice->Visible = false;
	DBdeletefinalbutton->Visible = false;

	Updatechefsalerytextbox->Visible = false;
	chefnewsalerytextbox->Visible = false;
	Updatechefsalerytextbox->Text = "ID";
	chefnewsalerytextbox->Text = "0";
	Updatechefsaleryidnotice->Visible = false;
	chefsaleryupdatednotice->Visible = false;
	Updatechefsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	UpdateDBsalerytextbox->Visible = false;
	DBnewsalerytextbox->Visible = false;
	UpdateDBsalerytextbox->Text = "ID";
	DBnewsalerytextbox->Text = "0";
	UpdateDBsalerynotice->Visible = false;
	DBsaleryupdatednotice->Visible = false;
	UpdateDBsaleryfinalbutton->Visible = false;
	chefnewsalerylabel->Visible = false;

	Cheftotalordersidbox->Visible = false;
	Cheftotalordersidbox->Text = "ID";
	cheftotalordersdisplaybox->Visible = false;
	cheftotalordersdisplaybox->Text = "0";
	cheftotalordersdisplayfinalbutton->Visible = false;
	cheftoatlordersnotice->Visible = false;
	Cheftotalorderslable->Visible = false;

	DBtotalordersidbox->Visible = false;
	DBtotalordersidbox->Text = "ID";
	DBtotalordersdisplaybox->Visible = false;
	DBtotalordersdisplaybox->Text = "0";
	DBtotalordersdisplaybox->Visible = false;
	DBdisplayordersnotice->Visible = false;
	DBdisplayorderslabel->Visible = false;
	DBdisplayordersfinalbutton->Visible = false;
}
