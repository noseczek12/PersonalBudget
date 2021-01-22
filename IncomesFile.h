#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomesFile : public XmlFile {
    const string FILENAME_WITH_INCOMES;
    string temporaryIncomesFileName;
    int lastIncomeId;
    AuxiliaryMethods auxiliaryMethods;
    void deleteFile();
    void changeFilename();
public:
    IncomesFile(string fileName):
        XmlFile(fileName) {
        lastIncomeId = 0;
    };
    vector<Income> loadIncomesOfLoggedInUserFromFile(int id);
    Income getIncomeData();
    void setLastIncomeId();
    int getLastIncomeId();
    void addIncomeToFile(Income income);
    int getLastIncomeIdFromFile();
};


#endif
