#include "BudgetManager.h"

void BudgetManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING A NEW INCOME <<<" << endl << endl;
    income = provideNewIncomeDetails();

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << "The income has been added." << endl;
    system("pause");
}

Income BudgetManager::provideNewIncomeDetails() {
    Income income;
    string date = "";
    char choice;

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Is the income from today? Y - yes, N - no ";

    do {
        choice = AuxilaryMethods::changeToLowercase(AuxilaryMethods::readCharacter());
        switch(choice) {
        case 'y':
            income.setDate(dateManager.getTodayStringDate());
            break;
        case 'n':
            do {
                cout << "Provide the date in the format YYYY-mm-dd:";
                date = AuxilaryMethods::loadLine();
                if(dateManager.checkIfDateIsCorrect(date))
                    income.setDate(date);
                else {
                    cout << "The date should have the format YYYY-mm-dd and be within the range from 2000-01-01 to today." << endl << endl;
                }
            } while(!dateManager.checkIfDateIsCorrect(date));
            break;
        default:
            cout << "Provide Y - yes or N - no : ";
            break;
        }
    } while(!(choice == 'y' || choice == 'n'));

    cout << "Enter a description: ";
    income.setItem(AuxilaryMethods::loadLine());

    cout << "Enter the amount: ";
    income.setAmount(AuxilaryMethods::convertDecimalPointFromCommaToDot(AuxilaryMethods::loadNumber()));
    return income;
}

void BudgetManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> ADDING A NEW EXPENSE <<<" << endl << endl;
    expense = provideNewExpenseDetails();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout << "The expense has been added." << endl;
    system("pause");
}

Expense BudgetManager::provideNewExpenseDetails() {
    Expense expense;
    string date = "";
    char choice;

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Is the expense from today? Y - yes, N - no ";

    do {
        choice = AuxilaryMethods::changeToLowercase(AuxilaryMethods::readCharacter());
        switch(choice) {
        case 'y':
            expense.setDate(dateManager.getTodayStringDate());
            break;
        case 'n':
            do {
                cout << "Provide the date in the format YYYY-mm-dd:";
                date = AuxilaryMethods::loadLine();
                if(dateManager.checkIfDateIsCorrect(date))
                    expense.setDate(date);
                else {
                    cout << "The date should have the format YYYY-mm-dd and be within the range from 2000-01-01 to today." << endl << endl;
                }
            } while(!dateManager.checkIfDateIsCorrect(date));
            break;
        default:
            cout << "Provide Y - yes or N - no : ";
            break;
        }
    } while(!(choice == 'y' || choice == 'n'));

    cout << "Enter a description: ";
    expense.setItem(AuxilaryMethods::loadLine());

    cout << "Enter the amount: ";
    expense.setAmount(AuxilaryMethods::convertDecimalPointFromCommaToDot(AuxilaryMethods::loadNumber()));
    return expense;
}

void BudgetManager::showCurrentMonthBalance() {
    vector <Income> selectedIncomes;
    vector <Expense> selectedExpenses;

    for(auto income : incomes) {
        if(dateManager.checkIfDateIsFromCurrentMonth(income.getDate()))
            selectedIncomes.push_back(income);
    }

    for(auto expense : expenses) {
        if(dateManager.checkIfDateIsFromCurrentMonth(expense.getDate()))
            selectedExpenses.push_back(expense);
    }

    sort(selectedIncomes.begin(), selectedIncomes.end());
    sort(selectedExpenses.begin(), selectedExpenses.end());

    showData(selectedIncomes, selectedExpenses);
    showBalance(selectedIncomes, selectedExpenses);
}

void BudgetManager::showPreviousMonthBalance() {
    vector <Income> selectedIncomes;
    vector <Expense> selectedExpenses;

    for(auto income : incomes) {
        if(dateManager.checkIfDateIsFromPreviousMonth(income.getDate()))
            selectedIncomes.push_back(income);
    }

    for(auto expense : expenses) {
        if(dateManager.checkIfDateIsFromPreviousMonth(expense.getDate()))
            selectedExpenses.push_back(expense);
    }

    sort(selectedIncomes.begin(), selectedIncomes.end());
    sort(selectedExpenses.begin(), selectedExpenses.end());

    showData(selectedIncomes, selectedExpenses);
    showBalance(selectedIncomes, selectedExpenses);
}

void BudgetManager::showSelectedPeriodBalance() {
    string startDate = "", endDate = "";
    vector <Income> selectedIncomes;
    vector <Expense> selectedExpenses;

    do {
        cout << "Provide the start date in the format YYYY-mm-dd:";
        startDate = AuxilaryMethods::loadLine();
        cout << "Provide the end date in the format YYYY-mm-dd:";
        endDate =  AuxilaryMethods::loadLine();
        if(!(dateManager.checkIfDateIsCorrect(startDate) || dateManager.checkIfDateIsCorrect(endDate)))
            cout << "The date should have the format YYYY-mm-dd and be within the range from 2000-01-01 to today." << endl << endl;
    } while(!(dateManager.checkIfDateIsCorrect(startDate) || dateManager.checkIfDateIsCorrect(endDate)));

    for(auto income : incomes) {
        if(dateManager.checkIfDateIsFromEnteredPeriod(startDate, endDate, income.getDate()))
            selectedIncomes.push_back(income);
    }

    for(auto expense : expenses) {
        if(dateManager.checkIfDateIsFromEnteredPeriod(startDate, endDate, expense.getDate()))
            selectedExpenses.push_back(expense);

    }

    sort(selectedIncomes.begin(), selectedIncomes.end());
    sort(selectedExpenses.begin(), selectedExpenses.end());

    showData(selectedIncomes, selectedExpenses);
    showBalance(selectedIncomes, selectedExpenses);
}

void BudgetManager::showData(vector <Income>& selectedIncomes, vector <Expense>& selectedExpense) {

    system("cls");
    cout << endl << "INCOMES:" << endl;
    cout << "-----------------------------------" << endl;

    for(auto income : selectedIncomes) {
        cout << "Date:                   " << income.getDate() << endl;
        cout << "Item:                   " << income.getItem() << endl;
        cout << "Amount:                 " << income.getAmount() << endl << endl;
    }

    cout << endl << "EXPENSES:" << endl;
    cout << "-----------------------------------" << endl;

    for(auto expense : selectedExpense) {
        cout << "Date:                   " << expense.getDate() << endl;
        cout << "Item:                   " << expense.getItem() << endl;
        cout << "Amount:                 " << expense.getAmount() << endl << endl;
    }
}

void BudgetManager::showBalance(vector <Income>& selectedIncomes, vector <Expense>& selectedExpenses) {
    cout << endl << "TOTAL INCOMES:  " << calculateBalace(selectedIncomes);
    cout << endl << "TOTAL EXPENSES: " << calculateBalace (selectedExpenses);
    cout << endl << "TOTAL BALANCE:  " << calculateBalace(selectedIncomes) - calculateBalace (selectedExpenses) << endl;
    system("pause");
}

float BudgetManager::calculateBalace(vector <auto>& selectedData) {
    float balance = 0.0;

    for(auto data : selectedData) {
        balance += stof(data.getAmount());
    }
    return balance;
}
