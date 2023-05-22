#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxilaryMethods.h"

using namespace std;

class IncomesFile {

    const string INCOMES_FILENAME;
    int lastIncomeId;
public:
    IncomesFile(string filenameWithIncomes) : INCOMES_FILENAME (filenameWithIncomes) {
        lastIncomeId = 0;
    };

    vector <Income> loadLoggedInUserIncomesFromFile(int loggedInUserId);
    void addIncomeToFile(Income& income);
    int getLastIncomeId();
};

#endif
