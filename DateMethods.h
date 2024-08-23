#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class DateMethods
{

    void calculateCurrentDate(map <string, int> &currentDate);
    int  isYearLeap(int year);



public:


    bool validateDate(string date);
    int  convertStringDateToInt(string dateAsString);
    string convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate();
    int getCurrentMonthFirstDayDate();
    int getPreviousMonthLastDayDate();
    int getPreviousMonthFirstDayDate();
    int returnNumberOfDaysInMonth(int year, int month);

};

#endif
