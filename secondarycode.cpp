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
    int count = 0;
    for (int i = 0; i <= no_of_words - no_of_terms; i++) {
        bool match = true;
        for (int j = 0; j < no_of_terms; j++) {
            if (content[i + j] != terms[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    return count;
}

void where_command(string content[MAX_NO_OF_WORDS], int no_of_words, string terms[MAX_NO_OF_TERMS], int no_of_terms) {
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);

    for (int i = 0; i <= no_of_words - no_of_terms; i++) {
        bool match = true;
        for (int j = 0; j < no_of_terms; j++) {
            if (content[i + j] != terms[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "Found at index: " << i << endl;
        }
    }
}

void context_command(string content[MAX_NO_OF_WORDS], int no_of_words, string terms[MAX_NO_OF_TERMS], int no_of_terms, int m) {
    assert(no_of_terms >= 0 && no_of_terms <= MAX_NO_OF_TERMS);
    assert(no_of_words >= 0 && no_of_words <= MAX_NO_OF_WORDS);

    for (int i = 0; i <= no_of_words - no_of_terms; i++) {
        bool match = true;
        for (int j = 0; j < no_of_terms; j++) {
            if (content[i + j] != terms[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << "Found at index: " << i << endl;
            cout << "Context: ";
            int start = max(i - m, 0);
            int end = min(i + no_of_terms + m, no_of_words);
            for (int j = start; j < end; j++) {
                cout << content[j] << " ";
            }
            cout << endl;
        }
    }
}

#ifndef TESTING
int main ()
{// precondition:
    assert(true);
/*  postcondition:
    program has presented interactive interface to user, allowing commands to be entered and executed
*/
    // PART 1
    // string filename;
    // int wordCount = enter_command(filename, content);
    // if (wordCount > 0) {
    //     cout << "Successfully read " << wordCount << " words" << endl;
    //     cout << "Words in order of appearance: ";
    //     for (int i = 0; i < wordCount; i++) {
    //         cout << content[i] << "\n";
    //     }
    //     cout << endl;
    // }
    // return 0;

    // PART 2
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
                for (int i = 0; i < wordCount; i++) {
                    cout << content[i] << "\n";
                }
                cout << endl;
            } else {
                cout << "No content to display. Use 'enter' to read a file." << endl;
            }
        } else if (command == "stop") {
            break;
        } else if (command.find("count") == 0) {
            // Extract terms and call count_command
            // Example: "count word1 word2 word3"
            string terms[MAX_NO_OF_TERMS];
            int no_of_terms = 0;
            size_t pos = 6;
            while (pos != string::npos) {
                size_t nextPos = command.find(" ", pos);
                if (nextPos == string::npos) {
                    terms[no_of_terms] = command.substr(pos);
                } else {
                    terms[no_of_terms] = command.substr(pos, nextPos - pos);
                }
                no_of_terms++;
                pos = nextPos == string::npos ? string::npos : nextPos + 1;
            }
            int count = count_command(content, wordCount, terms, no_of_terms);
            cout << "Count: " << count << endl;
        } else if (command.find("where") == 0) {
            // Extract terms and call where_command
            // Example: "where word1 word2 word3"
            string terms[MAX_NO_OF_TERMS];
            int no_of_terms = 0;
            size_t pos = 6;
            while (pos != string::npos) {
                size_t nextPos = command.find(" ", pos);
                if (nextPos == string::npos) {
                    terms[no_of_terms] = command.substr(pos);
                } else {
                    terms[no_of_terms] = command.substr(pos, nextPos - pos);
                }
                no_of_terms++;
                pos = nextPos == string::npos ? string::npos : nextPos + 1;
            }
            where_command(content, wordCount, terms, no_of_terms);
        } else if (command.find("context") == 0) {
            string terms[MAX_NO_OF_TERMS];
            int no_of_terms = 0;
            size_t pos = 8;
            while (pos != string::npos) {
                size_t nextPos = command.find(" ", pos);
                if (nextPos == string::npos) {
                    terms[no_of_terms] = command.substr(pos);
                } else {
                    terms[no_of_terms] = command.substr(pos, nextPos - pos);
                }
                no_of_terms++;
                pos = nextPos == string::npos ? string::npos : nextPos + 1;
            }
            int m = stoi(terms[0]);
            context_command(content, wordCount, &terms[1], no_of_terms - 1, m);
        } else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}
#endif
