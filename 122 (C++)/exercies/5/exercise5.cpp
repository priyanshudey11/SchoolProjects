/*
Priyanshu Dey 
4/11/2023
This program reads a binary tree from a file, stores it in an array, 
performs a post-order traversal,and outputs the node values.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

// This function recursively inserts nodes into the binary tree array
void insertHelper(string d1, string d2, string d3, string* tree, int size, int index) 
{
    // If the index is outside of the tree array bounds, return
    if (index >= size)
     {
        return;
    }
    // If the current node in the tree array has the same data as d1, insert the new nodes
    if (tree[index] == d1) 
    {
        if (d2 != "null") 
        {
            tree[2*index+1] = d2;
        }
        if (d3 != "null") 
        {
            tree[2*index+2] = d3;
        }
    } 
    // Otherwise, recursively call the insertHelper function on the left and right children of the current node
    else 
    {
        insertHelper(d1, d2, d3, tree, size, 2*index+1);
        insertHelper(d1, d2, d3, tree, size, 2*index+2);
    }
}

// This function recursively performs a post-order traversal of the binary tree array
void postorderTraversal(string* tree, int size, int index) 
{
    // If the index is outside of the tree array bounds, return
    if (index >= size) 
    {
        return;
    }
    // Recursively call the postorderTraversal function on the left and right children of the current node
    postorderTraversal(tree, size, 2*index+1);
    postorderTraversal(tree, size, 2*index+2);
    // If the current node in the tree array is not empty, print its data
    if (tree[index] != "") 
    {
        cout << tree[index] << " ";
    }
}

int main() 
{
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;
    ifstream inputFile(filename.c_str());
    // If there is an error opening the input file, print an error message and return
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return 0;
    }

    // Determine the size of the binary tree array based on the number of nodes in the input file
    string data;
    int size = 0;
    while (inputFile >> data) 
    {
        size++;
    }
    string* tree = new string[size];
    for (int i = 0; i < size; i++)
    {
        tree[i] = "";
    }

    // Read the input file again and insert nodes into the binary tree array
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    while (inputFile >> data) {
        string d1, d2, d3;
        d1 = data;
        inputFile >> d2 >> d3;
        // If the binary tree array is empty, add the first three nodes as the root and its children
        if (tree[0] == "") 
        {
            tree[0] = d1;
            tree[1] = d2;
            tree[2] = d3;
        } 
        // Otherwise, call the insertHelper function to add the nodes to the tree array
        else 
        {
            insertHelper(d1, d2, d3, tree, size, 0);
        }
    }

    // Perform a post-order traversal of the binary tree array


    postorderTraversal(tree, size, 0);
    //prints new line
    cout << endl;
    //deallocates the memory 
    delete[] tree;
    return 0;
}
