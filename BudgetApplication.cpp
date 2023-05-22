#include "BudgetApplication.h"

void BudgetApplication::registerUser() {
    userManager.registerUser();
}

void BudgetApplication::logInUser() {
    userManager.logInUser();

    if(ifUserIsLoggedIn()) {
        budgetManager = new BudgetManager(INCOMES_FILENAME, EXPENSES_FILENAME, userManager.getLoggedUserId());
    }
}

bool BudgetApplication::ifUserIsLoggedIn() {
    return userManager.ifUserIsLoggedIn();
}

void BudgetApplication::addIncome() {
     budgetManager -> addIncome();
}

void BudgetApplication::addExpense() {
      budgetManager -> addExpense();
}

void BudgetApplication::showCurrentMonthBalance() {
    budgetManager -> showCurrentMonthBalance();
}

void BudgetApplication::showPreviousMonthBalance() {
     budgetManager -> showPreviousMonthBalance();
}

void BudgetApplication::showSelectedPeriodBalance() {
     budgetManager -> showSelectedPeriodBalance();
}

void BudgetApplication::changePasswordOfLoggedInUser() {
     userManager.changePasswordOfLoggedInUser();
}

void BudgetApplication::logOutUser() {
    userManager.logOutUser();
    delete budgetManager;
    budgetManager = NULL;
}
