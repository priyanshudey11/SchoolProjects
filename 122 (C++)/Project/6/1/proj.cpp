/*
Majd Haddad,Allen Lewis, Devlin Ursu, Priyanshu Dey, Jumal Barker
May 3, 2023
This code is for a Turing Machine that has several different operations
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
// Define constants for characters used in the program
const char BLANK = 'B';
const char ZERO = '0';
const char ONE = '1';
const char STAR = '*';
const char LEFT = 'L';
const char RIGHT = 'R';
const char HALT_STATE='H';

// Define the maximum tape size and maximum number of states
const int MAXTAPE = 100;
const int MAXSTATES = 25;

// Define the starting position of the tape and starting state
const short STARTPOS = 40;
const char STARTSTATE = '0';

// Define the state transition structure
struct stateTrans 
{
    char state;
    char readChar;
    char nextState;
    char writeChar;
    char move;
};

// Define the state transition table
stateTrans delta[MAXSTATES][2];
void printTape(char tape[],int length, int pos)
{
    for(int i=0; i < length;i++)
    {
        if(i==pos)
        {
            cout << " "<< tape[i] << " ";
        }
        else
        {
            cout << " " << tape[i] <<" ";
        }
    }
    cout << endl;
}
/*
void twos_compliment() //Devlin
{

}

void alternating_1s() //Jumal
{

}

void unarySubtract() //Majd
{

}
*/

// Main function
int main() 
{
    char tape[MAXTAPE];
    char state = STARTSTATE;
    short pos = STARTPOS;
    int length = 0;

    // Initialize the tape with blanks
    for (int i = 0; i < MAXTAPE; i++) 
    {
        tape[i] = BLANK;
    }

    // Read input string
    string fileName;
    cout << "Enter the name of the input file => ";
    cin >> fileName;

    ifstream inFile(fileName);
    if (!inFile) 
    {
        cout << "Error: could not open file '" << fileName << "." << endl;
        return 1;
    }
    length = input.length();
    for (int i = 0; i < length; i++) 
    {
        tape[STARTPOS + i] = input[i];
    }

    // Initialize the state transition table
    for (int i = 0; i < MAXSTATES; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            delta[i][j].state = -1;
            delta[i][j].readChar = -1;
            delta[i][j].nextState = -1;
            delta[i][j].writeChar = -1;
            delta[i][j].move = -1;
        }
    }

    // Define state transitions for validating strings of alternating 0s and 1s
    delta[0][0].state = '0';
    delta[0][0].readChar = '0';
    delta[0][0].nextState = '1';
    delta[0][0].writeChar = '0';
    delta[0][0].move = RIGHT;

    delta[0][1].state = '0';
    delta[0][1].readChar = '1';
    delta[0][1].nextState = '2';
    delta[0][1].writeChar = '1';
    delta[0][1].move = RIGHT;

    delta[1][0].state = '1';
    delta[1][0].readChar = '1';
    delta[1][0].nextState = '0';
    delta[1][0].writeChar = '1';
    delta[1][0].move = RIGHT;

    delta[1][1].state = '1';
    delta[1][1].readChar = '0';
    delta[1][1].nextState = '2';
    delta[1][1].writeChar = '0';
    delta[1][1].move = RIGHT;

    delta[2][0].state = '2';
    delta[2][0].readChar = '1';
    delta[2][0].nextState = '1';
    delta[2][0].writeChar = '1';
    delta[2][0].move = RIGHT;

    delta[2][1].state = '2';
    delta[2][1].readChar = '0';
    delta[2][1].nextState = HALT_STATE;
    delta[2][1].writeChar = '0';
    delta[2][1].move = LEFT;
    
    // Define the intiaial state, the halting state and the current state
    int intitialState=0;
    int haltingState =3;
    int currentState=initialState;


    // Run the simulation
    while (currentState != HALT_STATE)
    {
        // Print the current state and the contents of the tape
        cout << "Current state: " << currentState << endl;
        cout << "Tape contents: ";
        printTape(tape, MAXTAPE, pos);

        // Find the transition for the current state and the current table
        char readChar = tape[pos];
        Transition transition = table[currentState][readChar];
    // Update the tape
    tape[pos] = transition.writeChar;

    // Move the head of the tape
    if (transition.move == 'L') {
        pos--;
    } else if (transition.move == 'R') {
        pos++;
    }

    // Update the current state
    currentState = transition.nextState;
}
    }

    if (currentState==foundTrans) 
    {
        cout << "Shit works"<< endl;
    }
    else
    {
        cout<< "Nope" <<endl;
    }
    
return 0;
}
}