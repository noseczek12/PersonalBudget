#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "UserManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpensesFile : public XmlFile {
    const string FILENAME_WITH_EXPENSES;
    string temporaryExpensesFileName;
    int lastExpenseId;
    AuxiliaryMethods auxiliaryMethods;
    void deleteFile();
    void changeFilename();
public:
    ExpensesFile(string fileName):
        XmlFile(fileName) {
        lastExpenseId = 0;
    };
    vector<Expense> loadExpensesOfLoggedinUserFromFile(int id);
    Expense getExpenseData();
    void setLastUserId();
    int getLastUserId();
    bool addExpenseToFile(Expense expense);
    int getLastExpenseIdFromFile();
};


#endif
