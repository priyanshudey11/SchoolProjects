/*
Priyanshu Dey 1/31/23
This program prints the ASCII values from 33 to 126
*/
//Libray Uses
#include <iostream>
#include <iomanip>
using namespace std;
//main function to run the program
int main()
    {
        //Header 
        cout << setw(5) << "Dec" << setw(7) << "Oct" << setw(7) << "Hex" << setw(7) << "Char" << endl;
        //Loops for a new line
        for (int i = 33; i <= 126; i++)
            //spacing and printing ouput
            {
                cout << setw(5) << dec << i << setw(7) << showbase << oct << i << setw(7) << hex << i << setw(7) << (char)i << endl;
            }
    }

