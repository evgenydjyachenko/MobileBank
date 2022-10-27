#include "Credit.h"

void ConsumerCredit::Approved(Human* human)
{
	cout << setw(67) << human->getOwner() << ", Вам одобрен кредит на следующих условиях:" << endl << endl
		<< setw(83) << "Сумма - " << credit_size << cur << endl << endl
		<< setw(83) << "Срок - " << date << "мес." << endl << endl
		<< setw(88) << "Ежемесяный платеж -" << " " << pay_per_month << cur << endl << endl
		<< setw(88) << "Процентная ставка -" << " " << percent << "%" << endl << endl;
}

void ConsumerCredit::Offer(Human* human)
{
	system("cls");
	REQUEST_CREDIT
		cout << setw(87) << "Поздравляем Вас, " << human->getOwner() << "!" << endl << endl
		<< setw(70) << "Вы оформили " << credit_type << " под " << percent << "% годовых" << endl
		<< setw(75) << "сроком на " << date << " месяцев на сумму " << credit_size << cur << endl << endl
		<< setw(82) << "Номер договора " << rand() % 999 << " - " << rand() % 999 << " - " << rand() % 999 << endl;
}

double ConsumerCredit::rand_percent(double min, double max)
{
	double r = (double)(rand()) / RAND_MAX * (max - min) + min;
	double result = floor(r * 10) / 10;
	return result;
}

void ConsumerCredit::NewCredit(Human* human, Finance* finance)
{
	system("cls");

	if (Request(finance) == true && Calculation(finance) == true)
	{
		getline(cin, choice);
		system("cls");
		cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
			<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

		for (int j = 0; j < 2000000000; j++) {}

		system("cls");
		REQUEST_CREDIT
			Approved(human);

		do
		{
			cout << setw(98) << "Желаете оформить кредит?(Y/N):";
			getline(cin, choice);

			credit_type = "Потребительский кредит";
			loan_balance = credit_size;

			if (choice[0] == 'Y' || choice[0] == 'y')
			{
				Offer(human);
				ConsumerCredit* consumer = new ConsumerCredit(credit_type, cur, credit_size, percent, pay_per_month, date, loan_balance);
				finance->setPayConsumer(pay_per_month, cur);
				lst.push_back(*consumer);
			}

			else if (choice[0] == 'N' || choice[0] == 'n') {}

			else
			{
				cout << endl << setw(100); INCORRECT cout << endl;
			}

		} while ((choice[0] != 'Y' && choice[0] != 'y') && (choice[0] != 'N' && choice[0] != 'n'));
	}
	else
	{
		system("cls");

		cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
			<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

		for (int j = 0; j < 2000000000; j++) {}

		system("cls");
		REQUEST_CREDIT

			cout << setw(73) << human->getOwner() << ", Вам отказано в выдаче кредита." << endl;
	}
	cout << endl << setw(63) << ""; system("pause"); system("cls");
}

bool ConsumerCredit::Request(Finance* finance)
{
	bool check = false;

	REQUEST_CREDIT

		do
		{
			cout << "Выберите валюту:" << endl
				<< "1 - Рубль" << endl
				<< "2 - Доллар" << endl
				<< "3 - Евро" << endl;
			cin >> currency;
			if (currency == 1)
				cur = ruble;
			else if (currency == 2)
				cur = dollar;
			else if (currency == 3)
				cur = euro;
			else
			{
				INCORRECT
					cout << endl << endl << setw(63) << ""; system("pause"); system("cls");
				REQUEST_CREDIT
			}

		} while (currency < 1 || currency > 3);

		finance->IncomeExpenses(finance, cur);

		do
		{
			cout << "Желаемая сумма кредита:";
			cin >> credit_size;

			if (cur == ruble && credit_size > 2000000)
			{
				cout << setw(103) << "Максимальная сумма кредита - 2 000 000!" << endl << endl;
			}

			else if ((cur == dollar || cur == euro) && credit_size > 20000)
			{
				cout << setw(103) << "Максимальная сумма кредита - 20 000!" << endl << endl;
			}
			else
			{
				check = true;
			}

		} while (check == false);

		if ((finance->getIncome() - finance->getExpenses()) >= finance->getIncome() * 0.25)
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool ConsumerCredit::Calculation(Finance* finance)
{
	if (cur == dollar || cur == euro)
	{
		date = credit_size * finance->getRate() / (finance->getIncome() * 0.15);

		if (date <= 36)
		{
			percent = rand_percent(13.5, 16.5);
			pay_per_month = (credit_size * finance->getRate()) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			pay_per_month /= finance->getRate();
			return true;
		}

		else if (date > 36 && date <= 84)
		{
			percent = rand_percent(16.5, 19.5);
			pay_per_month = (credit_size * finance->getRate()) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			pay_per_month /= finance->getRate();
			return true;
		}

		else
		{
			return false;
		}
	}

	else
	{
		date = credit_size / (finance->getIncome() * 0.15);

		if (date <= 36)
		{
			percent = rand_percent(13.5, 16.5);
			pay_per_month = credit_size * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			return true;
		}

		else if (date > 36 && date <= 84)
		{
			percent = rand_percent(16.5, 19.5);
			pay_per_month = credit_size * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			return true;
		}

		else
		{
			return false;
		}
	}

}

void ConsumerCredit::DebtOff(Finance* finance)
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		DATA
			CreditHat();
		lst.print();

		cout << "Введите №п/п кредита:";
		cin >> number;
		i = 0;
		number--;
		if (number < lst.getSize() && number >= 0)
		{

			for (int i = 0; i < lst.getSize(); ++i)
			{

				if (number == i)
				{
					finance->DeleteConsumer(number);
					lst.removeAt(number);
					system("cls");
					DATA
						CreditHat();
					lst.print();
					cout << setw(95) << "Кредит успешно закрыт!" << endl << endl << setw(63) << ""; system("pause");
					break;
				}
			}
		}
		else
		{
			INCORRECT system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << ""; system("pause");
	}
}

