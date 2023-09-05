/*
  Priyanshu Dey 
  1/23/23
  recursive program which determines the GCD (greatest common divisor) 
  of a pair of positive integers. The program prompts the user for 2 integers
  and verifies that both are poitive integers before the code executes.
 */
//libaries used to execute the code
#include <iostream>
using namespace std;

//Recurive program part
int gcd(int a, int b) 
    {
        //to stop the infinte recursion from happening 
        if (b == 0) return a;
        //recursice program where it will caluclte b until the remainder is 0 at which point b is the GCD
        else return gcd(b, a % b);
    }

//main function
int main()
    {
        //declaring a and b as integers
        int a, b;
        //promts user
        cout << "Enter the first positive integer: ";
        //Gets user input
        cin >> a;
        //checks if the input is postive and loops until the integer is positve
        while (a < 0) 
            {
                //tells the user it is not positive
                cout << "Invalid input. Both integers must be positive."<<endl;
                //repromts the user
                cout << "Enter the first positive integer: ";
                //Gets user input
                cin >> a;

            }
        //Promts user for secound number
        cout << "Enter the second positive integer: ";
        //Gets user input 
        cin >> b;
        //checks if the input is postive and loops until the integer is positve
        while (b <= 0)
            {
                //tells the user the input is not positvive.
                cout << "Invalid input. Both integers must be positive.";
                //repomts the user 
                cout << "Enter the second positive integer: ";
                //Gets user input 
                cin >> b;
            }
        //tells the user what the gcd is and excecuts gcd to calculte what the gcd is
        cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    }
