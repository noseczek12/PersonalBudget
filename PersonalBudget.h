#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class PersonalBudget {
    AuxiliaryMethods auxiliaryMethods;
    UserManager userManager;
    BudgetManager *budgetManager;
    const string FILENAME_WITH_INCOMES;
    const string FILENAME_WITH_EXPENSES;
public:
    PersonalBudget(string filenameWithUsers, string filenameWithIncomes, string filenameWithExpenses)
        : userManager(filenameWithUsers), FILENAME_WITH_INCOMES(filenameWithIncomes), FILENAME_WITH_EXPENSES(filenameWithExpenses) {
        budgetManager = NULL;
        vector<Income> loadIncomesOfLoggedInUserFromFile();
        vector<Expense> loadExpensesOfLoggedInUserFromFile();
    };
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    }
    void userRegistration();
    void userLogging();
    void userLogout();
    int isuserLoggedIn();
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void chosenPeriodBalance();
    void changePasswordOfLoggedInUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    vector<Income> loadIncomesOfLoggedInUserFromFile();
    vector<Expense> loadExpensesOfLoggedInUserFromFile();
};


#endif
