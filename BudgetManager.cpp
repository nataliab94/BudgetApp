#include "BudgetManager.h"

Operation BudgetManager::addOperationDetails(const Type &type)
{
    Operation operation;
    string typeDescription, tempDate, tempAmount, fileName;

    switch(type)
    {
    case INCOME:
        operation.id = incomeFile.getLastId() + 1;
        typeDescription = "income";
        break;
    case EXPENSE:
        operation.id = expenseFile.getLastId() + 1;
        typeDescription = "expense";
        break;
    }

    operation.userId = LOGGED_USER_ID;

    cout << "Enter " << typeDescription << " date. Press 'y' if you want to enter the current date, or 'n' to enter a specific date: ";
    if (Utils::getCharacter() == 'y')
    {
        tempDate = dateMethods.convertIntDateToStringWithDashes(dateMethods.getCurrentDate());
    }
    else
    {
        do
        {
            cout << "Enter " << typeDescription << " date (YYYY-MM-DD): ";
            tempDate = Utils::readLine();
        }
        while (!dateMethods.validateDate(tempDate));
    }

    operation.date = dateMethods.convertStringDateToInt(tempDate);

    cout << "Enter " << typeDescription << " name: ";
    operation.item = Utils::readLine();

    do
    {
        cout << "Add " << typeDescription << " amount with up to two decimal places: ";
        tempAmount = Utils::readLine();
    }
    while (!CashMethods::validateAmount(tempAmount));

    operation.amount = stod(tempAmount);

    if (type == INCOME)
    {
        incomeFile.addOperationToFile(operation);
    }
    else if (type == EXPENSE)
    {
        expenseFile.addOperationToFile(operation);
    }


    return operation;
}



void BudgetManager::showOperationDetails(Operation operation, Type type)
{
    switch (type)
    {
    case EXPENSE:
        cout << "Expense: " << operation.item << ", date: " << operation.date << ", amount: " << operation.amount << endl;
        break;
    case INCOME:
        cout << "Income: " << operation.item << ", date: " << operation.date << ", amount: " << operation.amount << endl;
        break;
    }
}


double BudgetManager::calculateBalance(const vector<Operation>& operations)
{
    double total = 0;
    for (const auto& operation : operations)
    {
        total += operation.amount;
    }
    return total;
}

void BudgetManager::showBalance(int startDate, int endDate)
{
    vector<Operation> filteredIncomes;
    vector<Operation> filteredExpenses;



    cout << "Loading incomes and expenses for user ID: " << LOGGED_USER_ID << endl;

    for (const auto& operation : incomes)
    {

        if (operation.date >= startDate && operation.date <= endDate)
        {
            cout << "Date = " << dateMethods.convertIntDateToStringWithDashes(operation.date) << " Type "<<operation.item<<" Income: "<< operation.amount<< endl;
            filteredIncomes.push_back(operation);
        }
    }

    for (const auto& operation : expenses)
    {

        if (operation.date >= startDate && operation.date <= endDate)
        {
            cout << "Date = " << dateMethods.convertIntDateToStringWithDashes(operation.date)<< " Type "<<operation.item<<" Expense: "<< operation.amount << endl;
            filteredExpenses.push_back(operation);
        }
    }

    double totalIncomes = calculateBalance(filteredIncomes);
    double totalExpenses = calculateBalance(filteredExpenses);

    cout << "Balance from " << dateMethods.convertIntDateToStringWithDashes(startDate) << " to " << dateMethods.convertIntDateToStringWithDashes(endDate) << ":" << endl;
    cout << "Total Incomes: " << totalIncomes << endl;
    cout << "Total Expenses: " << totalExpenses << endl;
    cout << "Net Balance: " << (totalIncomes - totalExpenses) << endl;

    system("pause");
}
