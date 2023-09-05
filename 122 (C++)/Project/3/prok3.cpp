
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
    Node* newNode = new Node;
    newNode->value = val;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a new node with a given value before a given node in the list
void insertBefore(Node*& node, int val) 
{
    Node* newNode = createNode(val);
    newNode->next = node;
    newNode->prev = node->prev;
    if (node->prev) {
        node->prev->next = newNode;
    }
    node->prev = newNode;
    node = newNode;
}

// Function to insert a new node with a given value after a given node in the list
void insertAfter(Node*& node, int val) 
{
    Node* newNode = createNode(val);
    newNode->prev = node;
    newNode->next = node->next;
    if (node->next)
    {
        node->next->prev = newNode;
    }
    node->next = newNode;
    node = newNode;
}

// Function to print the doubly linked list and its midpoint
void printList(Node* head, Node* tail, Node* mid, int count, bool verbose) 
{
    if (verbose)
    {
        cout << "Element #: ";
        for (int i = 1; i <= count; i++)
        {
            cout << i << "     ";
        }
        cout << endl;

        cout << "Values:    ";
        Node* node = head;
        while (node) 
        {
            cout << node->value << "   ";
            node = node->next;
        }
        cout << endl;

        cout << "c = " << count << endl;
        cout << "h => " << head->value << " (element 1)" << endl;
        cout << "t => " << tail->value << " (element " << count << ")" << endl;
        cout << "m => " << mid->value << " (element ";
        if (count % 2 == 0) 
        {
            cout << count / 2 << ")" << endl;
        }
        else 
        {
            cout << count / 2 + 1 << ")" << endl;
        }
    }
    else
    {
        cout << "Element #: " << count << endl;
        cout << "Values:    ";
        Node* node = head;
        while (node) 
        {
            cout << node->value << "   ";
            node = node->next;
        }
        cout << endl;
    }
}

int main() 
{
    // Open input file and read numbers into the doubly linked list
    string inputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    ifstream fin(inputFileName);
    if (!fin.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mid = nullptr;
    int count = 0;
    int num;
    bool verbose = false;
    char input;
    cout << "Do you want verbose output? (y/n): ";
    cin >> input;
    if (input == 'y') 
    {
        verbose = true;
    }
    if (fin.fail())
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    ofstream fout("output.txt");
    if (!fout.is_open()) 
    {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    while (fin >> num) 
    {
        count++;
        //Verbose
        if (verbose) 
        {
            fout << "Read x = " << num << endl;
            fout << "Element #: " << count << endl;
            fout << "Values:\t\t";
            Node* temp = head;
            while (temp != nullptr) 
            {
                fout << temp->value << "  ";
                temp = temp->next;
            }
            fout << endl;
        }

        if (head == nullptr) 
        {
            head = createNode(num);
            tail = head;
            mid = head;
        } 
        else if (num < head->value) 
        {
            insertBefore(head, num);
            mid = (count % 2 == 0) ? mid : mid->prev;
        } 
        else if (num > tail->value) 
        {
            insertAfter(tail, num);
            mid = (count % 2 == 0) ? mid->next : mid;
        } 
        else 
        {
            Node* temp = head;
            while (temp != nullptr) 
            {
                if (num < temp->value) 
                {
                    insertBefore(temp, num);
                    mid = (count % 2 == 0) ? mid : mid->prev;
                    break;
                }
                temp = temp->next;
            }
        }
        

        if (verbose) 
        {
            fout << "c = " << count << endl;
            fout << "h => " << head->value << " (element 1)" << endl;
            fout << "t => " << tail->value << " (element " << count << ")" << endl;
            fout << "m => " << mid->value << " (element " << (count / 2) + 1 << ")" << endl;
            fout << "Note that c/2 " << ((count % 2 == 0) ? "" : "+ 1") << " = " << count / 2 << endl;
        }

    }
        
    //node = head;

    printList(head, tail, mid, count, verbose);

    // Close input and output files
    fin.close();
    fout.close();


    return 0;
}

