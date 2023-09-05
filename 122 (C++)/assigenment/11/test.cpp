//Name: Qays Mukaddam
//Date: April 4th 2023
//Description: Writing a program that reads two matrices and 1) adds them(if compatible) and prints their sum, 
//subtracts them (if compatible) and prints their difference, and 3) multiplies them(if compatible) and prints their product.

#include <iostream> // adds iostream library 
#include <fstream> // adds fstream library
#include <iomanip> // adds iomanip library 

using namespace std;

int main()
{
    
    string file1, file2, outFile; //declares variable file1 file2 and outfile
    cout << "Enter the first matrix input file name: "; // asks user to enter input file
    cin >> file1; // output file1
    cout << "Enter the second matrix input file name: "; // asks user to enter second matrix input file
    cin >> file2; //output file2
    cout << "Enter the output file name: "; // asks user to enter output file name
    cin >> outFile; //output outfile

    
    ifstream fileA(file1); // Reads the input matrices from the files
    ifstream fileB(file2); // Reads the input matrices from the files

    // Checks if the input files opened successfully
    if (!fileA)
    {
        cout << "Error opening file " << file1 << endl; //output if error
        return 1;
    }
    if (!fileB)
    {
        cout << "Error opening file " << file2 << endl; //output if error
        return 1;
    }

    // Reads the dimensions of Matrix A
    int rowsA, colsA;
    fileA >> rowsA >> colsA;

    // Reads the dimensions of Matrix B
    int rowsB, colsB;
    fileB >> rowsB >> colsB;

    // Checks if the matrices are ok for addition, subtraction and multiplication
    if (rowsA != rowsB || colsA != colsB)
    {
        cout << "Matrices are not compatible for addition, subtraction or multiplication." << endl;
        return 1;
    }

    // Creates the matrix A and matrix B
    double A[rowsA][colsA], B[rowsB][colsB];

    // Reads matrix data for matrix A
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            if (!(fileA >> A[i][j])) {
                cout << "Error reading file " << file1 << endl; //outputs error
                return 1;
            }
        }
    }

    // Reads the matrix data for matrix B
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            if (!(fileB >> B[i][j])) {
                cout << "Error reading file " << file2 << endl; //outputs error 
                return 1;

            }
        }
    }

    // Addition
    double C[rowsA][colsA];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout << C << endl;
        }
    }

    // Subtraction
    double D[rowsA][colsA];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            D[i][j] = A[i][j] - B[i][j];
        }
    }

    // Muiltpaction 
    double E[rowsA][colsB];
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            E[i][j] = 0;
            for (int k = 0; k < colsA; k++)
            {
                E[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //Prints out Matrix A
    ofstream out(outFile);
    out << fixed << setprecision(3);
    out << "Matrix A = " << endl;
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            out << setw(8) << A[i][j];
        }
        out << endl; //ends matrix A
    }
    //Prints out the matrix B
    out << "\nMatrix B = " << endl;
    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            out << setw(8) << B[i][j];
        }
        out << endl; //ends the matrix B
    }
    // Prints the Addition
    out << "\nA + B = " << endl;
    if (rowsA == rowsB && colsA == colsB)
    {
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                out << setw(8) << A[i][j] + B[i][j];
            }
            out << endl; // ends additon
        }
    }
    else
    {
        out << "Matrices A and B do not work addition." << endl; //outputs matrices not compatible 
    }
    //prints the subtraction
    out << "\nA - B = " << endl;
    if (rowsA == rowsB && colsA == colsB)
    {
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsA; j++)
            {
                out << setw(8) << A[i][j] - B[i][j];
            }
            out << endl; //ends subtraction
        }
    }
    
    else
    {
        out << "Matrices A and B do not work subtraction." << endl; //outputs matrices not compatible
    }
    //prints the multiplication
    out << "\nA * B = " << endl;
    if (colsA == rowsB) {
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                double sum = 0;
                for (int k = 0; k < colsA; k++) {
                    sum += A[i][k] * B[k][j];
                }
                out << setw(8) << sum;
            }
            out << endl; //ends multiplication
        }
    }
  
    else
    {
        out << "Matrices A and B do not work multiplication." << endl; // output of else statment
    }
    
    out.close();
    return 0; //ends program

}