#pragma once
#include "Main.h"
#include "List.h"

class Cards
{
protected:
	long balance;
	Currency cur;
	string payment;
	int choice_to_print;
public:
	Cards() = default;

	Cards(string payment, Currency cur, long balance)
	{
		this->payment = payment;
		this->cur = cur;
		this->balance = balance;
	}

	virtual void Print() = 0;

	virtual void NewCard() = 0;

	virtual void ToDelete() = 0;
};

class DebitCard : public Cards
{
private:
	List <DebitCard> lst;
protected:	
	int year, month;
	string card_number;
public:
	
	DebitCard() = default;

	DebitCard(string card_number, string payment, Currency cur, long balance, int month, int year): Cards(payment,cur, balance)
	{
		this->payment = payment;
		this->cur = cur;
		this->card_number = card_number;
		this->balance = balance;
		this->year = year;
		this->month = month;		
	}

	virtual void ToDelete() override;
	
	virtual void NewCard() override;

	virtual void Print() override 
	{
		lst.print();
	}

	friend ostream& operator <<(ostream& output, DebitCard lst)
	{
		output << setw(40) << right << "Дебетовая карта"
			<< setw(22) << right << lst. card_number
			<< setw(13) << right << lst.balance
			<< setw(20) << right << "\t"
			<< setw(5) << right << lst.cur
			<< setw(17) << right << lst.payment
			<< setw(14) << right << lst.month << "/" << lst.year << endl;
		return output;
	}
};

class CreditCard : public DebitCard 
{
	long long credit_limit;
	List <CreditCard> lst;
public:
	CreditCard() = default;

	CreditCard(string card_number, string payment, Currency cur, long balance, int month, int year, long long credit_limit): DebitCard(card_number, payment, cur, balance, month, year)
	{
		this->payment = payment;
		this->cur = cur;
		this->card_number = card_number;
		this->balance = balance;
		this->year = year;
		this->month = month;
		this->credit_limit = credit_limit;
	}

	virtual void Print() override
	{
		lst.print();
	}

	virtual void ToDelete() override;

	virtual void NewCard() override;
	
	friend ostream& operator <<(ostream& output, CreditCard lst)
	{
		output << setw(40) << right << "Кредитная карта"
			<< setw(22) << right << lst.card_number
			<< setw(13) << right << lst.balance
			<< setw(15) << right << lst.credit_limit
			<< setw(11) << right << lst.cur
			<< setw(17) << right << lst.payment
			<< setw(14) << right << lst.month << "/" << lst.year << endl;
		return output;
	}
};

class Wallet : public DebitCard
{
	List <Wallet> lst;
public:
	Wallet() = default;

	Wallet(string card_number, Currency cur, long balance, string payment, int month, int year) : DebitCard(card_number, payment, cur, balance, month, year)
	{
		this->cur = cur;
		this->payment = payment;
		this->card_number = card_number;
		this->balance = balance;
		this->month = month;
		this->year = year;
	}

	virtual void Print() override
	{
		lst.print();
	}

	virtual void ToDelete() override;

	virtual void NewCard() override;

	friend ostream& operator <<(ostream& output, Wallet lst)
	{
		output << setw(40) << right << "Эл. кошелёк"
			<< setw(19) << right << lst.card_number
			<< setw(16) << right << lst.balance
			<< setw(20) << right << "\t"
			<< setw(5) << right << lst.cur
			<< setw(17) << right << lst.payment
			<< setw(13) << right << lst.month << "/" << lst.year << endl;
		return output;
	}
};