void ConsumerCredit::Refinance(Human* human, Finance* finance)
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		DATA
			CreditHat();
		lst.print();

		cout << "Введите №п/п кредита:";
		cin >> number;
		number--;

		if (number < lst.getSize() && number >= 0)
		{
			getline(cin, choice);

			for (int i = 0; i < lst.getSize(); ++i)
			{
				if (number == i)
				{
					system("cls");

					cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
						<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

					for (int j = 0; j < 2000000000; j++) {}

					percent -= rand_percent(1, 3);
					pay_per_month = lst[i].loan_balance * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), lst[i].date)) / ((pow((1 + ((percent / 12) / 100)), lst[i].date)) - 1));

					system("cls");
					REQUEST_REF

						do
						{
							cout << setw(98) << "Желаете рефинансировать кредит?(Y/N):";
							getline(cin, choice);

							if (choice[0] == 'Y' || choice[0] == 'y')
							{
								ConsumerCredit* consumer = new ConsumerCredit(lst[i].credit_type, lst[i].cur, lst[i].credit_size, percent, pay_per_month, lst[i].date, lst[i].loan_balance);
								finance->changePayConsumer(pay_per_month, number);
								lst.removeAt(number);
								lst.insert(*consumer, number);

								system("cls");

								DATA
									CreditHat();
								lst.print();
								cout << setw(98) << "Кредит успешно рефинансирован!" << endl << endl << setw(63) << ""; system("pause");
								break;
							}

							else if (choice[0] == 'N' || choice[0] == 'n')
							{
								break;
							}

							else
							{
								cout << endl << setw(100); INCORRECT cout << endl;
							}

						} while ((choice[0] != 'Y' && choice[0] != 'y') && (choice[0] != 'N' && choice[0] != 'n'));
				}
			}
		}
		else
		{
			INCORRECT system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << ""; system("pause");
	}
}

void Mortage::NewCredit(Human* human, Finance* finance)
{
	system("cls");

	if (Request(finance) == true && Calculation(finance) == true)
	{
		getline(cin, choice);
		system("cls");
		cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
			<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

		for (int j = 0; j < 2000000000; j++) {}

		system("cls");
		REQUEST_CREDIT
			Approved(human);

		do
		{
			cout << setw(98) << "Желаете оформить кредит?(Y/N):";
			getline(cin, choice);

			credit_type = "Ипотечный кредит";
			loan_balance = credit_size - contribution;

			if (choice[0] == 'Y' || choice[0] == 'y')
			{
				Offer(human);
				Mortage* mortage = new Mortage(credit_type, cur, credit_size, percent, pay_per_month, date, contribution, loan_balance);
				finance->setPayMortage(pay_per_month, cur);
				lst.push_back(*mortage);
			}

			else if (choice[0] == 'N' || choice[0] == 'n') {}

			else
			{
				cout << endl << setw(100); INCORRECT cout << endl;
			}

		} while ((choice[0] != 'Y' && choice[0] != 'y') && (choice[0] != 'N' && choice[0] != 'n'));

	}
	else
	{
		system("cls");
		cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
			<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

		for (int j = 0; j < 2000000000; j++) {}

		system("cls");

		REQUEST_CREDIT
			cout << setw(73) << human->getOwner() << ", Вам отказано в выдаче кредита." << endl;
	}
	cout << endl << setw(63) << ""; system("pause"); system("cls");
}

