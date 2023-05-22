#ifndef BUDGETAPPLICATION_H
#define BUDGETAPPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class BudgetApplication {

    UserManager userManager;
    BudgetManager* budgetManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;
public:
    BudgetApplication(string filenameWithUsers, string filenameWithIncomes, string fileNameWithExpenses)
        : userManager(filenameWithUsers), INCOMES_FILENAME(filenameWithIncomes), EXPENSES_FILENAME(fileNameWithExpenses) {
        budgetManager = NULL;
    };
    ~BudgetApplication() {
        delete budgetManager;
        budgetManager = NULL;
    }
    void registerUser();
    void logInUser();
    bool ifUserIsLoggedIn();
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
    void changePasswordOfLoggedInUser();
    void logOutUser();
};
#endif
