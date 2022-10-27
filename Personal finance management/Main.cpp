#include "Human.h"
#include "Main.h"
#include "Credit.h"
#include "Finance.h"


namespace card
{
    bool CheckCard(string* card_number)
    {
        int length = card_number->size();
        char buff[255];
        strcpy(buff, card_number->c_str());

        if (length == 19)
        {
            for (int i = 0, z = 0; i < length; i++, z++)
            {
                if (z == 4)
                {
                    i++;
                    z = 0;
                }
                if (buff[i] > 47 && buff[i] < 58) {}
                else
                {
                    return false;
                }               
            }

            for (int j = 4; j <= 14; j += 5)
            {
                if (buff[j] == ' ') {}
                else
                {
                    return false;
                }
            }

            return true;
        }
        else
        {
            return false;
        }
    }
}

namespace wallet
{
    bool CheckCard(string* wallet_number)
    {
        int length = wallet_number->size();
        char buff[255];
        strcpy(buff, wallet_number->c_str());

        if (length == 14)
        {
            for (int i = 0; i < length; i++)
            {
                if (buff[i] > 47 && buff[i] < 58) {}
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Password_Check(vector <char>* vec)
{
    vector <char> password = { 'q','w','e','r','t','y' };
    if (password.size() == vec->size())
    {
        for (auto it = password.cbegin(), it2 = vec->cbegin(); it != password.cend(); ++it, ++it2)
        {
            if (*it == *it2) {}
            else
            {
                vec->clear();
                cout << endl << endl << setw(91) << "НЕВЕРНЫЙ ПАРОЛЬ!" << endl << endl << setw(63) << ""; system("pause"); system("cls");
                return false;
            }
        }
    }
    else
    {
        vec->clear();
        cout << endl << endl << setw(91) << "НЕВЕРНЫЙ ПАРОЛЬ!" << endl << endl << setw(63) << ""; system("pause"); system("cls");
        return false;
    }
    return true;
}

void SignIn()
{
    vector <char> password_add;
    char c;

    do
    {
        cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl;
        cout << setw(87) << "Введите пароль: ";
        while ((c = _getch()) != '\r')
        {
            password_add.push_back(c);
            _putch('*');
        }
    } while (!Password_Check(&password_add));
    
    cout << endl << endl << setw(63) << ""; system("pause"); system("cls");
    cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl;
}

void Info(string* string, int* currency, Currency* cur, double* balance, int* month, int* year)
{
    cout << "Введите название платежной системы:";
    getline(cin, *string);
    do
    {
        cout << "Выберите валюту:" << endl
            << "1 - Рубль" << endl
            << "2 - Доллар" << endl
            << "3 - Евро" << endl;
        cin >> *currency;
        if (*currency == 1)
            *cur = ruble;
        else if (*currency == 2)
            *cur = dollar;
        else if (*currency == 3)
            *cur = euro;
        else
        {
            INCORRECT
                cout << endl << endl << setw(63) << "";
            system("pause");
            system("cls");
            cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl << setw(89) << "НОВЫЕ ДАННЫЕ" << endl << endl;
        }

    } while (*currency <1 || *currency > 3);
    
    cout << "Введите балланс:";
    cin >> *balance;

    cout << "Введите срок действия(MM/YY):" << endl;
        
    do
    {
        cout << "Месяц:";
        cin >> *month;
        if (*month < 1 || *month > 12)
        {
            INCORRECT
        }
    } while (*month < 1 || *month > 12);

    do
    {
        cout << "Год:";
        cin >> *year;
        if (*year < 22 || *year > 35)
        {
            INCORRECT
        }
    } while (*year < 22 || *year > 35);   
}

void CardsHat()
{
    cout << setw(55) << right << "№ Счета"
        << setw(20) << right << "Баланс"
        << setw(20) << right << "Кредитный лимит"
        << setw(9) << right << "Валюта"
        << setw(20) << right << "Платежная система"
        << setw(15) << right << "Срок действия" << endl << endl;
}

void CreditHat()
{
    cout << setw(55) << right << "Сумма кредита"
        << setw(22) << right << "Остаток к погашению"
        << setw(20) << right << "Срок кредитования"
        << setw(20) << right << "Процентная ставка" 
        << setw(20) << right << "Ежемесячный платеж" << endl << endl;
}

void FinanceHat()
{
    cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl;
    cout << setw(88) << "СТАТИСТИКА РАСХОДОВ" << endl << endl
        << setw(55) << right << ""
        << setw(26) << right << "Остаток к погашению"
        << setw(9) << right << "Валюта"
        << setw(20) << right << "Срок кредитования"
        << setw(20) << right << "Процентная ставка" << endl << endl;
}

