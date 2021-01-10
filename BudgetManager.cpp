#include "BudgetManager.h"

Income BudgetManager::enterNewIncomeData()
{

}

Expense BudgetManager::enterNewExpenseData()
{

}

char BudgetManager::chooseOptionFromAdditionalMenu()
{

}

void BudgetManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData();

    incomes.push_back(income);
    if(incomesFile.addIncomeToFile(income))
        cout << "New income has been added." << endl;
    else
        cout << "Error! Cannot add income to file." << endl;
    system("pause");
}

void BudgetManager::addExpense()
{

}

void BudgetManager::currentMonthBalance()
{

}

void BudgetManager::chosenPeriodBalance()
{

}
