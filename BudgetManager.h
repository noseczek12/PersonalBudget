#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
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
    //FileWithIncomes fileWithIncomes;
    Income enterNewIncomeData();
    Expense enterNewExpenseData();
    char chooseOptionFromAdditionalMenu();
public:
    BudgetManager(){};
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void chosenPeriodBalance();
};


#endif
