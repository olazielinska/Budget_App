#include "AuxilaryMethods.h"

char AuxilaryMethods::readCharacter() {
    string input = "";

    while (true) {
        cin.sync();
        getline(cin, input);

        if (input.length() == 1) {
            return input[0];
        }
        cout << "This isn't single character. Try again." << endl;
    }
}

string AuxilaryMethods::loadLine() {
    string input= "";

    cin.sync();
    getline(cin, input);
    return input;
}

string AuxilaryMethods::convertDecimalPointFromCommaToDot(string stringNumber) {
    for(char c : stringNumber) {
        if(c == ',')
            c = '.';
    }
    return stringNumber;
}

char AuxilaryMethods::changeToLowercase(char letter) {
    return tolower(letter);
}

string AuxilaryMethods::loadNumber() {
    string stringNumber;
    bool isNumber;

    do {
        cin >> stringNumber;
        isNumber = true;

        for(char c : stringNumber) {
            if(!(isdigit(c) || c == '.' || c == ',')) {
                isNumber = false;
            }
        }
        if(!(isdigit(stringNumber[0])) || !(isdigit(stringNumber[stringNumber.length() - 1])))
            isNumber = false;
        if(!isNumber)
            cout << "Enter correct number: ";
    } while(!isNumber);
    return stringNumber;
}
