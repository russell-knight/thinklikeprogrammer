#include <iostream>
using std::cin;
using std::cout;

/*
    Goal 1: Print the following to stdout:

    #####
    ####
    ###
    ##
    #

    Constraints: Only use cout << "#"and cout << "\n" commands

    Approach:
    - use for loop to print each row (1-5)
    - use nested for loop to print hash symbols on each row
*/
void printTriangle()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            cout << "#";
        }
        cout << "\n";
    }
}

/*
    Goal: Print the following to stdout:

    #
    ##
    ###
    ####
    ###
    ##
    #

    Constraints: Only use cout << "#"and cout << "\n" commands

    Approach:
    - set an int value to 1
    - print # while int value is not == 4, i++
    - while int value != 1 print
*/
void printSidewaysTriangle()
{
    for (int row = 1; row < 8; row++)
    {
        int hashNum = 4 - abs(4-row);
        
        for (int i = 0; i < hashNum; i++)
        {
            cout << "#";
        }
        cout << "\n";
    }
}


/* Goal print 
               ##
              ####
             ######
            ########
*/
void printUprightTriangle()
{
    const int NUM_ROWS = 4;
    const int NUM_ROW_CHARS = 8;

    // Iterate rows
    for (int currRow = NUM_ROWS; currRow > 0; currRow--)
    {
        int hashNum = 5 - currRow;
        // Iterate chars in row
        for (int currCharPos = 1; currCharPos <= NUM_ROW_CHARS; currCharPos++)
        {
            if (currCharPos <= 4) // print left side of traingle
            {
                if (currCharPos < currRow)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }
            else // print right side of triangle
            {
                if (currCharPos - 4 <= hashNum)
                {
                    cout << "#";
                }
                else
                {
                    cout << " ";
                }
            }    
        }
        cout << std::endl;
    }
}

/* Goal: Print ########
                ######
                 ####
                  ##
    
    Note that #### is the vertical mirror of ####
               ###                           ###
                ##                           ##
                 #                           #
    And the combination of these will print the full image.


    row 1 | 4 hashes
    row 2 | 3 hashes
    row 3 | 2 hashes
    row 4 | 1 hash

    numHash = 5 - row

    row 1 | 0 spaces
    row 2 | 1 space
    row 3 | 2 spaces
    row 4 | 3 spaces

    numSpaces = row - 1
*/
void printUpsideDownTriangle()
{
    const int NUM_ROWS = 4;
    const int NUM_ROW_CHARS = 8;

    // Iterate rows
    for (int currRow = 1; currRow <= NUM_ROWS; currRow++)
    {
        int hashNum = 5 - currRow;
        // Iterate chars in row
        for (int currCharPos = 1; currCharPos <= NUM_ROW_CHARS; currCharPos++)
        {
            if (currCharPos <= 4) // print left side of traingle
            {
                if (currCharPos < currRow)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }
            else // print right side of triangle
            {
                if (currCharPos - 4 <= hashNum)
                {
                    cout << "#";
                }
                else
                {
                    cout << " ";
                }
            }    
        }
        cout << std::endl;
    }
}

/* #            #
    ##        ##
     ###    ###
      ########
      ########
     ###    ###
    ##        ##
   #            #

   Try printing one quadrant first

    #             which is 7 chars wide
     ##           numHashes == rowNum
      ###         start Hash pos = currCharPos == numHashes
       ####

    
    The other quadrant is harder

                                #
                              ## 
                            ###  
                          ####
    row 1 starts on 14   13
    row 2 starts on 12   10
    row 3 starts on 10    7
    row 4 starts on 8     4
*/
void printStarShape()
{
    const int NUM_ROWS = 8;
    const int NUM_ROW_CHARS = 14;

    // print top half of star
    for (int currRow = 1; currRow <= 4; currRow++)
    {
        int hashesToPrint = 0;
        for (int currCharPos = 1; currCharPos <= NUM_ROW_CHARS; currCharPos++)
        {
            if (hashesToPrint > 0)
            {
                cout << "#";
                hashesToPrint--;
            }
            else if (currCharPos == currRow || currCharPos == NUM_ROW_CHARS - 2*(currRow-1))
            {
                hashesToPrint = currRow - 1;
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << std::endl;
    }
    // print bottom half of star
    for (int currRow = 4; currRow > 0; currRow--)
    {
        int hashesToPrint = 0;
        for (int currCharPos = 1; currCharPos <= NUM_ROW_CHARS; currCharPos++)
        {
            if (hashesToPrint > 0)
            {
                cout << "#";
                hashesToPrint--;
            }
            else if (currCharPos == currRow || currCharPos == NUM_ROW_CHARS - 2*(currRow-1))
            {
                hashesToPrint = currRow - 1;
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << std::endl;
    }
}

int main()
{
    // printTriangle();
    // printSidewaysTriangle();
    // printUprightTriangle();
    // printUpsideDownTriangle();
    printStarShape();
}