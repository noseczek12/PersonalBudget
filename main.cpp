#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml");
    vector <Income> incomes;
    vector <Expense> expenses;
    char choice;

    while (true) {
        if (personalBudget.isuserLoggedIn()==0) {
            choice = personalBudget.chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            if (incomes.empty() == true && expenses.empty() == true)
                choice = personalBudget.chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.currentMonthBalance();
                break;
            case '4':
                personalBudget.chosenPeriodBalance();
                break;
            case '5':
                personalBudget.changePasswordOfLoggedInUser();
                break;
            case '6':
                personalBudget.userLogout();
                break;
            }
        }
    }
    return 0;
}
