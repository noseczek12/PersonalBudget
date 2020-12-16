#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{

}

void PersonalBudget::userLogging()
{

}

void PersonalBudget::userLogout()
{

}

bool PersonalBudget::isuserLoggedIn()
{

}

void PersonalBudget::addIncome()
{

}

void PersonalBudget::addExpense()
{

}

void PersonalBudget::currentMonthBalance()
{

}

void PersonalBudget::chosenPeriodBalance()
{

}

void PersonalBudget::changePasswordOfLoggedInUser()
{

}

char PersonalBudget::chooseOptionFromMainMenu()
{
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

char PersonalBudget::chooseOptionFromUserMenu()
{
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
