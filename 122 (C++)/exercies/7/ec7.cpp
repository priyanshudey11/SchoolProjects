/*
Priyanshu Dey
*/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstring>

using namespace std;

// Set the maximum number of rows and columns for matrices
const int MAX_ROWS = 6;
const int MAX_COLS = 6;

// Function to print a matrix
void print_matrix(int matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j]; // Output the element at this position in the matrix
        }
        cout << endl; // Move to the next row
    }
}

// Function to load a matrix from a file
void load_attribute_matrix(ifstream& input_file, int attribute1_size, int attribute2_size, int rows, int cols, int matrix[][MAX_COLS]) {
    int attribute1, attribute2, value; // Variables to hold the data read from the file
    int row, col; // Variables to store the position in the matrix where the value should be stored
    int i = 0; // Counter for the number of values read from the file
    bool yes = false, no = false; // Flags to indicate if there are any positive or negative values in the matrix
    int matrixone[MAX_ROWS][MAX_COLS] = {0}; // Temporary matrix to hold values read from the file

    // Loop through each row of the matrix
    for (int i = 0; i < rows; i++) {
        input_file >> attribute1 >> attribute2 >> value; // Read a line of data from the file
        row = attribute2 - 4; // Calculate the row index for the matrix
        col = attribute1 - 1; // Calculate the column index for the matrix
        double attributerow1c = col + 0.5 * ((row + 1) % 2); // Calculate the row index for the matrix when the matrix is shifted by half a cell horizontally
        double attributerow1r = row + 0.5; // Calculate the column index for the matrix when the matrix is shifted by half a cell vertically

        cout << "i = " << i << " j = " << row << " k = " << col << " fileData = " << value << endl; // Output debugging information
        if (value >= 10) { // Check if the value is positive
            yes = true;
        } else { // Otherwise, it is negative
            no = true;
        }

        matrixone[int(attributerow1c)][int(attributerow1r)] = value; // Store the value in the temporary matrix
        i++; // Increment the counter for the number of values read from the file
    }

    // Copy the values from the temporary matrix to the output matrix
    for (int i = 0; i < MAX_COLS; i++) {
        for (int j = 0; j < MAX_ROWS; j++) {
            matrix[i][j] = matrixone[i][j];
        }
    }
}

// This function calculates the entropy of a given set of yes and no counts
double calculate_entropy(double yes_count, double no_count) {
double total_count = yes_count + no_count; // Calculate the total number of instances
double yes_ratio = yes_count / total_count; // Calculate the ratio of instances that are labeled as "yes"
double no_ratio = no_count / total_count; // Calculate the ratio of instances that are labeled as "no"
double entropy = 0.0;
if (yes_ratio != 0.0 && no_ratio != 0.0) { // Check if both ratios are non-zero
entropy = -yes_ratio * log2(yes_ratio) - no_ratio * log2(no_ratio); // Calculate the entropy using the formula
} else if (yes_ratio != 0.0) { // If only "yes" instances are present
entropy = -yes_ratio * log2(yes_ratio); // Calculate the entropy using the formula for "yes" instances only
} else if (no_ratio != 0.0) { // If only "no" instances are present
entropy = -no_ratio * log2(no_ratio); // Calculate the entropy using the formula for "no" instances only
}
return entropy; // Return the calculated entropy value
}

// This function calculates the information gain for each row in the matrix
void calculate_gain(int matrix[][MAX_COLS], int rows, int cols, double& max_gain, int& max_gain_row) {
double initial_entropy = calculate_entropy(4.0, 3.0); // Calculate the initial entropy using the total counts
max_gain = 0.0;
max_gain_row = -1;

// Loop through each row in the matrix
for (int i = 0; i < rows; i++) {
    double yes_count = 0.0, no_count = 0.0;
    double attribute_entropy = 0.0;
    // Loop through each column in the row
    for (int j = 0; j < cols; j++) {
        if (matrix[i][j] == 1) { // If the instance is labeled as "yes"
            yes_count++;
        } else { // If the instance is labeled as "no"
            no_count++;
        }
    }
    attribute_entropy = calculate_entropy(yes_count, no_count); // Calculate the entropy for the row
    double gain = initial_entropy - attribute_entropy; // Calculate the information gain for the row
    // Print the row number, the number of "yes" and "no" instances, the entropy and the gain
    cout << "row = " << i << " yes = " << yes_count << " no = " << no_count <<" entropy = " << attribute_entropy << " gain = " << gain << endl;
    if (gain > max_gain) { // Check if the current gain is higher than the maximum gain so far
    max_gain = gain;
    max_gain_row = i; // Update the row number with the maximum gain
    }
}
}

// This function loads data from a file and then performs some calculations on that data.
int main() {
// Declare a string variable to hold the input file name and prompt the user to enter the file name.
string filename;
cout << "Enter the name of the input file => ";
cin >> filename;
// Declare an input file stream object and try to open the file with the given file name.
ifstream input_file(filename);
if (!input_file.is_open()) { // If the file cannot be opened, print an error message and return with a non-zero exit code.
    cout << "Cannot open " << filename << endl;
    return 1;
}

// Declare variables to hold sizes and counts and initialize some variables.
int attribute1_size, attribute2_size, total_attributes, rows, cols;
double yes_count = 0.0, no_count = 0.0;

// Read in the first line of the input file and extract the attribute sizes, number of attributes, and dimensions of the data matrix.
input_file >> attribute1_size >> total_attributes >> rows >> cols;
attribute2_size = total_attributes - attribute1_size;

// Declare and initialize two data matrices to hold attribute values for each attribute type.
int attribute1_matrix[MAX_ROWS][MAX_COLS] = {0};
int attribute2_matrix[MAX_ROWS][MAX_COLS] = {0};

// Load the attribute values from the input file into the two data matrices.
load_attribute_matrix(input_file, attribute1_size, attribute2_size, rows, cols, attribute1_matrix);
load_attribute_matrix(input_file, attribute2_size, attribute1_size, cols, rows, attribute2_matrix);

// Close the input file stream.
input_file.close();

// Print out the first data matrix and the transpose of the second data matrix.
cout << "Attribute 1 matrix:" << endl;
print_matrix(attribute1_matrix, attribute1_size, attribute2_size);

cout << "Attribute 2 matrix (transposed):" << endl;
print_matrix(attribute2_matrix, attribute2_size, attribute1_size);

// Calculate the information gain for each row of the first data matrix and print out the best attribute for the root node.
double max_gain;
int max_gain_row;
calculate_gain(attribute1_matrix, attribute1_size, attribute2_size, max_gain, max_gain_row);
cout << "Best attribute for the root node: Attribute 1, row " << max_gain_row + 1 << ", gain = " << fixed << setprecision(4) << max_gain << endl;

// Calculate the information gain for each row of the transpose of the second data matrix and print out the best attribute for the next node.
calculate_gain(attribute2_matrix, attribute2_size, attribute1_size, max_gain, max_gain_row);
cout << "Best attribute for the next node: Attribute 2, row " << max_gain_row + 1 << ", gain = " << fixed << setprecision(4) << max_gain << endl;

return 0;
}
