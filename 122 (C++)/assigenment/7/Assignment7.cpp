/*
Priyanshu Dey 
2/28/2023
This program recognizes palindromes and excludes spaces and punctuation
*/
#include <iostream>
#include <string>


using namespace std;

// Define a constant for the maximum size of the stack
const int MAX_STACK_SIZE = 25;

// Global variables for the stack and stack pointer
char stack[MAX_STACK_SIZE];
int stack_ptr = -1;

// Push operation
void push(char c) 
{
  // Check if the stack is full before pushing
  if (stack_ptr < MAX_STACK_SIZE - 1)
   {
    // Increment the stack pointer and add the character to the stack
    stack[++stack_ptr] = c;
  } 
  else
   {
    // If the stack is full, display an error message
    cout << "Error: Stack is full" << endl;
  }
}

// Pop operation
char pop() 
{
  // Check if the stack is empty before popping
  if (stack_ptr >= 0)
   {
    // Decrement the stack pointer and return the top character from the stack
    return stack[stack_ptr--];
  } 
  else 
  {
    // If the stack is empty, display an error message and return the null character
    cout << "Error: Stack is empty" << endl;
    return '\0';
  }
}

// Main function to check if a string is a palindrome
bool is_palindrome(string str) 
{
  // Push each non-space, non-punctuation, lowercase character onto the stack
  for (char c : str) 
  {
    // Check if the character is alphabetic before pushing if it is returns true
    if (isalpha(c)) 
    {
      // Convert the character to lowercase and push it onto the stack
      push(tolower(c));
    }
  }

  // Pop each character from the stack and compare with the corresponding character in the string
  for (char c : str) 
  {
    // Check if the character is alphabetic before comparing
    if (isalpha(c)) 
    {
      // Convert the character to lowercase and compare with the top character on the stack
      if (tolower(c) != pop()) 
      {
        // If the characters do not match, the string is not a palindrome
        return false;
      }
    }
  }

  // If all characters match, the string is a palindrome
  return true;
}

// Test the program with user input
int main() 
{
  string str;
  cout << "Enter a string: ";
  getline(cin, str);

  // Check if the string is a palindrome and display the appropriate message
  if (is_palindrome(str)) 
  {
    cout << str << " is a palindrome" << endl;
  } 
  else 
  {
    cout << str << " is not a palindrome" << endl;
  }

  return 0;
}
