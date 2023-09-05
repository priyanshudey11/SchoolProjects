/*
Priyanshu Dey
highly modularized C++ program that will sort a set of numbers using a modified binary sort algorithm 
while maintaining a doubly linked sorted list with the option of seeing a verbose option(shows each step of the way)
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct listMemb 
    {
    int value;
    struct listMemb *leftPtr;
    struct listMemb *rightPtr;
    };
// Function to create a new node
listMemb* createNode(int val)
    {
    // Allocate memory for a new linked list node and initialize its fields
    listMemb* newNode = new listMemb;
    newNode->value = val;
    newNode->leftPtr = nullptr;
    newNode->rightPtr = nullptr;
    // Return a pointer to the new node
    return newNode;
    }
// Function to insert a node before the given node
void insertBefore(listMemb* node, listMemb* newNode)
    {
    // Link the new node to the left and right nodes
    newNode->leftPtr = node->leftPtr;
    newNode->rightPtr = node;
    // If there is a left node, link it to the new node
    if (node->leftPtr != nullptr) 
        {
        node->leftPtr->rightPtr = newNode;
        }
    // Link the given node to the new node
    node->leftPtr = newNode;
    }

// Function to insert a node after the given node
void insertAfter(listMemb* node, listMemb* newNode)
    {
    // Link the new node to the left and right nodes
    newNode->leftPtr = node;
    newNode->rightPtr = node->rightPtr;
    // If there is a right node, link it to the new node
    if (node->rightPtr != nullptr) 
        {
        node->rightPtr->leftPtr = newNode;
        }
    // Link the given node to the new node
    node->rightPtr = newNode;
    }
// Function to show first line
void printHeader(int val, ofstream& outputFile)
    {
    // Create a string with the "Read x = " message and the value
    string readx = "Read x = " + to_string(val);
    // Print the string to the output file
    outputFile << readx;
    }

// Function to perform binary sort on the linked list
void binarySort(listMemb*& head, listMemb*& tail, int val, ofstream& outputFile)
    { 
    // Create a new pointer to the head of the list
    listMemb* current = head;
    // Loop through the linked list until we find the correct position to insert the new node
    while (current != nullptr && val > current->value) 
        {
        current = current->rightPtr;
        }
    
    // If the end of the list is reached, insert the new node at the end
    if (current == nullptr) 
        {
        // Insert at the end of the list
        listMemb* newNode = createNode(val);
        if (tail != nullptr)
            {
            // If tail exists, insert the new node after the tail
            insertAfter(tail, newNode);
            tail = newNode;
            }
        else
            {
            // If tail does not exist, set the head and tail to the new node
            head = newNode;
            tail = newNode;
            }
    }
    // If the current node is the head of the list, insert the new node at the beginning
    else if (current->leftPtr == nullptr) 
        {
        // Insert at the beginning of the list
        listMemb* newNode = createNode(val);
        insertBefore(head, newNode);
        head = newNode;
        }
    // Otherwise, insert the new node in the middle of the list
    else
        {
        // Insert in the middle of the list
        listMemb* newNode = createNode(val);
        insertBefore(current, newNode);
        }
    }
// Function to print the linked list in verbose function
void printList(listMemb* head, ofstream& outputFile, bool verbose)
{
    if (verbose)
    {
    // Initialize a pointer to traverse the linked list, starting from the head
    listMemb* current = head; 
    // Initialize a counter to keep track of the element number
    int count = 1; 
    // Initialize a string to store the element number
    string element = "Element #:"; 
    // Initialize a string to store the values of the elements
    string values ="Values:"; 
    // Initialize a string to store the current element number
    string c = " "; 
    // Initialize a string to store the value of the head element
    string h = ""; 
    // Initialize a string to store the value of the current element
    string t = " "; 
    // Initialize a string to store the value of the middle element
    string m = " "; 
    // Initialize a string to store a note about the middle element
    string note = " "; 
    // Traverse the linked list until the end is reached
    while (current != nullptr) 
        { 
        // Add a space to the string to separate the element numbers    
        element += " "; 
        // Add the element number to the string
        element += to_string(count); 
        // Add a space to the string to separate the values
        values += " "; 
        // Add the value of the current element to the string
        values += to_string(current->value); 
        // Set the current element number string
        c = "c = " + to_string(count); 
        // Set the head element string
        h = "h = " + to_string(head->value) + " (element 1)"; 
         // Set the current element string
        t = "t = " + to_string(current->value) + " (element " + to_string(count) + ")";

        // Determine the middle element and set the middle element string and note string accordingly
         // If the element number is even
        if (count % 2 == 0)
            {
            // Calculate the index of the middle element
            int midIndex = count / 2; 
            // Initialize a pointer to the middle element
            listMemb* mid = head; 

            // Traverse the linked list to find the middle element
            for (int i = 1; i < midIndex; i++) 
                { 
                mid = mid->rightPtr;
                }
            // Set the middle element string
            m = "m = " + to_string(mid->value) + " (element " + to_string(midIndex) + ")"; 
            // Set the note string
            note = "Note that c/2 = " + to_string(count/2); 
            }
        // If the element number is odd    
        else 
            {   
            // Calculate the index of the middle element
            int midIndex = count / 2 + 1;
            // Initialize a pointer to the middle element
            listMemb* mid = head; 
            // Traverse the linked list to find the middle element
            for (int i = 1; i < midIndex; i++) 
            { 
                mid = mid->rightPtr;
            }
            // Set the middle element string
            m = "m = " + to_string(mid->value) + " (element " + to_string(midIndex) + ")"; 
            // Set the note string
            note = "Note that c/2 + 1 = " + to_string(count / 2 + 1) + " (integer division!)"; 
            }

        // Move to the next element in the linked list
        current = current->rightPtr; 
        // Increment the element counter
        count++; 
    }
    // Print the strings to the output file
    outputFile << "\n" << element<< "\n" << values<< "\n" << c << "\n" << h<< "\n" << t<< "\n" << m<< "\n" << note <<"\n"<< endl;  
    
}
// Function to print the linked list for the non verbose function
else if(!verbose)
    {
    // Start at the beginning of the linked list
    listMemb* current = head;
    // Loop through each node in the linked list until the end is reached (nullptr)
    while (current != nullptr)
        {
        // Output the value stored in the current node to the output file, followed by a space
        outputFile << current->value << " ";
        // Move to the next node in the linked list by setting current to its right pointer
        current = current->rightPtr;
        }
    // Add a newline character to the output file to separate the output of different linked lists
    outputFile << endl;
    }
}

// Main function
int main()
{
    // Ask the user for the name of the input and output files
    string inputFile, outputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    // Ask the user if they want to enable verbose printing
    bool verbose = false;
    string verboseInput;
    cout << "Do you want to print the linked list in verbose mode 'y/n'? ";
    cin >> verboseInput;
    if (verboseInput == "y")
    {
        verbose = true;
    }
    // Open the input and output files
    ifstream fin(inputFile);
    ofstream fout(outputFile);
    // Initialize the linked list
    listMemb* head = nullptr;
    listMemb* tail = nullptr;
    // Read the numbers from the input file and add them to the linked list
    int num;
    while (fin >> num) {
        binarySort(head, tail, num, fout);
      if (verbose) {
        printHeader (num, fout);
        printList(head, fout, true);
    }
    else {
        printList(head, fout,false);
    }
    }
    // Close the input and output files
    fin.close();
    fout.close();
    // Inform the user that the sorted output has been written to the output file
    cout << "Sorted output has been written to " << outputFile << endl;
    return 0;
}