#include "DateManager.h"

string DateManager::getTodayStringDate() {
    auto now = chrono::system_clock::now();
    auto nowTime = chrono::system_clock::to_time_t(now);
    tm* nowTM = localtime(&nowTime);

    ostringstream oss;
    oss << put_time(nowTM, "%Y-%m-%d");
    return oss.str();
}

tm DateManager::convertStringToTime(string stringDate) {
    tm date = {};

    istringstream ss (stringDate);
    ss >> get_time(&date, "%Y-%m-%d");
    return date;
}

bool DateManager::checkIfDateIsCorrect(string inputDate) {
    return((checkIfDateHasValidFormat(inputDate) && checkIfDateIsWithinAppropriateRange(inputDate)) ? true : false);

}

bool DateManager::checkIfDateHasValidFormat(string inputDate) {
    tm date = {};

    istringstream iss(inputDate);
    iss >> get_time(&date, "%Y-%m-%dd");

    return (iss ? true : false);
}

bool DateManager::checkIfDateIsWithinAppropriateRange(string inputDate) {
    const string FIRST_DATE = "2000-01-01";

    tm startDate = convertStringToTime(FIRST_DATE);
    tm actualDate = convertStringToTime(getTodayStringDate());
    tm enteredDate = convertStringToTime(inputDate);

    auto startTime = chrono::system_clock::from_time_t(mktime(&startDate));
    auto actualTime = chrono::system_clock::from_time_t(mktime(&actualDate));
    auto enteredTime = chrono::system_clock::from_time_t(mktime(&enteredDate));

    return ((enteredTime >= startTime && enteredTime <= actualTime) ? true : false);
}

bool DateManager::checkIfDateIsFromCurrentMonth(string stringDate) {
    tm actualDate = convertStringToTime(getTodayStringDate());
    tm firstDayOfActualMonth = getFirstDayOfMonth(actualDate);
    tm enteredDate = convertStringToTime(stringDate);

    auto firstDayOfActualMonthTime = chrono::system_clock::from_time_t(mktime(&firstDayOfActualMonth));
    auto actualTime = chrono::system_clock::from_time_t(mktime(&actualDate));
    auto enteredTime = chrono::system_clock::from_time_t(mktime(&enteredDate));

    return ((enteredTime >= firstDayOfActualMonthTime && enteredTime <= actualTime) ? true : false);
}

tm DateManager::getFirstDayOfMonth(tm date) {
    date.tm_mday = 1;
    return date;
}

tm DateManager::getPreviousMonth() {
    tm date = convertStringToTime(getTodayStringDate());

    if (date.tm_mon == 0) {
        date.tm_year -= 1;
        date.tm_mon = 11;
    } else {
        date.tm_mon -= 1;
    }
    return date;
}

tm DateManager::getLastDayOfMonth(tm date) {
    date.tm_mon += 1;
    date.tm_mday = 1;
    date.tm_mday -= 1;
    return date;
}

bool DateManager::checkIfDateIsFromPreviousMonth(string stringDate) {
    tm firstDayOfPreviousMonth = getFirstDayOfMonth(getPreviousMonth());
    tm lastDayOfPreviousMonth = getLastDayOfMonth(getPreviousMonth());
    tm enteredDate = convertStringToTime(stringDate);

    auto firstTime = chrono::system_clock::from_time_t(mktime(&firstDayOfPreviousMonth));
    auto lastTime = chrono::system_clock::from_time_t(mktime(&lastDayOfPreviousMonth));
    auto enteredTime = chrono::system_clock::from_time_t(mktime(&enteredDate));

    return ((enteredTime >= firstTime && enteredTime <= lastTime) ? true : false);
}

bool DateManager::checkIfDateIsFromEnteredPeriod(string startDate, string endDate, string stringDate) {
    tm firstDayOfEnteredPeriod = convertStringToTime(startDate);
    tm lastDayOfEneteredPeriod = convertStringToTime(endDate);
    tm enteredDate = convertStringToTime(stringDate);

    auto firstTime = chrono::system_clock::from_time_t(mktime(&firstDayOfEnteredPeriod));
    auto lastTime = chrono::system_clock::from_time_t(mktime(&lastDayOfEneteredPeriod));
    auto enteredTime = chrono::system_clock::from_time_t(mktime(&enteredDate));

    return ((enteredTime >= firstTime && enteredTime <= lastTime) ? true : false);
}
