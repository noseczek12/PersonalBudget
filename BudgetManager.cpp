#include "BudgetManager.h"

Income BudgetManager::enterNewIncomeData() {
    Income income;
    AuxiliaryMethods auxiliaryMethods;
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeIdFromFile()+1);
    income.setUserId(ID_OF_LOGGED_IN_USER);

    choice = chooseOptionFromAdditionalMenu();

    switch (choice) {
    case '1':
        int date;
        date = auxiliaryMethods.getCurrentDate();
        income.setDate(date);
        break;
    case '2':
        string inputDate;
        int convertedInputDate;
        inputDate = auxiliaryMethods.loadLine();
        convertedInputDate = auxiliaryMethods.removeDelimitersAndConvertToInt();
        if(checkDateValidity(convertedInputDate) == true)
            income.setDate(convertedInputDate);
        else
            cout << "Entered date is not valid. Please try again." << endl;
        break;
    default:
        cout << endl << "There is no such option in the menu." << endl << endl;
        system("pause");
        break;
    }

    string item;
    cout << "Enter item of income: ";
    item = auxiliaryMethods.loadLine();
    income.setItem(item);

    string amount;
    cout << "Enter amount of income: ";
    amount = auxiliaryMethods.loadLine();
    amount = auxiliaryMethods.changeCommaToDot();
    income.setAmount(amount);

    return income;
}

Expense BudgetManager::enterNewExpenseData() {

}

char BudgetManager::chooseOptionFromAdditionalMenu()
{
    char choice;

    system("cls");
    cout << "Choose date of income: " << endl;
    cout << "1. Current day." << endl;
    cout << "2. Another date." << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}

void BudgetManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterNewIncomeData();

    incomes.push_back(income);
    if(incomesFile.addIncomeToFile(income))
        cout << "New income has been added." << endl;
    else
        cout << "Error! Cannot add income to file." << endl;
    system("pause");
}

void BudgetManager::addExpense() {

}

void BudgetManager::currentMonthBalance() {

}

void BudgetManager::chosenPeriodBalance() {

}
