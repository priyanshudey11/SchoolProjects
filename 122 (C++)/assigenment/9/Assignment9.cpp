/*
Priyanshu Dey 
3/21/23
creates a hash table for names first and last name after an input is given.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a struct for a node in the linked list
struct Node {
    string name;
    Node* next;
};

// Define the size of the hash table
const int TABLE_SIZE = 100;

// Function to generate a key for a given name
unsigned char generateKey(const string& fullName) {
    unsigned char key = 0;
    for (int i = 0; i < fullName.length(); i++)
        key ^= fullName[i]; // ^ = bitwise XOR
    return key;
}

int main() {
    // Open the input file
    ifstream input;
    string fileName;
    cout << "Please enter the name of the input file: ";
    cin >> fileName;
    input.open(fileName);
    if (!input) {
        cerr << "Unable to open input file";
        return 1;
    }

    // Initialize the hash table
    Node* hashTable[TABLE_SIZE] = { nullptr };

    // Read names from input file and insert into hash table
    string fullName;
    while (getline(input, fullName)) {
        // Create a new node for the name
        Node* newNode = new Node;
        newNode->name = fullName;
        newNode->next = nullptr;

        // Generate a key for the name and insert into the hash table
        unsigned char key = generateKey(fullName);
        int index = key % TABLE_SIZE;
        if (hashTable[index] == nullptr) {
            // No collisions, so insert the new node
            hashTable[index] = newNode;
        }
        else {
            // Handle collisions by chaining nodes together in a linked list
            Node* current = hashTable[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print out the contents of the hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != nullptr) {
            // Print the names at this index
            cout << "Slot " << i << " is occupied with" << endl;
            Node* current = hashTable[i];
            while (current != nullptr) {
                cout << "\t" << current->name << endl;
                current = current->next;
            }

        }
    }

    // Close the input file
    input.close();

    // Free memory used by the linked lists
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
