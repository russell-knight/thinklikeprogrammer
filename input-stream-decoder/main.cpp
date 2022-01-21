#include <iostream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

/*
- Create endless stream of characters that are input and output to stdout
*/

/* Given an int, return the corresponding character in the alphabet
   e.g F=5, Z=26. note 0 will return ''
*/

const char changeModeChar = '#';

char decodeIntToUpperChar(int code)
{
 char upperAlphabet[27] = {'#','A','B','C','D','E','F','G','H','I','J',
                      'K','L','M','N','O','P','Q','R','S','T',
                      'U','V','W','X','Y','Z'};

    return upperAlphabet[code];
}

char decodeIntToLowerChar(int code)
{
 char lowerAlphabet[27] = {'#','a','b','c','d','e','f','g','h','i','j',
                      'k','l','m','n','o','p','q','r','s','t',
                      'u','v','w','x','y','z'};

    return lowerAlphabet[code];
}

char decodeIntToPuncChar(int code)
{
 char puncChars[9] = {'#','!','?',',','.',' ',';','"','\''};

    return puncChars[code];
}

/*
    Given the current puncutation mode, return the next mode
*/
char getNextMode(char currentMode)
{
    char nextMode;

    switch (currentMode)
    {
        case 'U':
            nextMode = 'L';
            break;
        case 'L':
            nextMode = 'P';
            break;
        case 'P':
            nextMode = 'U';
            break;
    }
    return nextMode;
}

// 18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
// should read "Right? Yes!"

int main()
{
    char mode = 'U'; // Messages start in Uppercase mode
    int digit;
    int divisor = 27;
    char nextChar;
    std::string strCode;
    std::string token;

    cout << "Enter comma delimited code: ";
    getline (cin, strCode);

    std::istringstream iss(strCode);
    
    // split string into tokens
    while (std::getline(iss, token, ','))
    {
        digit = std::stoi( token ) % divisor;

        if (digit == 0) // Change mode and divisor
        {
            mode = getNextMode(mode);
            if (mode == 'P')
            {
                divisor = 9;
            }
            else
            {
                divisor = 27;
            }
            continue;
        }

        switch(mode)
        {
            case 'U':
            cout << decodeIntToUpperChar(digit);
            break;
            case 'L':
            cout << decodeIntToLowerChar(digit);
            break;
            case 'P':
            cout << decodeIntToPuncChar(digit);
            break;
        }
        
    }
    cout << "\nEnd of code-read.";
}
