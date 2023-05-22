#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "DateManager.h"

class BudgetManager {

    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    DateManager dateManager;
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income provideNewIncomeDetails();
    Expense provideNewExpenseDetails();
    void showData(vector <Income>& selectedIncomes, vector <Expense>& selectedExpenses);
    void showBalance(vector <Income>& selectedIncomes, vector <Expense>& selectedExpenses);
    float calculateBalace(vector <auto>& selectedData);
public:
    BudgetManager(string filenameWithIncomes, string filenameWithExpenses, int loggedInUserId)
        : incomesFile(filenameWithIncomes), expensesFile(filenameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = incomesFile.loadLoggedInUserIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = expensesFile.loadLoggedInUserExpensesFromFile(LOGGED_IN_USER_ID);
    }
    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
};

#endif
