/*
Priyanshu Dey 
2/14/22
This program is a program that alters a word, phrase, or sentenc words to Pig Latin where
consonants are moved from the front of the word to the end and the letters “ay” are then added to the end. 
*/

#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGSsc
using namespace std;

// function to check if a character is a vowel
bool isVowel(char c) 
   {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
   }

int main() 
{
   // allocate initial memory for input
    char* line = new char[100];  
    //gets word from user
    cout << "Enter a word, phrase, or sentence: ";
    // read initial input
    cin.getline(line, 100);  
    
    // check if the input exceeded the initial memory allocation
    if (cin.gcount() == 100 && line[99] != '\n')
     {
      // declare character array to store input
        int curr_size = 100;
        //temporaruly store contents of the original line
        char* temp = nullptr;
        //read each character of input
        char c;
        
        // read and reallocate memory until the end of the input is reached
        while (cin.get(c))
         {
            if (c == '\n') 
               {
                  break;
               }
            //sees if there needs to be a buffer that needs to be expanded for memory 
            if (curr_size == strlen(line))
               {
                  //new buffer size 
                  temp = new char[curr_size * 2];
                  //Copies the contents of the old buffer
                  strncpy(temp, line, curr_size);
                  //Frees the old buffer to prevent memory leaks.
                  delete[] line;
                  //Sets the line pointer to point to the new buffer, 
                  line = temp;
                  // Updates the curr_size variable to reflect the new size of the buffer, which is twice the previous size.
                  curr_size *= 2;
               }
            //ensures that the buffer is null-terminated
            strncat(line, &c, 1);
        }
    }
    // declare pointer to character to store each token
    char* token;
    // initialize pointer to the beginning of the input array
    char* rest = line;
    
    // loop through each token in the input string
    while ((token = strtok(rest, " "))) 
      {
         //makes it easier to work with
         string word(token);
         //declares the new word
         string pig;
         //length of the word
         int len = word.length();
         int i = 0;
         // if the first letter of the token is a vowel, add "-ay" to the end of the token
         if (isVowel(word[0])) 
            {
                  pig = word + "-ay";
            }
         // otherwise, move all consonants before the first vowel to the end of the token and add "-ay"
         else 
            {
                  while (i < len && !isVowel(word[i]))
                     {
                        i++;
                     }
                  // no vowels found in word, treat as a special case and add "-ay" to the end
                  if (i == len)
                     {
                        pig = word + "-ay";
                     } 
                  else 
                     {
                        pig = word.substr(i) + word.substr(0, i) + "ay";
                     }
            }
      // print the pig latin translation of the current token, followed by a space
        cout << pig << " ";
      // set the rest pointer to NULL to indicate that subsequent calls to strtok should start at the beginning of the string
        rest = NULL;
    }
   // print a newline character to end the output
    cout << endl;
   // free dynamically allocated memory
    delete[] line;  
    return 0;
}