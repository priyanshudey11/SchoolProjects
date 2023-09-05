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

// Define a struct to store the data for each attribute
struct Attribute {
    int numValues;
    int **matrix;
};

// Function to calculate the entropy of a system
double entropy(int *counts, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        double p = static_cast<double>(counts[i]) / size;
        if (p != 0) {
            total -= p * log2(p);
        }
    }
    return total;
}

// Function to calculate the information gain of an attribute
double informationGain(Attribute attribute, int *outcomes, int numOutcomes) {
    int total = numOutcomes;
    double attributeEntropy = 0;
    for (int i = 0; i < attribute.numValues; i++) {
        int counts[attribute.numValues] = {0};
        for (int j = 0; j < numOutcomes; j++) {
            int value = attribute.matrix[i][outcomes[j]];
            if (value >= 0) {
                counts[value]++;
            }
        }
        double rowEntropy = entropy(counts, attribute.numValues);
        attributeEntropy += static_cast<double>(counts[0] + counts[1]) / total * rowEntropy;
    }
    return entropy(outcomes, numOutcomes) - attributeEntropy;
}

// Function to calculate and print the gain of an attribute
void print_attribute_gain(Attribute attribute, int num_yes, int num_no, double system_entropy, int numOutcomes) {
    double attribute_entropy = 0;
    for (int i = 0; i < attribute.numValues; i++) {
        int yes_count = 0;
        int no_count = 0;
        for (int j = 0; j < numOutcomes; j++) {
            if (attribute.matrix[i][j] == 1) {
                yes_count++;
            }
            else if (attribute.matrix[i][j] == 0) {
                no_count++;
            }
        }
        double d = yes_count + no_count;
        double row_entropy = entropy(new int[2]{yes_count, no_count}, 2);
        attribute_entropy += (d / (num_yes + num_no)) * row_entropy;
        cout << "row = " << i << " yes = " << yes_count << " no = " << no_count << " d = " << d << " entropy = " << fixed << setprecision(6) << row_entropy << endl;
    }
    double gain = system_entropy - attribute_entropy;
    cout << "(Attribute entropy = " << fixed << setprecision(6) << attribute_entropy << ") " << fixed << setprecision(7) << gain << endl;
}

// Function to transpose a matrix based on a given row
void transpose(Attribute& attribute, int transposeRow) {
    int numColumns = attribute.numValues;
    int numRows = attribute.matrix[transposeRow][0];
    int **newMatrix = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        newMatrix[i] = new int[numColumns];
        for (int j = 0; j < numColumns; j++) {
            newMatrix[i][j] = attribute.matrix[j][i];
        }
    }
    for (int i = 0; i < numColumns; i++) {
        delete[] attribute.matrix[i];
    }
    delete[] attribute.matrix;
    attribute.matrix = newMatrix;
    attribute.numValues = numRows;
}

int main() {
    string fileName;
    cout << "Enter the name of the input file => ";
    cin >> fileName;

    // Read the data from the input file
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return 1;
    }
    int numAttributes, numExamples;
    inputFile >> numAttributes >> numExamples;

    Attribute attributes[numAttributes];
    for (int i = 0; i < numAttributes; i++) {
        int numValues;
        inputFile >> numValues;
        attributes[i].numValues = numValues;
        attributes[i].matrix = new int*[numValues];
        for (int j = 0; j < numValues; j++) {
            attributes[i].matrix[j] = new int[numExamples];
        }
    }

    for (int j = 0; j < numExamples; j++) {
        for (int i = 0; i < numAttributes; i++) {
            int attributeValue;
            inputFile >> attributeValue;
            attributeValue--;
            attributes[i].matrix[attributeValue][j] = i < numAttributes - 1 ? attributeValue : attributeValue == 0 ? 1 : 0;
        }
    }
    inputFile.close();

    // Print the attribute matrices
    for (int i = 0; i < numAttributes - 1; i++) {
        cout << "Attribute " << i + 1 << " matrix:" << endl;
        for (int j = 0; j < attributes[i].numValues; j++) {
            for (int k = 0; k < numExamples; k++) {
                cout << setw(3) << attributes[i].matrix[j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Transpose the matrix for the last attribute
    transpose(attributes[numAttributes - 1], 0);

    // Compute and print the system entropy
    int counts[2] = {0};
    for (int i = 0; i < numExamples; i++) {
        int outcome = attributes[numAttributes - 1].matrix[0][i];
        counts[outcome]++;
    }
    int numYes = counts[1];
    int numNo = counts[0];
    double systemEntropy = entropy(counts, numExamples);
    cout << "Yes = " << numYes << " No = " << numNo << endl;
    cout << "System entropy = " << fixed << setprecision(6) << systemEntropy << endl;

    // Compute and print the information gain for each attribute
    for (int i = 0; i < numAttributes - 1; i++) {
        double gain = informationGain(attributes[i], attributes[numAttributes - 1].matrix[0], numExamples);
        cout << "Attribute " << i + 1 << " gain = " << fixed << setprecision(7) << gain << endl;
    }

    return 0;
}
