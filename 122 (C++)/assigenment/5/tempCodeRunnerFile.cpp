#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char* line = new char[100];  // allocate initial memory for input
    
    cout << "Enter a word, phrase, or sentence: ";
    cin.getline(line, 100);  // read initial input
    
    // check if the input exceeded the initial memory allocation
    if (cin.gcount() == 100 && line[99] != '\n') {
        int curr_size = 100;
        char* temp = nullptr;
        char c;
        
        // read and reallocate memory until the end of the input is reached
        while (cin.get(c)) {
            if (c == '\n') {
                break;
            }
            
            if (curr_size == strlen(line)) {
                temp = new char[curr_size * 2];
                strncpy(temp, line, curr_size);
                delete[] line;
                line = temp;
                curr_size *= 2;
            }
            strncat(line, &c, 1);
        }
    }
    
    char* token;
    char* rest = line;
    
    while ((token = strtok(rest, " "))) {
        string word(token);
        string pig;
        int len = word.length();
        int i = 0;
        
        if (isVowel(word[0])) {
            pig = word + "-ay";
        } else {
            while (i < len && !isVowel(word[i])) {
                i++;
            }
            if (i == len) {
                pig = word + "-ay";
            } else {
                pig = word.substr(i) + word.substr(0, i) + "ay";
            }
        }
        cout << pig << " ";
        rest = NULL;
    }
    cout << endl;

    delete[] line;  // free dynamically allocated memory
    
    return 0;
}
