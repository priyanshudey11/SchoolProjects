/*
Priyanshu Dey 
3/14/23
This program queue-based linked list application that allows the user to enter a list of positive integers (up to 25), 
possibly with duplicates in the list and removes the duplicates if given and 0 to stop the program
*/
#include <iostream>
using namespace std;

// define the node structure
struct Node {
    // integer data for the node
    int data;
    // pointer to the next node in the list
    Node* next;
};

// pointer to the front of the queue
Node* head = nullptr;
// pointer to the back of the queue
Node* tail = nullptr;
// integer to keep track of the number of nodes in the list
int size = 0;

// destructor for the queue
void destroyQueue() {
    // loop through the nodes in the list and delete them
    while (head != nullptr) {
        // store the current head node in a temporary variable
        Node* temp = head;
        // set the head pointer to the next node in the list
        head = head->next;
        // delete the temporary node
        delete temp;
    }
}

// enqueue function to add a node to the back of the queue
void enqueue(int value) {
    // create a new node
    Node* newNode = new Node;
    // set the data of the new node to the input value
    newNode->data = value;
    // set the next pointer of the new node to null
    newNode->next = nullptr;
    // if the queue is empty, set both the head and tail pointers to the new node
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    // otherwise, set the next pointer of the tail node to the new node and set the tail pointer to the new node 
    else {
        tail->next = newNode;
        tail = newNode;
    }
    // increment the size of the queue
    size++;
}

// removeDuplicates function to remove any duplicates in the queue
void removeDuplicates() {
    // set the current node to the head of the queue
    Node* current = head;
    // loop through the nodes in the list
    while (current != nullptr) {
        // set the runner node to the current node
        Node* runner = current;
        // loop through the nodes after the current node to check for duplicates
        while (runner->next != nullptr) {
            // if a duplicate is found, remove it
            if (runner->next->data == current->data) {
                Node* temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
                // decrement the size of the queue
                size--;
            } else {
                // move the runner node to the next node
                runner = runner->next;
            }
        }
        // move the current node to the next node
        current = current->next;
    }
}

// printQueue function to print out the queue from head to tail
void printQueue() {
    // set the current node to the head of the queue
    Node* current = head;
    // loop through the nodes in the list and print out the data
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    // print a newline character to move to the next line
    cout << endl;
}

// main function
int main() {
    int num;
    cout << "Enter a positive integer (or 0 or negative to quit): ";
    cin >> num;

    while (num > 0) {
        // if the input is positive, enqueue it
        if (num > 0) {
            enqueue(num);
        }

        cout << "Enter a positive integer (or 0 or negative to quit): ";
        cin >> num;
    }

    // remove any duplicates in the queue
    removeDuplicates();

    // print out the resulting queue
    printQueue();

    // loop through the nodes in the list and delete them
    while (head != nullptr) {
        // store the current head node in a temporary variable
        Node* temp = head;
        // set the head pointer to the next node in the list
        head = head->next;
        // delete the temporary node
        delete temp;
    }

    return 0;
}
