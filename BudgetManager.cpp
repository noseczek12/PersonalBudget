#include "BudgetManager.h"

Income BudgetManager::enterNewIncomeData() {
    Income income;
    AuxiliaryMethods auxiliaryMethods;
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeIdFromFile()+1);
    income.setUserId(ID_OF_LOGGED_IN_USER);

    choice = chooseOptionFromAdditionalMenu();

    switch (choice) {
    case '1': {
        string date;
        date = auxiliaryMethods.getCurrentDate();
        income.setDate(date);
        break;
    }
    case '2': {
        string inputDate, removedDelimitersDate;
        cout << "Please input date in yyyy-mm-dd format: ";
        inputDate = auxiliaryMethods.loadLine();
        removedDelimitersDate = auxiliaryMethods.removeDelimiters(inputDate);
        if(auxiliaryMethods.checkDateValidity(removedDelimitersDate) == true)
            income.setDate(removedDelimitersDate);
        else
            cout << "Entered date is not valid. Please try again." << endl;
        break;
    }
    default: {
        cout << endl << "There is no such option in the menu." << endl << endl;
        system("pause");
        break;
    }
    }
    system("cls");
    string item;
    cout << "Enter item of income: ";
    item = auxiliaryMethods.loadLine();
    income.setItem(item);

    string amount;
    cout << "Enter amount of income: ";
    amount = auxiliaryMethods.loadLine();
    amount = auxiliaryMethods.changeCommaToDot(amount);
    income.setAmount(amount);

    return income;
}

Expense BudgetManager::enterNewExpenseData() {

}

char BudgetManager::chooseOptionFromAdditionalMenu() {
    char choice;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    cout << "Choose date of income: " << endl;
    cout << "1. Current day." << endl;
    cout << "2. Another date." << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}

void BudgetManager::addIncome() {
    Income income;
    income = enterNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    cout << "New income has been added." << endl;
    system("pause");
}

void BudgetManager::addExpense() {

}

void BudgetManager::currentMonthBalance() {

}

void BudgetManager::chosenPeriodBalance() {

}

vector<Income> BudgetManager::loadIncomesOfLoggedInUserFromFile(int id) {
    incomesFile.loadIncomesOfLoggedInUserFromFile(id);
}
