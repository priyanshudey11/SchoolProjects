/*
Priyanshu Dey 
Feb 7th 2023
/ Writes to a file every possible seven-letter word corresponding to that number after getting a 7 digit input.*/
#include <iostream>
#include <fstream>
using namespace std;
//array declartion 
const int ROW_SIZE = 10;
const int COL_SIZE = 5;
//integer size
const int NUM_SIZE = 8;

char letters[ROW_SIZE][COL_SIZE] = {{'0', '\0', '\0', '\0', '\0'}, 
                                     {'1', '\0', '\0', '\0', '\0'},
                                     {'A', 'B', 'C', '\0', '\0'},
                                     {'D', 'E', 'F', '\0', '\0'},
                                     {'G', 'H', 'I', '\0', '\0'},
                                     {'J', 'K', 'L', '\0', '\0'},
                                     {'M', 'N', 'O', '\0', '\0'},
                                     {'P', 'Q', 'R', 'S', '\0'},
                                     {'T', 'U', 'V', '\0', '\0'},
                                     {'W', 'X', 'Y', 'Z', '\0'}};

void build_words(char *input, char letters[ROW_SIZE][COL_SIZE],
                 char *build, int index, ofstream &output)
{
    int num_index = input[index] - '0';
    for (int i = 0; letters[num_index][i] != '\0'; i++)
    {
        build[index] = letters[num_index][i];
        if (index == NUM_SIZE - 2)
        {
            build[index + 1] = '\0';
            output << build << endl;
        }
        else
        {
            build_words(input, letters, build, index + 1, output);
        }
    }
}

int main()
{
    //input number
    char input_num[NUM_SIZE];
    //
    char build_word[NUM_SIZE];
    cout << "Enter a 7-digit number: "; cin >> input_num;
    //name of putput
    string output_file = "output.txt";
    //open file 
    ofstream output(output_file);
    //combines all of the things so it ouptuts nicely
    build_words(input_num, letters, build_word, 0, output);
    //closes file
    output.close();
//tells the user where the file is stored
    cout << "The combinations for " << input_num 
         << " have been stored in " << output_file << endl;

}
