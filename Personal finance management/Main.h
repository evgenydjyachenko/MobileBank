#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "List.h"
#include <cmath>

#define DATA cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(88) << "ВАШИ ДАННЫЕ" << endl << endl;
#define ADD_CARD cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(89) << "НОВЫЕ ДАННЫЕ" << endl << endl << "Выберите команду:" << endl << "0 - Назад" << endl <<"1 - Добавить дебетовую карту" << endl << "2 - Добавить кредитную карту" << endl << "3 - Добавить электронный кошелёк" << endl;
#define DELETE_CARD cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(90) << "УДАЛЕНИЕ ДАННЫХ" << endl << endl << "Выберите команду:" << endl << "0 - Назад" << endl <<"1 - Удалить дебетовую карту" << endl << "2 - Удалить кредитную карту" << endl << "3 - Удалить виртуальный кошелёк" << endl;
#define CARD_WALLET_MENU cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(90) << "КАРТЫ/КОШЕЛЬКИ" << endl << endl << "Выберите команду:" << endl << "0 - Назад" << endl << "1 - Добавить данные" << endl << "2 - Удалить данные" << endl << "3 - Вывести данные на экран" << endl;
#define CREDITS_MENU cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(86) << "КРЕДИТЫ" << endl << endl << "Выберите команду:" << endl << "0 - Назад" << endl << "1 - Оформить кредит" << endl << "2 - Погасить кредит" << endl << "3 - Рефинансировать кредит" << endl << "4 - Вывести данные на экран" << endl;
#define CREDIT_TYPE  system("cls"); cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(86) << "КРЕДИТЫ" << endl << endl; cout << "Выберите тип кредита:" << endl << "0 - Назад" << endl << "1 - Потребительский" << endl << "2 - Ипотечный" << endl;
#define REQUEST_CREDIT cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(94) << "ЗАЯВКА НА КРЕДИТОВАНИЕ" << endl << endl;
#define REQUEST_REF cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(94) << "ЗАЯВКА НА РЕФИНАНСИРОВАНИЕ" << endl << endl << setw(67) << human->getOwner() << ", Ваши условия по рефинансированию:" << endl << endl << setw(83) << "Сумма - " << lst[i].credit_size << lst[i].cur << endl << endl << setw(83) << "Срок - " << lst[i].date << "мес." << endl << endl << setw(88) << "Ежемесяный платеж -" << " " << pay_per_month << lst[i].cur << endl << endl << setw(88) << "Процентная ставка -" << " " << percent << "%" << endl << endl;
#define FINANCE_MENU cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(87) << "ФИНАНСЫ" << endl << endl << "Выберите команду:" << endl << "0 - Назад" << endl << "1 - Добавить доходы" << endl << "2 - Добавить расходы" << endl << "3 - Вывести данные на экран" << endl;
#define FINANCE_ANALYSIS cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(90) << "ДОХОДЫ/РАСХОДЫ" << endl << endl;
#define SEARCH cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(91) << "РЕЗУЛЬТАТ ПОИСКА" << endl << endl;
#define MAIN_MENU cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(89) << "ГЛАВНОЕ МЕНЮ" << endl << endl<< "Выберите вкладку:" << endl << "0 - Выйти из приложения" << endl << "1 - Карты/кошельки" << endl << "2 - Кредиты" << endl << "3 - Финансы" << endl;
#define INCORRECT cout << "Некорректный ввод, попробуйте заново." << endl;

using namespace std;

namespace wallet
{
	bool CheckCard(string* wallet_number);
}

namespace card
{
	bool CheckCard(string* card_number);
}


enum Currency : char
{
    ruble = 'Р', dollar = '$', euro = 'E'
};

void Info(string* string, int* currency, Currency* cur, double* balance, int* month, int* year);

void SignIn();

void CardsHat();

void CreditHat();
