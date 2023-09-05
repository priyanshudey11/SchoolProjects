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
    // multplicity of this node
    int multiplicity;
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
    // initialize the multiplicity to 1 since this is the first occurrence of this value
    node->multiplicity = 1;
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

TreeNode* rebalance(TreeNode* node)
{
    // Calculate the balance factor of the node
    int balanceFactor = getBalanceFactor(node);

    // If the balance factor is greater than 1 and the left subtree's balance factor is greater than or equal to 0, perform a right rotation
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) 
    {
        return rightRotate(node);
    }
    // If the balance factor is less than -1 and the right subtree's balance factor is less than or equal to 0, perform a left rotation
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
    {
        return leftRotate(node);
    }
    // If the balance factor is greater than 1 and the left subtree's balance factor is less than 0, perform a left-right rotation
    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // If the balance factor is less than -1 and the right subtree's balance factor is greater than 0, perform a right-left rotation
    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the node if it does not require rebalancing
    return node;
}

// A function to insert a node with the given value into the tree
TreeNode* insertNode(TreeNode* node, string val) 
{
    // If the current node is NULL, create a new node with the given value and return it
    if (node == NULL) 
    {
        return createNode(val);
    }
    // If the value is less than the current node's value, insert it into the left subtree
    if (val < node->value) 
    {
        node->left = insertNode(node->left, val);
    }
    // If the value is greater than the current node's value, insert it into the right subtree
    else if (val > node->value) 
    {
        node->right = insertNode(node->right, val);
    }
    // If the value is equal to the current node's value, increment its multiplicity
    else 
    {
        node->multiplicity++;
    }
    
    // Update the height of the current node
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    // Update the balance factor of the current node
    node->balanceFactor = getBalanceFactor(node);
    
    // Rebalance the tree if necessary
    return rebalance(node);
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
        <<setw(10)<< node->balanceFactor<<"\t"
        <<setw(10)<<node->multiplicity << endl;
        //Traverse the right
        printTree(node->right);
    }
}
void printInorderWithMultiplicity(TreeNode* node) 
{
    if (node != NULL) 
    {
        printInorderWithMultiplicity(node->left);
        cout << node->value;
        if (node->multiplicity > 1) 
        {
            cout << "(" << node->multiplicity << ")";
        }
        cout << endl;
        printInorderWithMultiplicity(node->right);
    }
}

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
        // Insert the current word into the tree
        root = insertNode(root, word);
    }
    //Prints table and tree
    cout 
    <<setw(10)<< "NODE"<<"\t"
    <<setw(10)<<"LEFT"<<"\t"
    <<setw(10)<<"RIGHT"<<"\t"
    <<setw(10)<<"HEIGHT"<<"\t"
    <<setw(10)<<"BALANCE"<<"\t"
    <<setw(10)<<"MULTIPLICITY" << endl;
    printTree(root);
    return 0;
}
