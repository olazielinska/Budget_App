#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>

using namespace std;

class DateManager {

    bool checkIfDateIsWithinAppropriateRange(string inputDate);
    bool checkIfDateHasValidFormat(string inputDate);
    tm getFirstDayOfMonth(tm date);
    tm getLastDayOfMonth(tm date);
    tm getPreviousMonth();
public:
    string getTodayStringDate();
    bool checkIfDateIsCorrect(string inputDate);
    bool checkIfDateIsFromCurrentMonth(string stringDate);
    bool checkIfDateIsFromPreviousMonth (string stringDate);
    bool checkIfDateIsFromEnteredPeriod(string startDate, string endDate, string stringDate);
    tm convertStringToTime (string stringDate);
};

#endif
