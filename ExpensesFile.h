#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class ExpensesFile {
    const string FILENAME_WITH_EXPENSES;
    string temporaryExpensesFileName;
    int lastUserId;
    //AuxiliaryMethods auxiliaryMethods;
    void deleteFile();
    void changeFilename();
public:
    ExpensesFile(){};
    vector<Expense> loadExpensesOfLoggedinUserFromFile();
    Expense getExpenseData();
    void setLastUserId();
    int getLastUserId();
    bool addExpenseToFile();
    int getLastUserIdFromFile();
};


#endif