bool Mortage::Request(Finance* finance)
{
	bool check = false;

	REQUEST_CREDIT

		do
		{
			do
			{
				cout << "Выберите валюту:" << endl
					<< "1 - Рубль" << endl
					<< "2 - Доллар" << endl
					<< "3 - Евро" << endl;
				cin >> currency;
				if (currency == 1)
					cur = ruble;
				else if (currency == 2)
					cur = dollar;
				else if (currency == 3)
					cur = euro;
				else
				{
					INCORRECT
						cout << endl << endl << setw(63) << ""; system("pause"); system("cls");
					REQUEST_CREDIT
				}

			} while (currency < 1 || currency > 3);

			finance->IncomeExpenses(finance, cur);

			do
			{
				cout << "Желаемая сумма кредита:";
				cin >> credit_size;

				if (cur == ruble && credit_size > 5000000)
				{
					cout << setw(103) << "Максимальная сумма кредита - 5 000 000!" << endl << endl;
				}

				else if ((cur == dollar || cur == euro) && credit_size > 75000)
				{
					cout << setw(103) << "Максимальная сумма кредита - 75 000!" << endl << endl;
				}
				else
				{
					check = true;
				}

			} while (check == false);

			cout << "Первоначальный взнос:";
			cin >> contribution;

		} while (check == false);

		if ((finance->getIncome() - finance->getExpenses()) >= finance->getIncome() * 0.25 && contribution > (credit_size * 0.15))
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool Mortage::Calculation(Finance* finance)
{
	if (cur == dollar || cur == euro)
	{
		date = (credit_size * finance->getRate() - contribution * finance->getRate()) / (finance->getIncome() * 0.15);

		if (date <= 60)
		{
			percent = rand_percent(9.5, 12.5);
			pay_per_month = (credit_size * finance->getRate() - contribution * finance->getRate()) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			pay_per_month /= finance->getRate();
			return true;
		}

		else if (date > 60 && date <= 180)
		{
			percent = rand_percent(12.5, 15.5);
			pay_per_month = (credit_size * finance->getRate() - contribution * finance->getRate()) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			pay_per_month /= finance->getRate();
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		date = (credit_size - contribution) / (finance->getIncome() * 0.15);

		if (date <= 60)
		{
			percent = rand_percent(9.5, 12.5);
			pay_per_month = (credit_size - contribution) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			return true;
		}

		else if (date > 60 && date <= 180)
		{
			percent = rand_percent(12.5, 15.5);
			pay_per_month = (credit_size - contribution) * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), date)) / ((pow((1 + ((percent / 12) / 100)), date)) - 1));
			return true;
		}
		else
		{
			return false;
		}
	}

}

void Mortage::DebtOff(Finance* finance)
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		DATA
			CreditHat();
		lst.print();

		cout << "Введите №п/п кредита:";
		cin >> number;
		i = 0;
		number--;
		if (number < lst.getSize() && number >= 0)
		{

			for (int i = 0; i < lst.getSize(); ++i)
			{

				if (number == i)
				{
					finance->DeleteMortage(number);
					lst.removeAt(number);
					system("cls");
					DATA
						CreditHat();
					lst.print();
					cout << setw(95) << "Кредит успешно закрыт!" << endl << endl << setw(63) << ""; system("pause");
					break;
				}
			}
		}
		else
		{
			INCORRECT system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << ""; system("pause");
	}
}

void Mortage::Refinance(Human* human, Finance* finance)
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		DATA
			CreditHat();
		lst.print();

		cout << "Введите №п/п кредита:";
		cin >> number;
		number--;

		if (number < lst.getSize() && number >= 0)
		{
			getline(cin, choice);

			for (int i = 0; i < lst.getSize(); ++i)
			{
				if (number == i)
				{
					system("cls");

					cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
						<< endl << setw(115) << "Выполняется обработка заявки. . . Пожалуйста, подождите. . . " << endl << endl;

					for (int j = 0; j < 2000000000; j++) {}

					percent -= rand_percent(1, 2);
					pay_per_month = lst[i].loan_balance * (((percent / 12) / 100) * (pow((1 + ((percent / 12) / 100)), lst[i].date)) / ((pow((1 + ((percent / 12) / 100)), lst[i].date)) - 1));

					system("cls");
					REQUEST_REF

						do
						{
							cout << setw(98) << "Желаете рефинансировать кредит?(Y/N):";
							getline(cin, choice);

							if (choice[0] == 'Y' || choice[0] == 'y')
							{
								Mortage* mortage = new Mortage(lst[i].credit_type, lst[i].cur, lst[i].credit_size, percent, pay_per_month, lst[i].date, lst[i].contribution, lst[i].loan_balance);
								finance->changePayMortage(pay_per_month, number);
								lst.removeAt(number);
								lst.insert(*mortage, number);

								system("cls");

								DATA
									CreditHat();
								lst.print();
								cout << setw(98) << "Кредит успешно рефинансирован!" << endl << endl << setw(63) << ""; system("pause");
								break;
							}

							else if (choice[0] == 'N' || choice[0] == 'n')
							{
								break;
							}

							else
							{
								cout << endl << setw(100); INCORRECT cout << endl;
							}

						} while ((choice[0] != 'Y' && choice[0] != 'y') && (choice[0] != 'N' && choice[0] != 'n'));
				}
			}
		}
		else
		{
			INCORRECT system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << ""; system("pause");
	}
}
