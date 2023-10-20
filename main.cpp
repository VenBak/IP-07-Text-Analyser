#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

const int MAX_NO_OF_TERMS = 100;         // the maximum number of terms to read for a word sequence
const int MAX_NO_OF_WORDS = 25000;       // the maximum number of words to read from a text file
string content [MAX_NO_OF_WORDS];

bool read_word (ifstream& infile, string& word)
{// precondition:
    assert (infile.is_open());
/*  postcondition:
    result is true only if a word is read from `infile`, and this word is assigned to `word`.
    result is false otherwise, and the value of `word` should not be used.
*/
    infile >> word;
    return !infile.fail();
}

int enter_command (string filename, string content [MAX_NO_OF_WORDS])
{// precondition:
    assert (true);
/*  postcondition:
    if result is a positive number then the text file with file name `filename` has been successfully opened and closed after reading, and result number of words
    have been read from that file (at most MAX_NO_OF_WORDS) and are stored in that order in `content`.
    if result is zero, then either the text file was empty or has not been opened.
*/

    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Failed to open the file: " << filename << endl;
        return 0; 
    }

    int wordCount = 0;
    string word;

    while (wordCount < MAX_NO_OF_WORDS && read_word(inputFile, word)) {
        content[wordCount] = word;
        wordCount++;
    }

    inputFile.close();

    return wordCount;

    // content [MAX_NO_OF_WORDS]


    return 0;
}

int count_command (string content [MAX_NO_OF_WORDS], int no_of_words, string terms [MAX_NO_OF_TERMS], int no_of_terms)
{// precondition:
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);
/*  postcondition:
    result is the number of occurrences of the word sequence `terms` (which has `no_of_terms` elements) in `content` (which has `no_of_words` elements)
    (the result is obviously zero in case `no_of_words` < `no_of_terms`)
*/
    // implement this function
    return 0;
}

#ifndef TESTING
int main ()
{// precondition:
    assert(true);
/*  postcondition:
    program has presented interactive interface to user, allowing commands to be entered and executed
*/
    string command;
    int wordCount = 0;
    while (true) {
        cout << "Enter a command: ";
        getline(cin, command);

        if (command.find("enter") == 0) {
            string filename = command.substr(6); // Remove the "enter" part
            wordCount = enter_command(filename, content);
            cout << "Successfully read " << wordCount << " words" << endl;
        } else if (command == "content") {
            if (wordCount > 0) {
                cout << "Words in order of appearance: ";
                for (int i = 0; i < wordCount; i++) {
                    cout << content[i] << "\n";
                }
                cout << endl;
            } else {
                cout << "No content to display. Use 'enter' to read a file." << endl;
            }
        } else if (command == "stop") {
            break;
        }
    }
    return 0;
}
#endif
