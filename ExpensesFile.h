#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <vector>

#include "Expense.h"
#include "AuxilaryMethods.h"
#include "Markup.h"

using namespace std;

class ExpensesFile {

    const string EXPENSES_FILENAME;
    int lastExpenseId;
public:
    ExpensesFile(string filenameWithExpenses) : EXPENSES_FILENAME (filenameWithExpenses) {
        lastExpenseId = 0;
    };

    vector <Expense> loadLoggedInUserExpensesFromFile(int loggedInUserId);
    void  addExpenseToFile(Expense& expense);
    int getLastExpenseId();
};

#endif
