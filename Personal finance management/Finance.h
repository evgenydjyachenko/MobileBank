#pragma once
#include "Main.h"

class Finance
{
	long income = 0, expenses = 0, loan_expenses, pay_per_month = 0, sum = 0;
	const static int exchange_rate = 65;// почему double не проходит?
	string name;
	Currency cur;
	vector <string> name_expenses = { "Еда", "ЖКУ", "Транспорт", "Развлечения", "Одежда", "Образование", "Кредиты" };
	vector <long> value_expenses, sum_pay_per_month, sum_consumer, sum_mortage;
public:
	Finance() = default;

	void Calculation();
	
	void DeleteConsumer(int index);

	void DeleteMortage(int index);

	void IncomeExpenses(Finance* finance, Currency cur);

	inline long getPay()
	{
		return pay_per_month;
	}

	void setPay(long pay_per_month);

	void setPayConsumer(long pay_per_month, Currency cur);

	void setPayMortage(long pay_per_month, Currency cur);

	void changePayConsumer(long pay_per_month, int index);

	void changePayMortage(long pay_per_month, int index);

	inline Currency getCur()
	{
		return cur;
	}

	inline double getIncome()
	{
		return income;
	}

	inline double getExpenses()
	{
		return expenses;
	}

	long getAllPay();

	inline static int getRate()
	{
		return exchange_rate;
	}

	inline void setIncome(long income)
	{
		this->income = income;
	}

	inline void setExpenses(long expenses)
	{
		this->expenses = expenses;
	}

	void Print() const;
};


