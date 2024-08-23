#include "BudgetMainApp.h"

using namespace std;



void BudgetAppMain::registerUser()
{
    userManager.registerUser();
}

void BudgetAppMain::loginUser()
{
    userManager.loginUser();

    if (isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedUserId());
    }
}

void BudgetAppMain::logOutUser()
{
    userManager.logOutUser();
}

bool BudgetAppMain::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void BudgetAppMain::changePassword()
{
    userManager.changeUserPassword();
}
char BudgetAppMain::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>>MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = Utils::getCharacter();

    return choice;
}

char BudgetAppMain::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance " << endl;
    cout << "4. Previous month balance" << endl;
    cout << "5. Selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    choice = Utils::getCharacter();

    return choice;
}

void BudgetAppMain::loadUsersFromFile()
{
    userManager.loadUsers();
}

void BudgetAppMain::addIncome()
{
    budgetManager->addOperationDetails(INCOME);
}

void BudgetAppMain::addExpense()
{
    budgetManager->addOperationDetails(EXPENSE);
}

void BudgetAppMain::showCurrentMonthBalance()
{
    int startDate = dateMethods.getCurrentMonthFirstDayDate();
    int endDate = dateMethods.getCurrentDate();

    budgetManager->showBalance(startDate, endDate);
}

void BudgetAppMain::showPreviousMonthBalance()
{
    int startDate = dateMethods.getPreviousMonthFirstDayDate();
    int endDate = dateMethods.getPreviousMonthLastDayDate();

    budgetManager->showBalance(startDate, endDate);
}

void BudgetAppMain::showCustomPeriodBalance()
{
    string startDateString, endDateString;
    cout << "Enter start date (yyyy-mm-dd): ";
    cin >> startDateString;
    cout << "Enter end date (yyyy-mm-dd): ";
    cin >> endDateString;

    int startDate = dateMethods.convertStringDateToInt(startDateString);
    int endDate = dateMethods.convertStringDateToInt(endDateString);

    budgetManager->showBalance(startDate, endDate);
}



