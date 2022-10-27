#pragma once
#include "Main.h"
#include "Human.h"
#include "List.h"
#include "Finance.h"

class Credit
{
protected:
	string credit_type;
	double percent;
	long long credit_size, loan_balance, pay_per_month;
	int date;
	Currency cur;
public:
	Credit() = default;	

	Credit(string credit_type, double percent, long pay_per_month, long long credit_size, long long loan_balance, int date, Currency cur)
	{
		this->credit_type = credit_type;
		this->percent = percent;
		this->pay_per_month = pay_per_month;
		this->credit_size = credit_size;
		this->loan_balance = loan_balance;
		this->date = date;
		this->cur = cur;
	}
};

class ConsumerCredit : public Credit
{
private:
	List <ConsumerCredit> lst;
protected:
	int currency;
	string choice;

	void Approved(Human* human);

	void Offer(Human* human);

	double rand_percent(double min, double max);

public:
	ConsumerCredit() = default;

	ConsumerCredit(string credit_type, Currency cur, long long credit_size, double percent, long pay_per_month, int date, long long loan_balance):
		Credit(credit_type, percent, pay_per_month, credit_size, loan_balance, date, cur)
	{
		this->credit_type = credit_type;
		this->cur = cur;
		this->credit_size = credit_size;
		this->percent = percent;
		this->pay_per_month = pay_per_month;
		this->date = date;
		this->loan_balance = loan_balance;
	}

	void NewCredit(Human* human, Finance* finance);

	bool Request(Finance* finance);

	bool Calculation(Finance* finance);

	void DebtOff(Finance* finance);

	void Refinance(Human* human, Finance* finance);

	void Print() const
	{
		lst.print();
	}

	friend ostream& operator <<(ostream& output, ConsumerCredit lst)
	{
		output << setw(35) << right << lst.credit_type
			<< setw(17) << right << lst.credit_size << lst.cur
			<< setw(16) << right << lst.loan_balance << lst.cur
			<< setw(17) << right << lst.date << "мес"
			<< setw(20) << right << lst.percent <<"%" 
			<< setw(20) << right << lst.pay_per_month << lst.cur << endl;
		return output;
	}
};

class Mortage : public ConsumerCredit
{
	long double contribution;
	List <Mortage> lst;
public:
	Mortage() = default;

	Mortage(string credit_type, Currency cur, long long credit_size, double percent, long pay_per_month, int date, long double contribution, long long loan_balance)
		: ConsumerCredit(credit_type, cur, credit_size, percent, pay_per_month, date, loan_balance)
	{
		this->credit_type = credit_type;
		this->cur = cur;
		this->credit_size = credit_size;
		this->percent = percent;
		this->pay_per_month = pay_per_month;
		this->date = date;
		this->contribution = contribution;
		this->loan_balance = loan_balance;
	}
	
	void NewCredit(Human* human, Finance* finance);

	bool Request(Finance* finance);

	bool Calculation(Finance* finance);

	void DebtOff(Finance* finance);

	void Refinance(Human* human, Finance* finance);

	void Print() const
	{
		lst.print();
	}

	friend ostream& operator <<(ostream& output, Mortage lst)
	{
		output << setw(35) << right << lst.credit_type
			<< setw(17) << right << lst.credit_size << lst.cur
			<< setw(16) << right << lst.loan_balance << lst.cur
			<< setw(17) << right << lst.date << "мес"
			<< setw(20) << right << lst.percent << "%"
			<< setw(20) << right << lst.pay_per_month << lst.cur << endl;
		return output;
	}
};



