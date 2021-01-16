#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Income.h"
#include "Expense.h"
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class BudgetManager {
    int ID_OF_LOGGED_IN_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    //FileWithExpenses fileWithExpenses;
    IncomesFile incomesFile;
    Income enterNewIncomeData();
    Expense enterNewExpenseData();
    char chooseOptionFromAdditionalMenu();
public:
    BudgetManager(string filenameWithIncomes, int idOfLoggedInUser)
    :  incomesFile(filenameWithIncomes), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        incomes = incomesFile.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void chosenPeriodBalance();
    vector<Income> loadIncomesOfLoggedInUserFromFile();
};


#endif
