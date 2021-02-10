#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
public:
    static string convertIntToString(int number);
    static char loadCharacter();
    static string loadLine();
    static int LoadInteger();
    static int convertStringtoInt(string number);
    static string getNumber(string text, int charPosition);
    static string changeCommaToDot(string text);
    static bool isDateValid();
    static int howManydaysHasCurrentMonth();
    static int compareTwoDates();
    static string getCurrentDate();
    static int checkDateValidity(string enteredDate);
    static string removeDelimiters(string str);
    static int getNumberOfDaysInEnteredMonth(int month, int year);
    static string getDateWithFirstDayOfCurrentMonth();
    static string getDateWithLastDayOfCurrentMonth();
    static string getDateWithDelimiters(string str);
};

#endif
