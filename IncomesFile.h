#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Income.h"
//#include "UzytkownikMenedzer.h"
//#include "AdresatMenedzer.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class IncomesFile {
    const string FILENAME_WITH_INCOMES;
    string temporaryIncomesFileName;
    int lastUserId;
    //AuxiliaryMethods auxiliaryMethods;
    void deleteFile();
    void changeFilename();
public:
    IncomesFile(){};
    vector<Income> loadIncomesOfLoggedinUserFromFile();
    Income getIncomeData();
    void setLastUserId();
    int getLastUserId();
    bool addIncomeToFile();
    int getLastUserIdFromFile();
};


#endif
