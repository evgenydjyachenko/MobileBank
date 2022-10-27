#include "Finance.h"

void Finance::Calculation()
{
	value_expenses.reserve(name_expenses.size());
	if (!value_expenses.empty())
	{

		value_expenses.clear();
	}
	loan_expenses = getExpenses();
	for (int i = 0; i < name_expenses.size() - 2; ++i)
	{
		double result = rand() % loan_expenses;
		value_expenses.push_back(result);
		loan_expenses -= result;
	}
	value_expenses.push_back(loan_expenses);
	value_expenses.push_back(pay_per_month);
}

void Finance::DeleteConsumer(int index)
{
	long pay = getPay();

	for (int i = 0; i < sum_consumer.size(); ++i)
	{
		if (i == index)
		{
			this->pay_per_month = pay - sum_consumer[i];
			value_expenses[6] -= sum_consumer[i];;
			break;
		}
	}
}

void Finance::DeleteMortage(int index)
{
	long pay = getPay();

	for (int i = 0; i < sum_mortage.size(); ++i)
	{
		if (i == index)
		{
			this->pay_per_month = pay - sum_mortage[i];
			value_expenses[6] -= sum_mortage[i];;
			break;
		}
	}
}

void Finance::IncomeExpenses(Finance* finance, Currency cur)
{
	this->cur = cur;

	if (income == 0 && expenses == 0)
	{
		cout << "¬аш ежемес€чный доход:";
		cin >> income;
		cout << "¬аши ежемес€чные расходы:";
		cin >> expenses;

		if (cur == dollar || cur == euro)
		{
			income *= getRate();
			expenses *= getRate();
		}
		finance->Calculation();
	}
}

void Finance::setPay(long pay_per_month)
{
	sum_pay_per_month.push_back(pay_per_month);
	this->value_expenses[6] += pay_per_month;;
	this->pay_per_month = value_expenses[6];
}

void Finance::setPayConsumer(long pay_per_month, Currency cur)
{
	if (cur == dollar || cur == euro)
	{
		sum_consumer.push_back(pay_per_month * getRate());
		setPay(pay_per_month * getRate());
	}
	else
	{
		sum_consumer.push_back(pay_per_month);
		setPay(pay_per_month);
	}
}

void Finance::setPayMortage(long pay_per_month, Currency cur)
{
	if (cur == dollar || cur == euro)
	{
		sum_mortage.push_back(pay_per_month * getRate());
		setPay(pay_per_month * getRate());
	}
	else
	{
		sum_mortage.push_back(pay_per_month);
		setPay(pay_per_month);
	}
}

void Finance::changePayConsumer(long pay_per_month, int index)
{
	this->pay_per_month = pay_per_month;

	for (int i = 0; i < sum_consumer.size(); ++i)
	{
		if (index == i)
		{
			if (cur == dollar || cur == euro)
			{
				value_expenses[6] -= (sum_consumer[i] - (pay_per_month * getRate()));
				sum_consumer[i] = pay_per_month * getRate();
				break;
			}
			else
			{
				value_expenses[6] -= (sum_consumer[i] - pay_per_month);
				sum_consumer[i] = pay_per_month;
				break;
			}

		}
	}
}

void Finance::changePayMortage(long pay_per_month, int index)
{
	this->pay_per_month = pay_per_month;

	for (int i = 0; i < sum_mortage.size(); ++i)
	{
		if (index == i)
		{
			if (cur == dollar || cur == euro)
			{
				value_expenses[6] -= (sum_mortage[i] - (pay_per_month * getRate()));
				sum_mortage[i] = pay_per_month * getRate();
				break;
			}
			else
			{
				value_expenses[6] -= (sum_mortage[i] - pay_per_month);
				sum_mortage[i] = pay_per_month;
				break;
			}

		}
	}
}

long Finance::getAllPay()
{
	if (value_expenses.empty())
	{
		throw exception("Ќет данных о финансах!");
	}
	return value_expenses[6];
}

void Finance::Print() const
{
	for (auto it = name_expenses.cbegin(); it != name_expenses.cend(); ++it)
	{
		cout << "\t\t" << right << *it;
	}
	cout << endl << endl;

	cout << setw(18) << value_expenses[0] << ruble << setw(15) << value_expenses[1] << ruble << setw(18) << value_expenses[2] << ruble
		<< setw(25) << value_expenses[3] << ruble << setw(20) << value_expenses[4] << ruble << setw(18) << value_expenses[5] << ruble << setw(22) << value_expenses[6] << ruble;

	cout << endl << endl;
}