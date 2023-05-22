#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <string>
#include <ctype.h>
#include <sstream>

using namespace std;

class AuxilaryMethods {
public:
    static char readCharacter();
    static string loadLine();
    static string convertDecimalPointFromCommaToDot(string stringNumber);
    static char changeToLowercase(char letter);
    static string loadNumber();
};

#endif
