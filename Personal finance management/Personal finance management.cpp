#include "Main.h"
#include "Credit.h"
#include "List.h"
#include "Cards.h"
#include "Human.h"

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, choice2, choice3;
    string s;

    Cards* cards[] = {new DebitCard, new CreditCard, new Wallet};
    Credit credit;
    ConsumerCredit consumer_credit;
    Mortage mortage;
    Finance finance;
    
    SignIn();

    cout << "Введите Ваше имя: ";
    getline(cin, s);

    Human human(s);

    system("cls");

    for (int j = 0; j < 2000000000; j++) {}//Sleep(5000)

    human.Greeting();

    for (int j = 0; j < 2000000000; j++) {}

    cout << endl << endl;
    cout << setw(63) << ""; system("pause");

    do
    {
        system("cls");
        MAIN_MENU
            cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            do
            {
                system("cls");
                CARD_WALLET_MENU
                cin >> choice2;

                switch (choice2)
                {
                case 0:
                    break;
                case 1:
                    do
                    {  
                        system("cls");
                        ADD_CARD
                            cin >> choice3;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:
                            cards[0]->NewCard();
                            break;
                        case 2:
                            cards[1]->NewCard();
                            break;
                        case 3:
                            cards[2]->NewCard();
                            break;
                        default:
                            INCORRECT
                                cout << setw(63) << ""; system("pause");
                            break;
                        }
                    } while (choice3 != 0);
                    break;
                case 2: 
                    do
                    {
                        system("cls");
                        DELETE_CARD
                        cin >> choice3;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:
                            cards[0]->ToDelete();
                            break;
                        case 2:
                            cards[1]->ToDelete();
                            break;
                        case 3:
                            cards[2]->ToDelete();
                            break;
                        default:
                            INCORRECT
                                cout << setw(63) << ""; system("pause");
                                break;
                        }  
                    } while (choice3 != 0);
                    break;
                case 3:
                    system("cls");
                    DATA
                    CardsHat();
                    for (int i = 0; i < 3; i++)
                    {
                        cards[i]->Print();
                    }
                    cout << setw(63) << ""; system("pause");
                    break;
                default:
                    INCORRECT
                        cout << setw(63) << ""; system("pause");
                    break;
                }
 
            } while (choice2 != 0);
            break;
        case 2:
            do
            {
                system("cls");
                CREDITS_MENU
                    cin >> choice2;

                switch (choice2)
                {
                case 0:
                    break;
                case 1:
                    do
                    {
                        CREDIT_TYPE
                        cin >> choice3;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:                           
                            consumer_credit.NewCredit(&human, &finance);
                            break;
                        case 2:
                            mortage.NewCredit(&human, &finance);
                            break;
                        default:
                            INCORRECT
                                cout << setw(63) << ""; system("pause");
                                break;
                        }
                    } while (choice3 != 0);
                    break;
                case 2:
                    do
                    {
                        CREDIT_TYPE
                        cin >> choice3;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:
                            consumer_credit.DebtOff(&finance);
                            break;
                        case 2:
                            mortage.DebtOff(&finance);
                            break;
                        default:
                            INCORRECT
                                cout << setw(63) << ""; system("pause");
                            break;
                        }
                    } while (choice3 != 0);
                    break;
                case 3:
                    do
                    {
                        CREDIT_TYPE
                            cin >> choice3;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:
                            consumer_credit.Refinance(&human, &finance);
                            break;
                        case 2:
                            mortage.Refinance(&human, &finance);
                            break;
                        default:
                            INCORRECT
                                cout << setw(63) << ""; system("pause");
                            break;
                        }
                    } while (choice3 != 0);
                    break;
                case 4:
                    system("cls");
                    DATA
                    CreditHat();
                    consumer_credit.Print();
                    mortage.Print();
                    cout << setw(63) << ""; system("pause");
                    break;
                default:
                    INCORRECT
                        cout << setw(63) << ""; system("pause");
                        break;
                }              
            } while (choice2 != 0);
            break;
        case 3:
            system("cls");
            getline(cin, s);
            try
            {
                FINANCE_ANALYSIS
                    cout << setw(75) << "ВАШИ ДОХОДЫ" << setw(28) << "ВАШИ РАСХОДЫ" << endl << endl
                    << setw(72) << finance.getIncome() << ruble << setw(27) << finance.getExpenses() + finance.getAllPay() << ruble << endl << endl
                    << setw(90) << "СВОБОДНЫЕ СЕДСТВА = " << (finance.getIncome() - finance.getExpenses() - finance.getAllPay()) << ruble << endl << endl;
                cout << setw(63) << "";
                system("pause");
                cout << endl << setw(104) << "Показать статистику Ваших расходов?(Y/N):";
                getline(cin, s);
                system("cls");
                switch (s[0])
                {
                case 'N':
                case 'n':
                    break;
                case 'Y':
                case 'y':
                    cout << setw(90) << "МОБИЛЬНЫЙ БАНК" << endl << endl;
                    cout << setw(89) << "ВАШИ РАСХОДЫ" << endl << endl;
                    finance.Print();
                    cout << setw(63) << ""; system("pause");
                    break;
                default:
                    INCORRECT
                        cout << setw(63) << ""; system("pause");
                    break;
                }
            }
            catch (const exception& ex)
            {
                cout << setw(95) << ex.what() << endl << endl;
                cout << setw(63) << ""; system("pause");
            }
            break;
        default:
            INCORRECT
                cout << setw(63) << ""; system("pause");
                break;
        }
    } while (choice != 0);
      
    return 0;
}
