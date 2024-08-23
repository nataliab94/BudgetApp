#include "DateMethods.h"

void DateMethods::calculateCurrentDate(map<string, int> &currentDate)
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    currentDate["year"] = now->tm_year + 1900;
    currentDate["month"] = now->tm_mon + 1;
    currentDate["day"] = now->tm_mday;
}

int DateMethods::isYearLeap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool DateMethods::validateDate(string date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (month < 1 || month > 12)
        return false;

    int daysInMonth = returnNumberOfDaysInMonth(year, month);

    return day >= 1 && day <= daysInMonth;
}

int DateMethods::convertStringDateToInt(string dateAsString)
{
    string dateWithoutDashes = dateAsString;
    dateWithoutDashes.erase(remove(dateWithoutDashes.begin(), dateWithoutDashes.end(), '-'), dateWithoutDashes.end());
    return stoi(dateWithoutDashes);
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt)
{
    string dateStr = to_string(dateAsInt);
    return dateStr.substr(0, 4) + "-" + dateStr.substr(4, 2) + "-" + dateStr.substr(6, 2);
}


int DateMethods::getCurrentDate()
{
    time_t now = time(0);
    tm* timeAsStruct = localtime(&now);

    stringstream ss;
    ss << setw(4) << setfill('0') << (timeAsStruct->tm_year + 1900)
       << setw(2) << setfill('0') << (timeAsStruct->tm_mon + 1)
       << setw(2) << setfill('0') << timeAsStruct->tm_mday;

    return stoi(ss.str());
}

int DateMethods::getCurrentMonthFirstDayDate()
{
    string currentDate = convertIntDateToStringWithDashes(getCurrentDate());
    return convertStringDateToInt(currentDate.substr(0, 8) + "01");
}

int DateMethods::getPreviousMonthLastDayDate()
{
    int currentDate = getCurrentDate();

    int year = currentDate / 10000;
    int month = (currentDate / 100) % 100;

    if (month == 1)
    {
        year -= 1;
        month = 12;
    }
    else
    {
        month -= 1;
    }
    int day = returnNumberOfDaysInMonth(year, month);

    int previousMonthLastDay = year * 10000 + month * 100 + day;

    return previousMonthLastDay;

}


int DateMethods::getPreviousMonthFirstDayDate()
{
    int currentDate = getCurrentDate();


    int year = currentDate / 10000;
    int month = (currentDate / 100) % 100;
    int day = currentDate % 100;


    if (month == 1)
    {
        year -= 1;
        month = 12;
    }
    else
    {
        month -= 1;
    }


    int previousMonthFirstDay = year * 10000 + month * 100 + 1;

    return previousMonthFirstDay;
}


int DateMethods::returnNumberOfDaysInMonth(int year, int month)
{
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isYearLeap(year))
        return 29;

    return daysInMonth[month - 1];
}
