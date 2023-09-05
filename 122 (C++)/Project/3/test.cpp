#include <iostream>
#include <fstream>

using namespace std;

// Struct for the doubly linked list node
struct Node 
{
    int value;
    Node* prev;
    Node* next;
};

// Function to create a new node with a given value
Node* createNode(int val) 
{
    // Allocate memory for the new node
    Node* newNode = new Node;

    // Set the node's value and pointers to nullptr
    newNode->value = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    // Return the new node
    return newNode;
}

// Function to insert a new node with a given value before a given node in the list
void insertBefore(Node*& node, int val) 
{
    // Create a new node with the given value
    Node* newNode = createNode(val);

    // Update the pointers of the new node and the existing node
    newNode->next = node;
    newNode->prev = node->prev;
    if (node->prev) {
        node->prev->next = newNode;
    }
    node->prev = newNode;

    // Update the reference to the existing node to point to the new node
    node = newNode;
}

// Function to insert a new node with a given value after a given node in the list
void insertAfter(Node*& node, int val) 
{
    // Create a new node with the given value
    Node* newNode = createNode(val);

    // Update the pointers of the new node and the existing node
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next) {
        node->next->prev = newNode;
    }
    node->next = newNode;

    // Update the reference to the existing node to point to the new node
    node = newNode;
}
int main() 
{
    int getElementNumber(Node* node, Node* head);
    int count = 0;
    bool verbose = false;
    char input;
    // Open input file and read numbers into the doubly linked list
    string inputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Do you want verbose output? (y/n): ";
    cin >> input;
    if (input == 'y') 
    {
        verbose = true;
    }
    ifstream fin(inputFileName);
    if (!fin.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    // Create variables to track the head, tail, and midpoint of the list
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;

    // Read the first number from the input file and create the initial node
    int num;
    if (fin >> num) {
        head = createNode(num);
        tail = head;
        mid = head;
    }

    // Read the remaining numbers and insert them into the list
    while (fin >> num) {

        // Check if the number should be inserted before the head
        if (num < head->value) {
            insertBefore(head, num);
            mid = head;
        }

        // Check if the number should be inserted after the tail
        else if (num > tail->value) {
            insertAfter(tail, num);
            mid = tail;
        }

        // Check if the number should be inserted before the midpoint
        else if (num < mid->value) {
            Node* node = mid;
            while (num < node->value) {
                node = node->prev;
            }
            insertAfter(node, num);
            mid = node->next;
        }

        // Check if the number should be inserted after the midpoint
        else if (num > mid->value) {
            Node* node = mid;
            while (num > node->value) {
                node = node->next;

            }
            insertBefore(node, num);
            mid = node->prev;
        }
        //else will put it after the 
        else 
        {
            insertAfter(mid, num);
        }
    }
    fin.close();

    // Open output file and write sorted numbers
    string outputFileName = "sorted_" + inputFileName;
    ofstream fout(outputFileName);
    if (!fout.is_open()) 
    {
        cout << "Error opening output file!" << endl;
        return 1;
    }
    //new node
    Node* node = head;
    //goes until nullptr
    if (verbose) 
    {
        fout << "c = " << count << endl;
        fout << "h => " << head->value << " (element 1)" << endl;
        fout << "t => " << tail->value << " (element " << count << ")" << endl;
        fout << "m => " << mid->value << " (element " << (count / 2) + 1 << ")" << endl;
        fout << "Note that c/2 " << ((count % 2 == 0) ? "" : "+ 1") << " = " << count / 2 << endl;
        
    }
    else
    {
        while (node) 
        {
            fout << node->value << endl;
            node = node->next;
        }
        }
    fout.close();
    cout << "Sorted numbers written to " << outputFileName << endl;

    // Clean up memory
    node = head;
    while (node) 
    {
        Node* next = node->next;
        delete node;
        node = next;
    }

    return 0;
}
 