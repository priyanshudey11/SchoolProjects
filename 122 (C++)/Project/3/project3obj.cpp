#include <iomanip>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int MAXSIZE = 256;

struct Entry {
    bool flag = false;
    string str = "";
    struct Entry* next = NULL;
};

unsigned char getKey(string);

int main() {
    struct Entry table[MAXSIZE];

    string inF; 
    string str;

    cout << "Enter the name of file you wish to open: ";
    cin >> inF;

    ifstream inFStream(inF);

    if (inFStream.fail()) {
        cout << "Cannot open " << inF << endl;
        return 1;
    }

    while (getline(inFStream, str)) {
        unsigned char key = getKey(str);
        if (table[key].flag == false) {
            table[key].flag = true;
            table[key].str = str;
        }
        else {
            struct Entry* newPtr = new struct Entry;
            newPtr->flag = true;
            newPtr->str = str;
            newPtr->next = NULL;
            struct Entry* currPtr = &table[key];
            while (currPtr->next != NULL) {
                currPtr = currPtr->next;
            }
            currPtr->next = newPtr;
        }
    }
    inFStream.close();

    for (int i = 0; i < MAXSIZE; i++) {
        if (table[i].flag) {
            cout << "Slot " << i << " is occupied with " << table[i].str;
            struct Entry* currPtr = table[i].next;
            while (currPtr != NULL) {
                cout << "\t" << currPtr->str;
                currPtr = currPtr->next;
            }
            cout << endl;
        }
    }

    return 0;
}

unsigned char getKey(string str) {
    unsigned char key = 0;
    for (int i = 0; i < str.length(); i++) {
        key ^= str[i];
    }

    return key;
}