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

string AuxiliaryMethods::changeCommaToDot(string text) {
    text.replace(text.begin(), text.end(), ',', '.');
    return text;
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
    int convertedDateToInt = stoi(s);
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentDay = now->tm_mday;
    int currentMonth = now->tm_mon + 1;
    int currentYear = now->tm_year + 1900;
    sprintf(s, "%04d%02d%02d", currentYear, currentMonth, currentDay);
    return s;
}

bool AuxiliaryMethods::checkDateValidity()
{

}

string AuxiliaryMethods::removeDelimiters(string str)
{
    str.erase(remove(str.begin(), str.end(), '-'), str.end());
    return str;
}
