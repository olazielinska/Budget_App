#include <iostream>

#include "BudgetApplication.h"
#include "AuxilaryMethods.h"

using namespace std;

char selectOptionFromMainMenu() {
    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Sign up" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    return AuxilaryMethods::readCharacter();
}

char selectOptionFromLoggedUserMenu() {

    system("cls");
    cout << " >>> YOUR BUDGET <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show current month balance" << endl;
    cout << "4. Show previous month balance" << endl;
    cout << "5. Show selected period balance" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";

    return AuxilaryMethods::readCharacter();
}

int main() {
    char choice = {};
    BudgetApplication budgetApplication ("Users.xml", "Incomes.xml", "Expenses.xml");

    while(true) {
        if(!budgetApplication.ifUserIsLoggedIn()) {
            choice = selectOptionFromMainMenu();

            switch(choice) {
            case '1':
                budgetApplication.registerUser();
                break;
            case '2':
                budgetApplication.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "The option isn't available in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = selectOptionFromLoggedUserMenu();

            switch(choice) {
            case '1':
                budgetApplication.addIncome();
                break;
            case '2':
                budgetApplication.addExpense();
                break;
            case '3':
                budgetApplication.showCurrentMonthBalance();
                break;
            case '4':
                budgetApplication.showPreviousMonthBalance();
                break;
            case '5':
                budgetApplication.showSelectedPeriodBalance();
                break;
            case '6':
                budgetApplication.changePasswordOfLoggedInUser();
                break;
            case '7':
                budgetApplication.logOutUser();
                break;
            default:
                cout << endl << "The option isn't available in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
