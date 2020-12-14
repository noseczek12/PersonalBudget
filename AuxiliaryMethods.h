#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntToString(int number);
    static char loadCharacter();
    static string loadLine();
    static int LoadInteger();
    static int convertStringtoInt(string number);
    static string getNumber(string text, int charPosition);
    static string changeCommaToDot();
    static bool isDateValid();
    static int howManydaysHasCurrentMonth();
    static int compareTwoDates();
};

#endif
