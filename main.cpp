#include <iostream>


#include "BudgetMainApp.h"
#include "Utils.h"

using namespace std;

int main()
{
    BudgetAppMain budgetAppMain ("users.xml ", "incomes.xml", "expenses.xml");

    char choice;

    while (true)
    {
        if (!budgetAppMain.isUserLoggedIn())
        {
            choice = budgetAppMain.selectOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                budgetAppMain.registerUser();
                break;
            case '2':
                budgetAppMain.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

        else

        {

            choice = budgetAppMain.selectOptionFromUserMenu();

            switch (choice)
            {

            case '1':
                budgetAppMain.addIncome();
                break;
            case '2':
                budgetAppMain.addExpense();
                break;
            case '3':
                budgetAppMain.showCurrentMonthBalance();
                break;
            case '4':
                budgetAppMain.showPreviousMonthBalance();
                break;
            case '5':
                budgetAppMain.showCustomPeriodBalance();
                break;
            case '6':
                budgetAppMain.changePassword();
                break;
            case '7':
                budgetAppMain.logOutUser();
                break;

            }
        }
    }
    return 0;
}



