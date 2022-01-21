#include <iostream>
#include <tgmath.h>
#include <string>
using std::cin;
using std::cout;
using std::endl;

int getDoubleDigitValue(int x)
{
    x *= 2;

    if (x > 9)
    {
        return 1 + x % 10;
    }
    else
    {
        return x;
    }
}

/*
    Which numbers to double.

    - minimum length for a number will be 2 digits, no maximum length
    - the highest valued unit for a n-lengthed number will be given:
        - 10^n-1
    - For even lengthed nums, the double values will begin at n-1, n-3, n-5... while positive
    - For odd lengthed nums, the double values will begin at n-2 while the result is > 1
*/

/*

/* Is a number odd or even?
*/
bool isNumEven(int num)
{
    return (num % 2 == 0) ? true : false;
}
/*
    Determining length (how man digits) of a number
    Ranges:
    - 1 digit [0-9]
    - 2 digits [10-99]
    - 3 digits [100-999]
    If a number is subtracted by 10^n and the result is < 0
    then that number has at most n digits
*/
int getNumberOfDigits(int num)
{
    int exp = 0;
    int difference = 0;

    while (difference >= -1)
    {
        exp++;
        difference = num - pow(10, exp);
    }
    return exp;
}

/*
    Take the first 12 digits of the 13-digit ISBN
    Multiply each number in turn. Odd positioned numbers are multiplied by 1, even positioned numbers
    are multiplied by 3. 
    Add all of the 12 answers.
    Do a modulo 10 division on the result.
    Take that remainder result and subract it from 10, compare this with the check digit (13th digit).
*/
bool isValidIsbnNum(long long int isbn)
{
    int sum = 0;
    int checkDigit = isbn % 10;
    int calculatedCheckDigit;
    // remove check digit for now
    isbn /= 10;

    for (int i = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            // cout << "adding: " << 3* int(fmodl(isbn / pow(10,i), 10)) << endl;
            sum += 3* int(fmodl(isbn / pow(10,i), 10));
        }
        else
        {
            // cout << "adding: " << int(fmodl(isbn / pow(10,i), 10)) << endl;
            sum += int(fmodl(isbn / pow(10,i), 10));
        }
    }


    
    // cout << "Sum is: " << sum << endl;
    sum = sum % 10;
    // cout << "Sum is: " << sum << endl;
    calculatedCheckDigit = 10 - sum;

    return (calculatedCheckDigit == checkDigit);
}

void checkLuhn()
{
    int luhn;
    int numDigits;
    int checkDigit;

    cout << "Enter a Lunh number you wish to check the validity of: ";
    cin >> luhn;

    checkDigit = luhn % 10;
    cout << "The check digit is: " << checkDigit << endl;
    luhn = luhn / 10; // We've stored checkDigit so lets remove it for now.

    numDigits = getNumberOfDigits(luhn);
    cout << "Your Luhn is " << numDigits << " digit(s) long." << endl;

    int sum = 0;

    if (isNumEven(numDigits))
    {
        // get positional value of each digit
        int posVal;
        for (int i = 0; i < numDigits; i++)
        {
            posVal = int(luhn / pow(10, i)) % 10;
            if (isNumEven(i)) // every other digit is doubled
            {
                sum += getDoubleDigitValue(posVal);
            }
            else
            {
                sum += posVal;
            }
        }
    }
    else // odd Number
    {
        // get positional value of each digit
        int posVal;
        for (int i = 0; i < numDigits; i++)
        {
            posVal = int(luhn / pow(10, i)) % 10;
            if (isNumEven(i))
            {
                sum += posVal;
            }
            else
            { // every other digit is doubled
                sum += getDoubleDigitValue(posVal);
            }
        }
    }
    if ((sum + checkDigit) % 10 != 0)
    {
        cout << "Invalid Luhn number!" << endl;
    }
    else
    {
        cout << "Valid Luhn number!" << endl;
    }
}

int main()
{
    cout << "ISBN: 9781593274245. Valid? " << isValidIsbnNum(9781593274245) << endl;
    cout << "ISBN: 9781861972712. Valid? " << isValidIsbnNum(9781861972712) << endl;
    cout << "ISBN: 9785142865428. Valid? " << isValidIsbnNum(9785142865428) << endl;
}