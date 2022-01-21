#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::stack;

/* Program to convert between decimal and binary an vice-versa */
void printBinaryFormOfDecimal(int decimal)
{
    stack<int> stack;

    while (decimal > 0)
    {
        stack.push(decimal % 2);
        decimal /= 2;
    }

    while (!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}

int getNumberOfDigits(int num)
{
    int exp = 0;
    int difference;

    do
    {
        exp++;
        difference = num - pow(10, exp);
    } while (difference >= 0); // if diff is negative, then we've found num of digits

    return exp;
}

void printDecimalToHexadecimal(int decimal)
{
    stack<int> stack;
    int unitVal;

    while (decimal > 0)
    {
        stack.push(decimal % 16);
        decimal /= 16;
    }

    while (!stack.empty())
    {
        unitVal = stack.top();

        switch(unitVal)
        {
            case (10):
                cout << 'A';
                break;
            case (11):
                cout << 'B';
                break;
            case (12):
                cout << 'C';
                break;
            case (13):
                cout << 'D';
                break;
            case (14):
                cout << 'E';
                break;
            case (15):
                cout << 'F';
                break;
            default:
                cout << unitVal;
                break;
        }
        
        stack.pop();
    }

    cout << endl;
}

void printDecimalFormOfBinary(int binary)
{
    int decimal = 0;
    int length = getNumberOfDigits(binary);

    for (int i = 0; i <= length; i++)
    {
        decimal += (int(binary / pow(10,i)) % 10) * pow(2,i);
    }
    
    cout << decimal << endl;
}

int main()
{
    // printBinaryFormOfDecimal(100);
    // printDecimalFormOfBinary(101010);
    printDecimalToHexadecimal(137356);
}