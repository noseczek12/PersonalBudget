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
    int lastIncomeId;
    //AuxiliaryMethods auxiliaryMethods;
    void deleteFile();
    void changeFilename();
public:
    IncomesFile(){};
    vector<Income> loadIncomesOfLoggedinUserFromFile();
    Income getIncomeData();
    void setLastIncomeId();
    int getLastIncomeId();
    bool addIncomeToFile();
    int getLastIncomeIdFromFile();
};


#endif
