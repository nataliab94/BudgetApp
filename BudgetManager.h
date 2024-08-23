#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include<algorithm>
#include "Type.h"
#include "File.h"
#include "Operation.h"
#include "OperationFile.h"
#include "Utils.h"
#include "CashMethods.h"
#include "DateMethods.h"


using namespace std;

class BudgetManager
{
    const int LOGGED_USER_ID;

    OperationFile incomeFile;
    OperationFile expenseFile;


    vector <Operation> incomes;
    vector <Operation> expenses;


    Operation typeOperationDetails(int lastOperationId);
    DateMethods dateMethods;




public:

    BudgetManager (string incomeFileName, string expenseFileName, int loggedUserId)
    :LOGGED_USER_ID(loggedUserId), incomeFile(incomeFileName),expenseFile(expenseFileName)
    {
        incomes = incomeFile.loadOperationsFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromFile(LOGGED_USER_ID);
    }
    double calculateBalance(const vector<Operation>& operations);
    Operation addOperationDetails(const Type &type);
    void showOperationDetails(Operation operation, Type type);
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showCustomPeriodBalance();
    void showBalance(int startDate,int endDate);

};

#endif
