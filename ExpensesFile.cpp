#include "ExpensesFile.h"

vector <Expense> ExpensesFile::loadLoggedInUserExpensesFromFile(int loggedInUserId) {
    vector <Expense> expenses;
    CMarkup xmlFile;
    Expense expense;

    xmlFile.Load(EXPENSES_FILENAME);

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("Expense")) {
        xmlFile.IntoElem();
        xmlFile.FindElem("ExpenseId");
        expense.setExpenseId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        lastExpenseId = expense.getExpenseId();
        xmlFile.FindElem("UserId");
        expense.setUserId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.FindElem("Date");
        expense.setDate(xmlFile.GetData());
        xmlFile.FindElem("Item");
        expense.setItem(xmlFile.GetData());
        xmlFile.FindElem("Amount");
        expense.setAmount(xmlFile.GetData());
        if(expense.getUserId() == loggedInUserId)
            expenses.push_back(expense);
        xmlFile.OutOfElem();
    }
    return expenses;
}

void ExpensesFile::addExpenseToFile(Expense& expense) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(EXPENSES_FILENAME);

    if(!fileExists) {
        xmlFile.AddElem("Expenses");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("Expense");
    xmlFile.IntoElem();
    xmlFile.AddElem("ExpenseId", expense.getExpenseId());
    xmlFile.AddElem("UserId", expense.getUserId());
    xmlFile.AddElem("Date", expense.getDate());
    xmlFile.AddElem("Item", expense.getItem());
    xmlFile.AddElem("Amount", expense.getAmount());
    xmlFile.Save(EXPENSES_FILENAME);
}

int ExpensesFile::getLastExpenseId() {
    return lastExpenseId;
}
