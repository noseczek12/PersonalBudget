#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class PersonalBudget {
    //MetodyPomocnicze metodyPomocnicze;
    //UzytkownikMenedzer uzytkownikMenedzer;
    //AdresatMenedzer *adresatMenedzer;
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
    void currrentMonthBalance();
    void chosenPeriodBalance();
    void changePasswordOfLoggedInUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
};


#endif
