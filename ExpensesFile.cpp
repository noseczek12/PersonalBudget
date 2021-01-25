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

bool ExpensesFile::addExpenseToFile(Expense expense) {
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem( "Expenses" );
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "ExpenseId", AuxiliaryMethods::convertIntToString(expense.getExpenseId()));
    xml.AddElem( "UserId", AuxiliaryMethods::convertIntToString(expense.getUserId()));
    xml.AddElem( "Date", expense.getDate());
    xml.AddElem( "Item", expense.getItem() );
    xml.AddElem( "Amount", expense.getAmount() );
    xml.Save(getFileName());
}

int ExpensesFile::getLastExpenseIdFromFile() {
    int idCount = 0;
    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
    if(!fileExists) {
        return 1;
    } else {
        string singleUserData = "";
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            singleUserData = xml.GetData();
            idCount = auxiliaryMethods.convertStringtoInt(singleUserData);
            xml.OutOfElem();
        }
    }
    return idCount+1;
}
