#include "ExpensesFile.h"

void ExpensesFile::deleteFile() {

}

void ExpensesFile::changeFilename() {

}

vector<Expense> ExpensesFile::loadExpensesOfLoggedinUserFromFile(int id) {
    Expense expense;
    vector<Expense> expenses;
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        cout << "Can't open file. File " << getFileName() << " doesn't exist." << endl;
        system("pause");
    } else {
        string singleUserData = "";
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            singleUserData = xml.GetData();
            expense.setExpenseId(atoi(singleUserData.c_str()));
            xml.FindElem("UserId");
            singleUserData = xml.GetData();
            expense.setUserId(atoi(singleUserData.c_str()));
            xml.FindElem("Date");
            singleUserData = xml.GetData();
            expense.setDate(singleUserData);
            xml.FindElem("Item");
            singleUserData = xml.GetData();
            expense.setItem(singleUserData);
            xml.FindElem("Amount");
            singleUserData = xml.GetData();
            expense.setAmount(singleUserData);
            expenses.push_back(expense);
            xml.OutOfElem();
        }
    }
    return expenses;
}

Expense ExpensesFile::getExpenseData() {

}

void ExpensesFile::setLastUserId() {

}

int ExpensesFile::getLastUserId() {

}

bool ExpensesFile::addExpenseToFile() {

}

int ExpensesFile::getLastUserIdFromFile() {

}
