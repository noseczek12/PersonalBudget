#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::loadCharacter() {
    string input = "";
    char character  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "Invalid character. Please type again." << endl;
    }
    return character;
}

string AuxiliaryMethods::loadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int AuxiliaryMethods::LoadInteger() {
    string input = "";
    int number = 0;

    while (true) {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It is not a number. Please type again. " << endl;
    }
    return number;
}

int AuxiliaryMethods::convertStringtoInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::getNumber(string text, int charPosition) {
    string number = "";
    while(isdigit(text[charPosition]) == true) {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

string AuxiliaryMethods::changeCommaToDot(string str) {
    char ch1 = ',', ch2 = '.';
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ch1)
            str[i] = ch2;
    }
    return str;
}

bool AuxiliaryMethods::isDateValid() {

}

int AuxiliaryMethods::howManydaysHasCurrentMonth() {

}

int AuxiliaryMethods::compareTwoDates() {

}

string AuxiliaryMethods::getCurrentDate() {
    char s[10];
    string date = s;
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentDay = now->tm_mday;
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;
    sprintf(s, "%04d%02d%02d", currentYear, currentMonth, currentDay);
    return s;
}

bool AuxiliaryMethods::checkDateValidity(string enteredDate) {
    int enteredDateConvertedToInt;
    int lastDayOfCurrentMonth;
    int dateLimit = 20010101;
    enteredDateConvertedToInt = convertStringtoInt(enteredDate);
    lastDayOfCurrentMonth = getDateWithLastDayOfCurrentMonth();
    if(enteredDateConvertedToInt >= dateLimit && enteredDateConvertedToInt <= lastDayOfCurrentMonth)
        return true;
    else
        return false;
}

string AuxiliaryMethods::removeDelimiters(string str) {
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    return str;
}

int AuxiliaryMethods::getDateWithLastDayOfCurrentMonth() {
    time_t t = time(0);
    tm* now = localtime(&t);
    int LastDayOfMonth = getNumberOfDaysInCurrentMonth();
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;
    char s[10];
    sprintf(s, "%04d%02d%02d", currentYear, currentMonth, LastDayOfMonth);
    string date = s;
    int convertedDateToInt = stoi(s);
    return convertedDateToInt;
}

int AuxiliaryMethods::getNumberOfDaysInCurrentMonth() {
    time_t t = time(0);
    tm* now = localtime(&t);
    int month = now->tm_mon + 1;
    int year = now->tm_year + 1900;
    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}
