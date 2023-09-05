/*
* Tanner Kleintop, Andrew Nguyen, Krushil Amrutiya, Sean Gao, Shifra Suthakar
* April 29, 2023
* This is a C++ program that simulates a Turing Machine.
* The program reads a file with instructions for the Turing Machine.
* It then reads an input string and simulates the Turing Machine on it.
* The final output is the resulting tape after the Turing Machine is done.
*/
#include <iostream> // for input and output to console
#include <fstream> // for input and output to files
#include <string> // for string operations

// define some constants for the Turing Machine
const char BLANK = 'B'; // the blank character on the tape
const char ZERO = '0'; // the '0' character on the tape
const char ONE = '1'; // the '1' character on the tape
const char STAR = '*'; // a wildcard character used in the input file
const char LEFT = 'L'; // move the tape head left
const char RIGHT = 'R'; // move the tape head right
const int MAXTAPE = 100; // the maximum length of the tape
const int MAXSTATES = 25; // the maximum number of states the Turing Machine can have
const short STARTPOS = 40; // the starting position of the tape head
const char STARTSTATE = ZERO; // the starting state of the Turing Machine

// define a struct for the state transition function of the Turing Machine
struct stateTrans {
    char state; // the current state of the Turing Machine
    char readChar; // the character on the tape being read
    char nextState; // the next state of the Turing Machine
    char writeChar; // the character to write to the tape
    char move; // the direction to move the tape head
};

// This function initializes the character array 'tape' with blanks,
// and then copies the characters from the input string 'inputString' onto it.
// The starting position for the input string is defined by the constant 'STARTPOS'.

void initializeTape(char tape[MAXTAPE], const std::string& inputString) {
    // First, initialize the entire tape array with blanks
    for (int i = 0; i < MAXTAPE; ++i) {
        tape[i] = BLANK;
    }

    // Then, copy the input string onto the tape starting at the designated position
    for (int i = 0; i < inputString.length(); ++i) {
        tape[STARTPOS + i] = inputString[i];
    }
}


// This function prints out the contents of the character array 'tape',
// with the current position of the tape highlighted by vertical bars.
// The starting position of the tape iFmas defined by the constant 'STARTPOS',
// and the length of the tape is defined by 'MAXTAPE'.

void printTape(const char tape[MAXTAPE], int position) {
    // Print out information about the tape
    std::cout << "Tape starts at " << STARTPOS << " length = " << MAXTAPE << " highlights position " << position << " on tape =\n";

    // Print out each character on the tape, with the current position highlighted
    for (int i = 0; i < MAXTAPE; ++i) {
        if (i == position) {
            std::cout << "|" << tape[i] << "| ";
        }
        else {
            std::cout << tape[i] << " ";
        }
    }
    std::cout << std::endl; // Move to the next line after printing the tape
}


// This function reads in transition rules from the input file 'inFile',
// and stores them in the array of state transitions 'transitions'.
// Each transition rule consists of a current state, a character to read, a next state,
// a character to write, and a direction to move the tape.

void readTransitions(std::ifstream& inFile, stateTrans transitions[MAXSTATES]) {
    int i = 0; // Initialize the counter for the number of transition rules read

    // Read in transition rules as long as there are still rules to read in the input file
    while (inFile >> transitions[i].state >> transitions[i].readChar >> transitions[i].nextState >> transitions[i].writeChar >> transitions[i].move) {
        ++i; // Increment the counter for each rule read
    }
}


// This function searches for a transition rule in the array of state transitions 'transitions',
// that matches the current state 'currentState' and the character being read 'readChar'.
// If a matching transition rule is found, it is returned.
// Otherwise, a default 'blank' transition is returned.

stateTrans findTransition(const stateTrans transitions[MAXSTATES], char currentState, char readChar) {
    // Loop through each transition rule in the 'transitions' array
    for (int i = 0; i < MAXSTATES; ++i) {
        // Check if the current transition rule matches the current state and input character
        if (transitions[i].state == currentState && transitions[i].readChar == readChar) {
            // If so, return the matching transition rule
            return transitions[i];
        }
    }

    // If no matching transition rule was found, return a default 'blank' transition
    return stateTrans{ BLANK, BLANK, BLANK, BLANK, BLANK };
}


// This function runs the Turing machine, given the initial tape 'tape' and transition rules 'transitions'.
// The machine starts in the 'STARTSTATE' state, at position 'STARTPOS' on the tape.
// It continues to execute until a blank transition is encountered.
// After execution, the final state and tape are printed to the console.

void runTuringMachine(char tape[MAXTAPE], stateTrans transitions[MAXSTATES]) {
    char currentState = STARTSTATE; // Initialize the current state to the starting state
    int position = STARTPOS; // Initialize the tape position to the starting position

    while (true) { // Loop until a blank transition is encountered
        stateTrans transition = findTransition(transitions, currentState, tape[position]); // Find the next transition rule to apply
        if (transition.state == BLANK) { // If the transition is blank, stop execution
            break;
        }
        tape[position] = transition.writeChar; // Write the new character to the tape
        position += (transition.move == RIGHT) ? 1 : -1; // Move the tape position to the right or left, depending on the move direction
        currentState = transition.nextState; // Update the current state to the next state in the transition rule
    }

    std::cout << "Execution halts in state " << currentState << std::endl; // Print the final state of the machine
    printTape(tape, position); // Print the final tape contents, with the current position highlighted
}


int main() {
   std::string inputFileName;
   std::cout << "Enter the input file name: "; // Prompt the user to enter the input file name
   std::cin >> inputFileName; // Read the input file name from the user

   std::ifstream inFile(inputFileName); // Open the input file for reading
   if (!inFile) { // If the input file could not be opened, print an error message and exit with a non-zero status code
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
            return 1;
    }

    std::string inputString;
    std::getline(inFile, inputString); // Read the first line of the input file as the input string
    char tape[MAXTAPE];
    initializeTape(tape, inputString); // Initialize the tape with the input string

    stateTrans transitions[MAXSTATES];
    readTransitions(inFile, transitions); // Read the transition rules from the input file
    inFile.close(); // Close the input file

    std::cout << "Tape before execution:" << std::endl;
        printTape(tape, STARTPOS); // Print the initial tape contents, with the current position highlighted

    runTuringMachine(tape, transitions); // Run the Turing machine on the initialized tape and transition rules

    return 0; // Exit with a status code of 0 to indicate successful execution
}