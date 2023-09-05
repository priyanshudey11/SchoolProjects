/*
Priyanshu Dey 
This program reads an adjacency matrix, M, from a file, and computes powers of M: Mp, where p varies from 1 to 5. Print out all powers from 1 to 5. 
*/
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

// Function to compute matrix power
// This function takes an adjacency matrix M, its size n, a power p, and an output matrix Mp as input
// It computes the pth power of M and stores the result in Mp
void matrixPower(int M[][MAX_SIZE], int n, int p, int Mp[][MAX_SIZE])
{
    // Base case: M^1 = M
    if (p == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Mp[i][j] = M[i][j];
            }
        }
        return;
    }
    else{
    // Recursive case: M^p = M^(p-1) * M
    int temp[MAX_SIZE][MAX_SIZE] = {0}; // temporary matrix to store M^(p-1)
    matrixPower(M, n, p-1, temp); // compute M^(p-1)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                // compute (M^(p-1)) * M
                Mp[i][j] += temp[i][k] * M[k][j];
            }
        }
    }
}
}
int main()
{
    // Read input adjacency matrix from file
    string inputFileName;
    cout << "Enter input file name: ";
    cin >> inputFileName;
    ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        cerr << "Error: could not open input file." << endl;
        return 1;
    }

    // Initialize output matrix to zeros.
  int n, m;
     
    inputFile >> n >> m; 
    // read size of matrix if applicable

    int M[MAX_SIZE][MAX_SIZE] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // read matrix element
            inputFile >> M[i][j];
        }
    }
    inputFile.close();

    // Compute matrix powers and write to output file
    string outputFileName;
    cout << "Enter output file name: ";
    cin >> outputFileName;
    ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        cerr << "Error: could not open output file." << endl;
        return 1;
    }

    // initialize output matrix to all zeros
    int Mp[MAX_SIZE][MAX_SIZE] = {0};
    // compute powers from 1 to 5
    for (int p = 1; p <= 5; p++)
    {
        outputFile << "Matrix to the power " << p << ":" << endl;
         // initialize output matrix to all zeros
        int Mp[MAX_SIZE][MAX_SIZE] = {0};
        // compute power of matrix
        matrixPower(M, n, p, Mp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // write matrix element to output file
                outputFile << Mp[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile << endl;
    }
    //closes output file
    outputFile.close();

   

    cout << "Output written to file: " << outputFileName << endl;

    return 0;
}