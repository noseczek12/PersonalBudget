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
    BudgetManager budgetManager;
    const string FILENAME_WITH_INCOMES;
    const string FILENAME_WITH_EXPENSES;
public:
    PersonalBudget(string filenameWithUsers, string filenameWithIncomes)
    : userManager(filenameWithUsers), FILENAME_WITH_INCOMES(filenameWithIncomes)
    {
        BudgetManager = NULL;
        //vector<Income> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    void userRegistration();
    void userLogging();
    void userLogout();
    bool isuserLoggedIn();
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void chosenPeriodBalance();
    void changePasswordOfLoggedInUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
};


#endif
