#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

int countVowelsInWord(string word)
{
    int count = 0;

    for (char const &c: word) {
        switch (c)
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                count++;
        }
    }
    return count;
}

int main()
{
    string sentence = "This is a sentence that I wrote all by myself today. Unpredictable words in here.";
    stringstream ss(sentence);
    string word;
    string longestWord = "";
    int count = 0;
    int mostVowelsInWord = 0;

    while (ss >> word)
    {
        count++;
        if (word.length() > longestWord.length())
        {
            longestWord = word;
        }
        if (countVowelsInWord(word) > mostVowelsInWord)
        {
            mostVowelsInWord = countVowelsInWord(word);
        }
    }
    
    cout << "There are " << count << " words in the sentence." << endl;
    cout << "The longest word was: '" << longestWord << "'. It was " << longestWord.length() << " chars long." << endl;
    cout << "The most vowels found in a word were: " << mostVowelsInWord << endl;

}