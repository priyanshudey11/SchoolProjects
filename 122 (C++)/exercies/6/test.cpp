#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const int SIZE = 26; // 26 chars
const int WORDSIZE = 25; // max word size

char cArray[SIZE]; // array of characters in set
int tArray[SIZE][SIZE] = {0}; // training array
int firstChars[SIZE] = {0}; // array of first character multiplicities
int transArray[SIZE][SIZE] = {0}; // transition array of multiplicities
char word[WORDSIZE+1]; // word being built

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

    int numWords;
    file >> numWords;
    string tempWord;
    getline(file, tempWord); // consume remaining newline character

    for (int i = 0; i < numWords; i++) 
    {
        getline(file, tempWord);
        int len = tempWord.length();
        firstChars[getIndex(cArray, tempWord[0]-'a')]++;
        for (int j = 1; j < len; j++) {
            int prevIndex = getIndex(cArray, tempWord[j-1]-'a');
            int nextIndex = getIndex(cArray, tempWord[j]-'a');
            if (prevIndex >= 0 && nextIndex >= 0) {
                tArray[prevIndex][nextIndex]++;
            }
        }
    }

    file.close();

    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0;
        for (int j = 0; j < SIZE; j++) {
            rowSum += tArray[i][j];
        }
        for (int j = 0; j < SIZE; j++) {
            if (rowSum > 0) {
                transArray[i][j] = (tArray[i][j] * 100) / rowSum;
            }
        }
    }

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

// Print the transition matrix to console
cout << "Multiplicities in:";
for (int i = 0; i < numChars; i++) {
    cout << "\t" << cArray[i];
}
cout << endl;
for (int i = 0; i < numChars; i++) {
    cout << cArray[i] << "\t";
    for (int j = 0; j < numChars; j++) {
        cout << transArray[i][j] << "\t";
    }
    cout << endl;
}

cout << "Words generated and written to " << outputFile << endl;

return 0;
}
