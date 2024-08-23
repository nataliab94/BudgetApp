#ifndef BUDGETAPPMAIN_H
#define BUDGETAPPMAIN_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"
#include "DateMethods.h"
#include "UserFile.h"


using namespace std;

class BudgetAppMain
{
    UserManager userManager;
    BudgetManager * budgetManager;
    DateMethods dateMethods;

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:

    BudgetAppMain(string userFileName, string incomesFileName, string expenseFileName) :
        userManager(userFileName),
        INCOMES_FILE_NAME(incomesFileName),
        EXPENSES_FILE_NAME(expenseFileName)
    {
        budgetManager = NULL;
        loadUsersFromFile();
    }
    ~BudgetAppMain()
    {
        delete budgetManager;
        budgetManager = NULL;
    }

    void registerUser();
    void loginUser();
    void logOutUser();
    bool isUserLoggedIn();
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void loadUsersFromFile();
    void changePassword();

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();


};

#endif
