#include <iostream>
#include <string>
using namespace std;

int compareFunc(const void * voidA, const void * voidB)
{
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}

int main()
{
    const int ARRAY_SIZE = 12;
    int myArray[ARRAY_SIZE] = {1,7,2,1,8,5,3,1,1,3,7,9};

    qsort(myArray, ARRAY_SIZE, sizeof(int), compareFunc);

    int mostCommonInt;
    int currInt;
    int highestFrequency = 0;
    int currentFrequency = 0;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (currInt != myArray[i]) // next int is different from last int
        {
            if (currentFrequency > highestFrequency)
            {
                mostCommonInt = myArray[i-1];
                highestFrequency = currentFrequency;
            }

            currInt = myArray[i];
            currentFrequency = 1; // start frequency for new int at 1
        }
        else // current int is the same as previous int
        {
            currentFrequency++;
        }
    }
    cout << "Most Common Int: " << mostCommonInt << endl;
    cout << "Occurred: " << highestFrequency << " times." << endl;
}