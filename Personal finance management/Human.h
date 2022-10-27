#pragma once
#include "Main.h"

class Human
{
	string owner;

public:

	Human() = default;
	
	Human(string owner)
	{
		this->owner = owner;
	}

	string getOwner()
	{
		return owner;
	}

	void Greeting()
	{
		cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
			<< endl << setw(86) << "Здравствуйте, " << owner << "!" << endl 
			<< endl << setw(115) << "Выполняется вход в приложение. . . Пожалуйста, подождите. . . ";
	}

	friend ostream& operator <<(ostream& output, Human hum)
	{
		output << hum;
		return output;
	}
};
