#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    string data;
    Node* left;
    Node* right;
};

// Function to create a new node with the given data
Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree recursively using preorder traversal
Node* buildTree(ifstream& input) {
    string line;
    getline(input, line);
    if (line == "null") {
        return NULL;
    }
    istringstream iss(line);
    string data;
    iss >> data;
    Node* root = createNode(data);
    root->left = buildTree(input);
    root->right = buildTree(input);
    return root;
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    // Open the input file
    string inputfile;
    cout << "Enter input file name: ";
    cin >> inputfile;
    ifstream input(inputfile);
    if (!input) {
        cerr << "Error: Failed to open the input file." << endl;
        return 1;
    }

    // Build the binary tree
    Node* root = buildTree(input);

    // Perform postorder traversal of the tree and print the result
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    // Close the input file
    input.close();

    return 0;
}
