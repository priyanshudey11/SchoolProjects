/*
  Priyanshu Dey 
  1/13/23
  Program output numbers from a txt file and outputs the numbers
  in neat rows and only allows 10 numbers per line. It uses pointers to run
  the code faster.
 */

 //Libraries 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct entry 
  {
      int value;
      entry *nextPtr;
  };

int main()
  {
    //initializing ptr
    //first element of the list
    entry *firstPtr = nullptr;
    //last element of the list 
    entry *lastPtr = nullptr;
    //new value of the list
    entry *newPtr;
    ////value of the current list
    entry *currentPtr;
    //stores temporary value
    int value;
    //count the number of times 
    int count = 0;

    // Prompt user for input file name
    string fileName; // input
    cout << "Enter the name of the input file: ";
    cin >> fileName;

    // Open the input file
    ifstream inputFile(fileName);
    //if file name is not found
    if (!inputFile) 
      {
        cout << "Error opening input file." << endl;

      }
    // Read integers from the file and add them to the linked list
    while (inputFile >> value)
      {
        entry *newPtr = new entry;
        
        newPtr->value = value;
        newPtr->nextPtr = nullptr;
        //if the list is empty sets first and last as new a new list
        if (firstPtr == nullptr) 
          {
            firstPtr = newPtr;
            lastPtr = newPtr;
          }
        //if the list is not empty
        else 
          {
            lastPtr->nextPtr = newPtr;
            lastPtr = newPtr;
          }
        count++;
        //loops for only the number of lines
        if (count % 10 == 0) 
          {
            cout << endl;
          }
      }
  // close file
  inputFile.close();
  // Print out the integers from the linked list
  currentPtr = firstPtr;
  count = 0;
  //outputs the count based if there is only 10 per line
  while (currentPtr != nullptr) 
    {
      //prints output
      cout <<setw(5)<< currentPtr->value << setw(5);
      currentPtr = currentPtr->nextPtr;
      count++;
      if (count % 10 == 0) 
        {
          cout << endl;
        }
    }
 }