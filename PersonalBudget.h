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
    /*KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenedzer = NULL;
        vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }
    */
    PersonalBudget(){};
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
