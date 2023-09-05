/*
Priyanshu Dey 
4/4/23
Thus program takes two input matrices from files, performs addition, subtraction, and multiplication of matrices, 
and writes the result to an output file.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
   //Declares and asks the user for input files
    string file1, file2, outFile;
    cout << "Enter the first matrix input file name: ";
    cin >> file1;
    cout << "Enter the second matrix input file name: ";
    cin >> file2;
    cout << "Enter the output file name: ";
    cin >> outFile;

    // Read input matrices from files
    ifstream fileA(file1);
    ifstream fileB(file2);

    // Check if input files opened successfully
    if (!fileA) 
    {
        cout << "Error opening file " << file1 << endl;
        return 1;
    }
    if (!fileB) 
    {
        cout << "Error opening file " << file2 << endl;
        return 1;
    }

    // Read dimensions of Matrix A
    int rowsA, c2;
    fileA >> rowsA >> c2;

    // Read dimensions of Matrix B
    int rowsB, colsB;
    fileB >> rowsB >> colsB;

    // Check if matrices are compatible for addition, subtraction and multiplication
    if (rowsA != rowsB || c2 != colsB)
     {
        cout << "Matrices are not compatible for addition, subtraction or multiplication." << endl;
        return 1;
    }

    // Create matrices A and B
    double A[rowsA][c2], B[rowsB][colsB];

    // Read matrix data for Matrix A
    for (int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < c2; j++) 
        {
            if (!(fileA >> A[i][j])) {
                cout << "Error reading file " << file1 << endl;
                return 1;
            }
        }
    }

    // Read matrix data for Matrix B
    for (int i = 0; i < rowsB; i++) 
    {
        for (int j = 0; j < colsB; j++)
         {
            if (!(fileB >> B[i][j])) {
                cout << "Error reading file " << file2 << endl;
                return 1;
               
            }
        }
    }
    //Calculations 

    // Calculate Matrix C = A + B Addition
    double C[rowsA][c2];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = A[i][j] + B[i][j];
            cout<<C<<endl;
        }
    }

    // Calculate Matrix D = A - B Subtraction
    double D[rowsA][c2];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < c2; j++) {
            D[i][j] = A[i][j] - B[i][j];
        }
    }

    // Calculate Matrix E = A * B Muiltpaction 
    double E[rowsA][colsB];
    for (int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < colsB; j++) 
        {
            E[i][j] = 0;
            for (int k = 0; k < c2; k++) 
            {
                E[i][j] += A[i][k] * B[k][j];
            }
        }
    }

   // Write output to file

   //Prints Matrix A
   ofstream out(outFile);
   out << fixed << setprecision(3);
   out << "Matrix A = " << endl;
   for (int i = 0; i < rowsA; i++) 
   {
      for (int j = 0; j < c2; j++)
       {
         out << setw(8) << A[i][j];
      }
      out << endl;
   }
   //Prints Matrix B
   out << "\nMatrix B = " << endl;
   for (int i = 0; i < rowsB; i++) 
   {
      for (int j = 0; j < colsB; j++) 
      {
         out << setw(8) << B[i][j];
      }
      out << endl;
   }
   // prints Addition
   out << "\nA + B = " << endl;
   if (rowsA == rowsB && c2 == colsB) 
   {
      for (int i = 0; i < rowsA; i++) 
      {
         for (int j = 0; j < c2; j++) 
         {
               out << setw(8) << A[i][j] + B[i][j];
         }
         out << endl;
      }
   } 
   // If it is not possible to add
   else 
   {
      out << "Matrices A and B are not compatible for addition." << endl;
   }
   //prints Subtraction
   out << "\nA - B = " << endl;
   if (rowsA == rowsB && c2 == colsB) 
   {
      for (int i = 0; i < rowsA; i++) 
      {
         for (int j = 0; j < c2; j++) 
         {
               out << setw(8) << A[i][j] - B[i][j];
         }
         out << endl;
      }
   } 
   // If it is not possible to subtraction
   else 
   {
      out << "Matrices A and B are not compatible for subtraction." << endl;
   }
   //prints Multiplication
   out << "\nA * B = " << endl;
   if (c2 == rowsB) {
      for (int i = 0; i < rowsA; i++) {
         for (int j = 0; j < colsB; j++) {
               double sum = 0;
               for (int k = 0; k < c2; k++) {
                  sum += A[i][k] * B[k][j];
               }
               out << setw(8) << sum;
         }
         out << endl;
      }
   } 
   // If it is not possible to multiplication
   else 
   {
      out << "Matrices A and B are not compatible for multiplication." << endl;
   }
   //closes file
   out.close();

   return 0;
   }
