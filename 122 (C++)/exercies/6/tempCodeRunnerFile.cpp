#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 27; // 26 chars + 1
const int WORDSIZE = 25; // max word size

char cArray[SIZE]; // array of characters in set
char tArray[SIZE][SIZE]; // training array
int firstChars[SIZE]; // array of first character multiplicities
int transArray[SIZE][SIZE]; // transition array of multiplicities
char word[WORDSIZE]; // word being built

int getRandom(int max) {
    return rand() % max;
}

int getIndex(char arr[SIZE], char c) {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == c) {
            return i;
        }
    }
    return -1;
}

char getChar(char arr[SIZE], int index) {
    if (index >= 0 && index < SIZE) {
        return arr[index];
    }
    return '\0';
}

int main() {
    srand(time(NULL)); // seed random number generator

    string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    ifstream file(inputFile);
    if (!file.is_open()) {
        cout << "Error opening input file.\n";
        return 1;
    }

    int numChars;
    file >> numChars;
    for (int i = 0; i < numChars; i++) {
        file >> cArray[i];
    }
    cArray[numChars] = '\0';

    int numWords;
    file >> numWords;
    string tempWord;
    getline(file, tempWord); // consume remaining newline character

    for (int i = 0; i < numWords; i++) {
        getline(file, tempWord);
        int len = tempWord.length();
        firstChars[getIndex(cArray, tempWord[0])]++;
        for (int j = 1; j < len; j++) {
            transArray[getIndex(cArray, tempWord[j-1])][getIndex(cArray, tempWord[j])]++;
        }
    }

    file.close();

    int numIterations;
    cout << "Enter the number of iterations: ";
    cin >> numIterations;

    string outputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cout << "Error opening output file.\n";
        return 1;
    }

    for (int i = 0; i < numIterations; i++) {
        // choose first character based on firstChars array
        int index = 0;
        int randNum = getRandom(numWords);
        while (randNum >= 0) {
            randNum -= firstChars[index];
            index++;
        }
        word[0] = getChar(cArray, index-1);

        // choose subsequent characters based on transArray
        int wordLen = 1;
        char prevChar = word[0];
        while (wordLen < WORDSIZE) {
            int index = 0;
            int randNum = getRandom(numWords);
            while (randNum >= 0) {
                randNum -= transArray[getIndex(cArray, prevChar)][index];
                index++;
            }
            char nextChar = getChar(cArray, index-1);
            if (nextChar == '\0') {
                break;
            }
            word[wordLen] = nextChar;
        wordLen++;
        prevChar = nextChar;
    }
    word[wordLen] = '\0';
    outFile << word << endl;
}

outFile.close();

cout << "Words generated and written to " << outputFile << endl;

return 0;
}