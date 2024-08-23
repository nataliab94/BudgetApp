#include "Utils.h"

string Utils::readLine()
{
    string phrase;
    getline(cin,phrase);
    return phrase;
}

char Utils::getCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please try again." << endl;
    }
    return character;
}
