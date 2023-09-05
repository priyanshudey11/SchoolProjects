#include <iostream>
#include <fstream>

using namespace std;

const char BLANK = 'B';
const char ZERO = '0';
const char ONE = '1';
const char STAR = '*';
const char LEFT = 'L';
const char RIGHT = 'R';
const int MAXTAPE = 100;
const int MAXSTATES = 25;
const short STARTPOS = 40;
const char STARTSTATE = ZERO;

struct stateTrans {
   char state;
   char readChar;
   char nextState;
   char writeChar;
   char move;
};

void initTape(char tape[], int &len) {
    for (int i = 0; i < MAXTAPE; i++) {
        tape[i] = BLANK;
    }
    string input;
    cout << "Enter input string: ";
    cin >> input;
    len = input.length();
    for (int i = 0; i < len; i++) {
        tape[STARTPOS + i] = input[i];
    }
}

void displayTape(char tape[], int len, int curPos) {
    cout << "Tape starts at " << STARTPOS << " length = " << len << " highlights position " << curPos << " tape = " << endl;
    for (int i = STARTPOS - 1; i < STARTPOS + len + 1; i++) {
        if (i == curPos) {
            cout << " |";
        }
        cout << tape[i] << "| ";
    }
    cout << endl;
}

int findNextState(stateTrans transTable[], char curState, char readChar) {
    for (int i = 0; i < MAXSTATES; i++) {
        if (transTable[i].state == curState && transTable[i].readChar == readChar) {
            return i;
        }
    }
    return -1;
}

void execute(stateTrans transTable[], char tape[], int &len, char &curState, int &curPos) {
    int nextStateIndex;
    do {
        displayTape(tape, len, curPos);
        nextStateIndex = findNextState(transTable, curState, tape[curPos]);
        if (nextStateIndex >= 0) {
            tape[curPos] = transTable[nextStateIndex].writeChar;
            curState = transTable[nextStateIndex].nextState;
            if (transTable[nextStateIndex].move == RIGHT) {
                curPos++;
            } else {
                curPos--;
            }
            if (curPos < 0 || curPos >= MAXTAPE) {
                cout << "Error: Out of range tape position: " << curPos << endl;
                return;
            }
        } else {
            cout << "Error: Could not find transition for state " << curState << " and tape symbol " << tape[curPos] << endl;
            return;
        }
    } while (curState != 'H');
}

int main() {
    char tape[MAXTAPE];
    char curState = STARTSTATE;
    int curPos = STARTPOS;
    int len;
    initTape(tape, len);

    stateTrans transTable[MAXSTATES] = {
        {'0', '0', '1', '0', RIGHT},
        {'0', '1', '2', '1', RIGHT},
        {'1', '1', '0', '1', RIGHT},
        {'1', '0', '3', '0', RIGHT},
        {'2', '0', '0', '0', RIGHT},
        {'2', '1', '4', '1', RIGHT},
        {'3', '0', '3', '0', RIGHT},
{'3', '1', '0', '1', RIGHT},
{'4', '1', '4', '1', RIGHT},
{'4', '0', '5', '0', LEFT},
{'5', '0', '5', '0', LEFT},
{'5', '1', '6', '1', LEFT},
{'6', '0', '7', '0', LEFT},
{'6', '1', '6', '1', LEFT},
{'7', '0', '7', '0', LEFT},
{'7', '1', '8', '1', RIGHT},
{'8', BLANK, 'ACCEPT', BLANK, RIGHT},
{'8', '0', '8', '0', RIGHT},
{'8', '1', '8', '1', RIGHT},
{'ACCEPT', '0', 'ACCEPT', '0', RIGHT},
{'ACCEPT', '1', 'ACCEPT', '1', RIGHT},
{'ACCEPT', BLANK, 'ACCEPT', BLANK, RIGHT},
{'REJECT', '0', 'REJECT', '0', RIGHT},
{'REJECT', '1', 'REJECT', '1', RIGHT},
{'REJECT', BLANK, 'REJECT', BLANK, RIGHT}
};
// Initialize tape to all blanks
for (int i = 0; i < MAXTAPE; i++) {
tape[i] = BLANK;
}
// Get input string from user
string inputStr;
cout << "Enter input string (0s and 1s only): ";
cin >> inputStr;
len = inputStr.length();
// Copy input string to tape
for (int i = 0; i < len; i++) {
tape[STARTPOS + i] = inputStr[i];
}
// Print starting tape
cout << "Tape starts at " << STARTPOS << " length = " << len << " highlights position " << curPos << " tape = " << endl;
for (int i = 0; i < MAXTAPE; i++) {
if (i == curPos) {
cout << " |" << tape[i] << "| ";
} else {
cout << " " << tape[i] << " ";
}
}
cout << endl;
// Execute the Turing machinea
while (true) {
// Find current state transition
stateTrans curTrans;
bool found = false;
for (int i = 0; i < MAXSTATES; i++) {
if (transTable[i].state == curState && transTable[i].readChar == tape[curPos]) {
curTrans = transTable[i];
found = true;
break;
}
}
if (!found) {
cout << "ERROR: No transition found for state " << curState << " and read char " << tape[curPos] << endl;
return -1;
}
// Update tape and move to next position
tape[curPos] = curTrans.writeChar;
if (curTrans.move == LEFT) {
curPos--;
} else {
curPos++;
}
// Check if execution should halt
if (curTrans.nextState == 'ACCEPT') {
cout << "Execution halts in state ACCEPT" << endl;
break;
} else if (curTrans.nextState == 'REJECT') {
cout << "Execution halts in state REJECT" << endl;
break;
}
}
}

