#include <iostream>
#include <fstream> 

using namespace std;

// Recursive function to generate permutations
void generate_permutations(char* chars, int start, int end, ofstream& outfile, int& count) 
{
    // Base case: reached end of permutation
    if (start == end) 
    { 
        // Increment the permutation count
        count++; 
        outfile << "Permutation " << count << ": ";
        // Print out the current permutation
        for (int i = 0; i <= end; i++) 
        { 
            outfile << chars[i] << " ";
        }
        outfile << endl;
    }
    // Recursive case: generate all permutations
    else
     { 
        for (int i = start; i <= end; i++) 
        {
            // Swap the characters at positions start and i
            char temp = chars[start];
            chars[start] = chars[i];
            chars[i] = temp;
            // Generate permutations for remaining characters
            generate_permutations(chars, start+1, end, outfile, count);
            // Swap back the characters to their original positions
            temp = chars[start];
            chars[start] = chars[i];
            chars[i] = temp;
        }
    }
}

int main() {
    int n, count = 0;
    char chars[6]; // Array to hold the characters
    ofstream outfile("permutations.txt"); // Output file stream

    // Prompt user for number of characters and character data
    cout << "Enter the number of characters you want to permute => ";
    cin >> n;
    cout << "Enter " << n << " characters => ";
    // Read in the characters
    for (int i = 0; i < n; i++) 
    { 
        cin >> chars[i];
    }

    // Generate permutations and store in output file
    generate_permutations(chars, 0, n-1, outfile, count);
    // Close the output file
    outfile.close(); 
    cout << "Permutations stored in 'permutations.txt'" << endl; // Inform the user of the output file name
    return 0;
}
