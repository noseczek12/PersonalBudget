#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxiliaryMethods.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"

using namespace std;

class BudgetManager {
    int ID_OF_LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    AuxiliaryMethods auxiliaryMethods;
    Income enterNewIncomeData();
    Expense enterNewExpenseData();
    char chooseOptionFromAdditionalIncomesMenu();
    char chooseOptionFromAdditionalExpensesMenu();
public:
    BudgetManager(string filenameWithIncomes, string filenameWithExpenses, int idOfLoggedInUser)
        :incomesFile(filenameWithIncomes), expensesFile(filenameWithExpenses), ID_OF_LOGGED_IN_USER(idOfLoggedInUser) {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
        expenses = expensesFile.loadExpensesOfLoggedinUserFromFile(ID_OF_LOGGED_IN_USER);
    };
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void chosenPeriodBalance();
    void printIncomeData(Income income);
    void printExpenseData(Expense expense);
    vector<Income> loadIncomesOfLoggedInUserFromFile(int id);
    vector<Expense> loadExpensesOfLoggedInUserFromFile(int id);
};


#endif
