#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogging() {
    userManager.userLogging();
    if(userManager.isUserLoggedIn()) {
        budgetManager = new BudgetManager(FILENAME_WITH_INCOMES, FILENAME_WITH_EXPENSES, userManager.getIdOfLoggedInUser());
    }
}

void PersonalBudget::userLogout() {
    userManager.userLogout();
}

int PersonalBudget::isuserLoggedIn() {
    userManager.isUserLoggedIn();
}

void PersonalBudget::addIncome() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->addIncome();
    } else {
        cout << "If you want to add income, you must be logged in !" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->addExpense();
    } else {
        cout << "If you want to add expense, you must be logged in !" << endl;
        system("pause");
    }
}

void PersonalBudget::currentMonthBalance() {

}

void PersonalBudget::chosenPeriodBalance() {

}

void PersonalBudget::changePasswordOfLoggedInUser() {
    userManager.changePasswordOfLoggedInUser();
}

char PersonalBudget::chooseOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add new user" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}

char PersonalBudget::chooseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Chosen period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "5. Change password" << endl;
    cout << "6. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = auxiliaryMethods.loadCharacter();

    return choice;
}

vector<Income> PersonalBudget::loadIncomesOfLoggedInUserFromFile() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->loadIncomesOfLoggedInUserFromFile(userManager.isUserLoggedIn());
    }
}

vector<Expense> PersonalBudget::loadExpensesOfLoggedInUserFromFile() {
    if(userManager.isUserLoggedIn()) {
        budgetManager->loadExpensesOfLoggedInUserFromFile(userManager.isUserLoggedIn());
    }
}
