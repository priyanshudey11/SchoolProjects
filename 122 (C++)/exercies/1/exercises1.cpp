/* Priyanshu Dey 
2/7/23
This is a simpltron program
*/
#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
    //declared input and temp
    int input;
    int temp;

    std::ifstream inFile;
    std::string filename;

    // memory array
    int memory[100];

    // operations
    const int read = 10;
    const int write = 11;
    const int load = 20;
    const int store = 21;
    const int add = 30;
    const int subtract = 31;
    const int divide = 32;
    const int multiply = 33;
    const int branch = 40;
    const int branchneg = 41;
    const int branchzero = 42;
    const int halt = 43;

    // registers
    int accumulator = 0;
    int instructionCounter = 0;
    int operationCode = 0;
    int operand = 0;
    int instructionRegister = 0;

    for (int i = 0; i < 100; i++) {
        memory[i] = 0;
    }
    // promts the user what to do 
    std::cout << "*** Welcome to Simpletron! ***" << std::endl;
    std::cout << "*** Please enter the name of the file containing the program: ***" << std::endl;
    //opens file
    std::cin >> filename;
    //opens file
    inFile.open(filename);
    //if file can not open
    if (inFile.fail()) {
        std::cout << "Cannot open " << filename << std::endl;

        return 1;
    }

    // read the input file into memory
    int i = 0;
    while (inFile >> input) {
        memory[i] = input;
        i++;
    }

    // close the input file
    inFile.close();

    
        instructionRegister = memory[instructionCounter];
        operationCode = instructionRegister / 100; // left two digits code
        operand = instructionCounter % 100; // right two digits of code
        //cases in which might happen
        switch (operationCode)
        {
        case read:
            std::cout << "? ";
            std::cin >> temp;
            memory[operand] = temp;
            instructionCounter++;
            break;
        case write:
            std::cout << std::showpos << memory[operand] << std::endl;
            instructionCounter++;
            break;
        case load:
            accumulator = memory[operand];
            instructionCounter++;
            break;
        case store:
            memory[operand] = accumulator;
            instructionCounter++;
            break;
        case add:
            accumulator += memory[operand];
            instructionCounter++;
            break;
        case subtract:
            accumulator -= memory[operand];
            instructionCounter++;
            break;
        case divide:
            accumulator /= memory[operand];
            instructionCounter++;
            break;
        case multiply:
            accumulator *= memory[operand];
            instructionCounter++;
            break;
        case branchneg:
            if (accumulator < 0) {
                instructionCounter = operand;
            }
            else {
                instructionCounter++;
            }
            break;
        case branchzero:
            if (accumulator == 0)
             {
                instructionCounter = operand;
           break;
           }
        else
         {
             instructionCounter++;
        }
        break;
        
        case branch:
        instructionCounter = operand;
        break;
        case halt:
           // executing = false;
            break;
        }
    

//output file
std::cout << "*** Memory Dump ***" << std::endl;
std::cout << std::setw(5) << "REGISTER:" << std::setw(8) << "DECIMAL" << std::endl;
std::cout << std::setw(5) << "Accumulator" << std::setw(8) << accumulator << std::endl;
std::cout << std::setw(5) << "Instruction Counter" << std::setw(8) << instructionCounter << std::endl;
std::cout << std::setw(5) << "Instruction Register" << std::setw(8) << instructionRegister << std::endl;
std::cout << std::setw(5) << "Operation Code" << std::setw(8) << operationCode << std::endl;
std::cout << std::setw(5) << "Operand" << std::setw(8) << operand << std::endl;
std::cout << "*** Memory Dump ***" << std::endl;
//output file
for (int i = 0; i < 100; i++) {
    std::cout << std::setw(5) << i << std::setw(10) << memory[i] << std::endl;
}

          }

/*
txt files didnt want to sumibt multiple files
a)
00	1008	
01	2008	
02	4106	
03	3009	
04	2109	
05	4000	
06	1109
07	4300	
08	0000	
09	0000	

b)
00	1017	
01	2018	
02	3019	
03	2118	
04	3120	
05	4211	
06	2017	
07	3021	
08	2121	
09	3121	
10	4200	
11	2021	
12  3017	
13	3220	
14	2122	
15	1122	
16	4300	
17	0000	
18	0000	
19	0001	
20	0007	
21	0000	
22	0000	
//end

c)
00	1024	
01	2024	
02	4120	
03	4220	
04	1025	
05	2026	
06	3027	
07	2126	
08	3127	
09	4221	
10	2024	  
11	3126	
12	4219	
13	2025	
14	3128	
15	4104	
16	2025	
17	2128	
18	4004	
19	1128	
20	4300	 
21	2025	
22	2128	
23	4004	
24	0000		
25	0000
26	0000	
27	0001	
28	0000	
*/