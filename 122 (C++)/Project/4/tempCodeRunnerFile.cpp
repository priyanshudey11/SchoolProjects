#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Define a struct for a node in a binary tree
struct TreeNode 
{
    string value;
    TreeNode* left;
    TreeNode* right;
    // the height of this node in the tree
    int height; 
    // the balance factor of this node
    int balanceFactor; 
};
// A function to create a new node with a given value
TreeNode* createNode(string val) 
{
    TreeNode* node = new TreeNode;
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    // initialize the height to 1 since this is a leaf node
    node->height = 1; 
    // initialize the balance factor to 0
    node->balanceFactor = 0; 
    return node;
}

// A function to get the height of a node in the tree
int getHeight(TreeNode* node) 
{
    if (node == NULL) 
    {
        // If the node is NULL, its height is 0
        return 0; 
    }
    return node->height; // Otherwise, return the height of the node
}

// A function to get the balance factor of a node in the tree
int getBalanceFactor(TreeNode* node)
{
    if (node == NULL) 
    {
        // If the node is NULL, its balance factor is 0
        return 0; 
    }
    // Otherwise, calculate the balance factor

    return getHeight(node->left) - getHeight(node->right); 
}
// A function to perform a left rotation on a given node in the tree
TreeNode* leftRotate(TreeNode* x) 
{
    // Store a reference to x's right child as y
    TreeNode* y = x->right; 
    // Store a reference to y's left child as z
    TreeNode* z = y->left; 
    // Make x the left child of y
    y->left = x; 
    // Make z the right child of x
    x->right = z; 
    // Update the height of x
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
    // Update the height of y
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
    // Update the balance factor of x
    x->balanceFactor = getBalanceFactor(x); 
    // Update the balance factor of y
    y->balanceFactor = getBalanceFactor(y); 
    // Return the new root of the subtree
    return y; 
}


// A function to perform a right rotation on a given node in the tree
TreeNode* rightRotate(TreeNode* y) 
{
    // Store a reference to y's left child as x
    TreeNode* x = y->left; 
    // Store a reference to x's right child as z
    TreeNode* z = x->right;
    // Make y the right child of x
    x->right = y; 
    // Make z the left child of y
    y->left = z; 
    // Update the height of y
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
    // Update the height of x
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
    // Update the balance factor of y
    y->balanceFactor = getBalanceFactor(y); 
    // Update the balance factor of x
    x->balanceFactor = getBalanceFactor(x); 
    // Return the new root of the subtree
    return x; 
}

// A function to insert a node with the given value into the tree rooted at "node"
TreeNode* insertNode(TreeNode* node, string val) 
{
    // If the current node is NULL, create a new node with the given value and return it
    if (node == NULL) 
    {
        return createNode(val);
    }
    // If the given value is less than the value at the current node, insert it in the left subtree
    if (val < node->value) 
     {
        node->left = insertNode(node->left, val);
    } 
    // If the given value is greater than or equal to the value at the current node, insert it in the right subtree
    else 
    {
        node->right = insertNode(node->right, val);
    }
    // Update the height of the current node
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1; 
    // Update the balance factor of the current node
    node->balanceFactor = getBalanceFactor(node); 
    // If the balance factor is greater than 1 and the value is less than the value in the left child, perform a right rotation
    if (node->balanceFactor > 1 && val < node->left->value) 
    {
        return rightRotate(node);
    }
    // If the balance factor is less than -1 and the value is greater than the value in the right child, perform a left rotation
    if (node->balanceFactor < -1 && val > node->right->value) 
    {
        return leftRotate(node);
    }
    // If the balance factor is between -2 and 2, return the current node
    if (node->balanceFactor > -2 && node->balanceFactor < 2) 
    {
        return node;
    }
    // If the balance factor is greater than 1 and the value is greater than the value in the left child, perform a left rotation on the left child followed by a right rotation on the current node
    if (node->balanceFactor > 1 && val > node->left->value) 
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // If the balance factor is less than -1 and the value is less than the value in the right child, perform a right rotation on the right child followed by a left rotation on the current node
    if (node->balanceFactor < -1 && val < node->right->value) 
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    // Return the current node
    return node; 
}
// This function performs an inorder traversal of the binary search tree and prints out the values of its nodes in ascending order.
void inorderTraversal(TreeNode* node)
{

    if (node != NULL)
    {
        // Traverse the left subtree recursively
        inorderTraversal(node->left);
        // Print the value of the current node
        cout << node->value << endl;
        // Traverse the right subtree recursively
        inorderTraversal(node->right);
    }
}

// This function prints out the values, left child, right child, height, and balance factor of each node in the binary search tree using an inorder traversal.
void printTree(TreeNode* node)
{
    // If the node is not null
    if (node != NULL)
    {
        // Traverse the left 
        printTree(node->left);
         // Print the value of the current node followed by its left and right child, height and balance factor
        cout 
        <<setw(10)<< node->value << "\t"
        <<setw(10)<< (node->left ? node->left->value : "null") << "\t"
        <<setw(10)<<(node->right ? node->right->value : "null") << "\t"
        <<setw(10)<<node->height << "\t"
        <<setw(10)<< node->balanceFactor<<"\t" << endl;
        //Traverse the right
        printTree(node->right);
    }
}

// This is the main function that reads in words from a file specified by the user,inserts them into a binary search tree, and then prints out the tree in a formatted table.
int main()
{
    // Initialize the root of the binary search tree to NULL
    TreeNode* root = NULL;
    // Declare a variable to store the filename
    string filename;
    //asks user for file name
    cout << "Enter filename: ";
    cin >> filename;
    ifstream inputFile;
    //opens file
    inputFile.open(filename.c_str());
    //if file open fails
    if (inputFile.fail())
    {
        cout << "Error opening file " << filename << endl;
    return 0;
    }
     // Declare a variable to store the current word/name
    string word;
    //while there are words to read
    while (inputFile >> word)
    {
        // Insert the current word into the binary search tree
        root = insertNode(root, word);
    }
    cout 
    <<setw(10)<< "NODE"<<"\t"
    <<setw(10)<<"LEFT"<<"\t"
    <<setw(10)<<"RIGHT"<<"\t"
    <<setw(10)<<"HEIGHT"<<"\t"
    <<setw(10)<<"BALANCE"<<"\t" << endl;
    printTree(root);
    return 0;
}

