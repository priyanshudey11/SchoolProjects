#include <iostream>
#include <fstream>
using namespace std;

// Define pointers for each node in the doubly linked list
struct listMemb {
    int value;
    struct listMemb *leftPtr;
    struct listMemb *rightPtr;
};
void printlist(struct listMemb *h) {
    struct listMemb *node = h;
    while (node) {
        cout << node->value << " ";
        node = node->rightPtr;
    }
    cout << endl;
}

// Function to insert a new node into the doubly linked list
void insertNode(struct listMemb **h, struct listMemb **t, struct listMemb **m, int x) {
    // Create a new node to hold the input value
    struct listMemb *newNode = new listMemb;
    newNode->value = x;

    // If the list is empty, set the head and tail pointers to the new node
    if (*h == NULL) {
        *h = newNode;
        *t = newNode;
        *m = newNode;
    }
    else {
        // If the input value is less than or equal to the value at the head node, insert at the head
        if (x <= (*h)->value) {
            newNode->rightPtr = *h;
            (*h)->leftPtr = newNode;
            *h = newNode;
        }
        // If the input value is greater than or equal to the value at the tail node, insert at the tail
        else if (x >= (*t)->value) {
            newNode->leftPtr = *t;
            (*t)->rightPtr = newNode;
            *t = newNode;
        }
        // Otherwise, insert the node in the appropriate position in the first or second half of the list
        else {
            // If the input value is less than the value at the middle node, insert in the first half of the list
            if (x < (*m)->value) {
                struct listMemb *curr = *h;
                while (curr != NULL && curr->value < x) {
                    curr = curr->rightPtr;
                }
                newNode->rightPtr = curr;
                newNode->leftPtr = curr->leftPtr;
                curr->leftPtr->rightPtr = newNode;
                curr->leftPtr = newNode;
            }
            // If the input value is greater than or equal to the value at the middle node, insert in the second half of the list
            else {
                struct listMemb *curr = *t;
                while (curr != NULL && curr->value > x) {
                    curr = curr->leftPtr;
                }
                newNode->leftPtr = curr;
                newNode->rightPtr = curr->rightPtr;
                curr->rightPtr->leftPtr = newNode;
                curr->rightPtr = newNode;
            }
        }
    }

    // Recompute the middle pointer
    int count = 0;
    struct listMemb *curr = *h;
    while (curr != NULL) {
        count++;
        curr = curr->rightPtr;
    }
    if (count % 2 == 0) {
        *m = (*m)->rightPtr;
    }
}

// Function to print out the elements in the list in order
void printList(struct listMemb *h) {
    struct listMemb *curr = h;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->rightPtr;
    }
}

// Function to free the memory used by the list
void freeList(struct listMemb *h) {
    struct listMemb *curr = h;
    while (curr != NULL) {
        struct listMemb *next = curr->rightPtr;
        delete curr;
        curr = next;
    }
}

int main() {
    // Open input file and read numbers into the doubly linked list
    string inputFile;
    cout << "Enter the name of the input file: ";
    cin >> inputFile;
    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    // Initialize head, tail, and middle pointers to null
    struct listMemb *h = NULL;
    struct listMemb *t = NULL;
    struct listMemb *m = NULL;
    // Initialize the count of elements in the list to 0
    int c = 0;

    // Read the first input value
    int x; 
    fin >> x;

    // Loop while there is more input data
    while (fin) {
        // Increase the count of elements in the list
        c++;

        // Create a new node to hold the input value
        struct listMemb *newNode = new listMemb;
        newNode->value = x;

        // If the list is empty, set the head and tail pointers to the new node
        if (h == NULL) {
            h = newNode;
            t = newNode;
            m = newNode;
        }
        else {
            // If the input value is less than or equal to the value at the head node, insert at the head
            if (x <= h->value) {
                newNode->rightPtr = h;
                h->leftPtr = newNode;
                h = newNode;
            }
            // If the input value is greater than or equal to the value at the tail node, insert at the tail
            else if (x >= t->value) {
                newNode->leftPtr = t;
                t->rightPtr = newNode;
                t = newNode;
            }
            // Otherwise, insert the node in the appropriate position in the first or second half of the list
            else {
                // If the input value is less than the value at the middle node, insert in the first half of the list
                if (x < m->value) {
                    struct listMemb *curr = h;
                    while (curr != NULL && curr->value < x) {
                        curr = curr->rightPtr;
                    }
                    newNode->rightPtr = curr;
                    newNode->leftPtr = curr->leftPtr;
                    curr->leftPtr->rightPtr = newNode;
                    curr->leftPtr = newNode;
                }
                // If the input value is greater than or equal to the value at the middle node, insert in the second half of the list
                else {
                    struct listMemb *curr = t;
                    while (curr != NULL && curr->value > x) {
                        curr = curr->leftPtr;
                    }
                    newNode->leftPtr = curr;
                    newNode->rightPtr = curr->rightPtr;
                    curr->rightPtr->leftPtr = newNode;
                    curr->rightPtr = newNode;
                }
            }
        }

        // Recompute the middle pointer
        if (c % 2 == 0) {
            m = m->rightPtr;
        }
        fin >> x;
    }

    // Open output file and write sorted numbers
    string outputFile = "sorted_" + inputFile;
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cout << "Error opening output file!" << endl;
        return 1;
    }
    struct listMemb* node = h;
    while (node) {
        fout << node->value << endl;
        node = node->rightPtr;
    }
    printlist(h);
    fout.close();
    return 0;
}
