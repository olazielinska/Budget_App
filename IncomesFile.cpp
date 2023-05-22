#include "IncomesFile.h"

vector <Income> IncomesFile::loadLoggedInUserIncomesFromFile(int loggedInUserId) {
    vector <Income> incomes;
    CMarkup xmlFile;
    Income income;

    xmlFile.Load(INCOMES_FILENAME);

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("Income")) {
        xmlFile.IntoElem();
        xmlFile.FindElem("IncomeId");
        income.setIncomeId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        lastIncomeId = income.getIncomeId();
        xmlFile.FindElem("UserId");
        income.setUserId(atoi(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.FindElem("Date");
        income.setDate(xmlFile.GetData());
        xmlFile.FindElem("Item");
        income.setItem(xmlFile.GetData());
        xmlFile.FindElem("Amount");
        income.setAmount(xmlFile.GetData());
        if(income.getUserId() == loggedInUserId)
            incomes.push_back(income);
        xmlFile.OutOfElem();
    }
    return incomes;
}

void IncomesFile::addIncomeToFile(Income& income) {
    CMarkup xmlFile;
    bool fileExists = xmlFile.Load(INCOMES_FILENAME);

    if(!fileExists) {
        xmlFile.AddElem("Incomes");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("Income");
    xmlFile.IntoElem();
    xmlFile.AddElem("IncomeId", income.getIncomeId());
    xmlFile.AddElem("UserId", income.getUserId());
    xmlFile.AddElem("Date", income.getDate());
    xmlFile.AddElem("Item", income.getItem());
    xmlFile.AddElem("Amount", income.getAmount());
    xmlFile.Save(INCOMES_FILENAME);
}

int IncomesFile::getLastIncomeId() {
    return lastIncomeId;
}
