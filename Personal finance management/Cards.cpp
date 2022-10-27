
#include "Cards.h"

void DebitCard::ToDelete()
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		SEARCH
			CardsHat();
		lst.print();

		cout << "Введите №п/п карты/кошелька:";
		cin >> number;
		i = 0;
		number--;
		if (number < lst.getSize() && number >= 0)
		{

			for (int i = 0; i < lst.getSize(); ++i)
			{

				if (number == i)
				{
					lst.removeAt(number);
					system("cls");
					DATA
						CardsHat();
					lst.print();
					cout << setw(97) << "Удаление успешно завершено!" << endl << endl << setw(63) << "";
					system("pause");
					break;
				}
			}
		}
		else
		{
			INCORRECT
				system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << "";
		system("pause");
	}
}

void DebitCard::NewCard()
{
	int choice, currency, month, year;
	double balance;
	long long credit_limit;
	Currency cur;
	string s, payment, wallet_number, number, card_number;
	getline(cin, s);

	do
	{
		cout << "Введите номер карты в формате xxxx xxxx xxxx xxxx:";
		getline(cin, card_number);
		if (card::CheckCard(&card_number) == true)
		{
			Info(&payment, &currency, &cur, &balance, &month, &year);
			DebitCard* debit = new DebitCard(card_number, payment, cur, balance, month, year);
			lst.push_back(*debit);
			cout << setw(97) << "Карта успешно добавлена!" << endl << endl << setw(63) << "";
			system("pause");
		}
		else
		{
			INCORRECT
		}
	} while (card::CheckCard(&card_number) != true);

}

void CreditCard::ToDelete()
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
			CardsHat();
		lst.print();

		cout << "Введите №п/п карты/кошелька:";
		cin >> number;
		i = 0;
		number--;
		if (number < lst.getSize() && number >= 0)
		{

			for (int i = 0; i < lst.getSize(); ++i)
			{

				if (number == i)
				{

					lst.removeAt(number);
					system("cls");
					DATA
						CardsHat();
					lst.print();
					cout << setw(97) << "Удаление успешно завершено!" << endl << endl << setw(63) << "";
					system("pause");
					break;
				}
			}
		}
		else
		{
			INCORRECT
				system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << "";
		system("pause");
	}
}

void CreditCard::NewCard()
{
	int choice, currency, month, year;
	double balance;
	long long credit_limit;
	Currency cur;
	string s, payment, wallet_number, number, card_number;
	getline(cin, s);

	do
	{
		cout << "Введите номер карты в формате xxxx xxxx xxxx xxxx:";
		getline(cin, card_number);
		if (card::CheckCard(&card_number) == true)
		{
			Info(&payment, &currency, &cur, &balance, &month, &year);
			cout << "Укажите кредитный лимит:";
			cin >> credit_limit;
			CreditCard* credit = new CreditCard(card_number, payment, cur, balance, month, year, credit_limit);
			lst.push_back(*credit);
			cout << setw(97) << "Карта успешно добавлена!" << endl << endl << setw(63) << "";
			system("pause");
		}
		else
		{
			INCORRECT
				system("pause");
		}
	} while (card::CheckCard(&card_number) != true);
}

void Wallet::ToDelete()
{
	int number, i = 0;
	system("cls");
	cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl
		<< endl << setw(115) << "Выполняется поиск данных. . . Пожалуйста, подождите. . . " << endl << endl;

	for (int j = 0; j < 2000000000; j++) {}

	system("cls");

	if (lst.getSize() > 0)
	{
		SEARCH
			CardsHat();
		lst.print();

		cout << "Введите №п/п карты/кошелька:";
		cin >> number;
		i = 0;
		number--;
		if (number < lst.getSize() && number >= 0)
		{

			for (int i = 0; i < lst.getSize(); ++i)
			{

				if (number == i)
				{
					lst.removeAt(number);
					system("cls");
					DATA
						CardsHat();
					lst.print();
					cout << setw(97) << "Удаление успешно завершено!" << endl << endl << setw(63) << "";
					system("pause");
					break;
				}
			}
		}
		else
		{
			INCORRECT
				system("pause");
		}
	}
	else
	{
		SEARCH
			cout << setw(92) << "Данные не найдены!" << endl << endl << setw(63) << "";
		system("pause");
	}
}

void Wallet::NewCard()
{
	int choice, currency, month, year;
	double balance;
	long long credit_limit;
	Currency cur;
	string s, payment, wallet_number, number, card_number;
	getline(cin, s);

	do
	{
		cout << "Введите номер кошелька из 14 цифр:";
		getline(cin, wallet_number);
		if (wallet::CheckCard(&wallet_number) == true)
		{
			Info(&payment, &currency, &cur, &balance, &month, &year);
			Wallet* wallet = new Wallet(wallet_number, cur, balance, payment, month, year);
			lst.push_back(*wallet);
			cout << setw(101) << "Электронный кошелёк успешно добавлен!" << endl << endl << setw(63) << "";
			system("pause");
		}
		else
		{
			INCORRECT
		}
	} while (wallet::CheckCard(&wallet_number) != true);
}
