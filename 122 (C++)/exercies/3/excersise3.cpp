/*
Priyanshu Dey
3/14/23
program prompts the user for a string (100 characters max) and either validates if it is a postive number,indentifier,or an invalid string
*/

#include <iostream>
#include <string>

using namespace std;

// Define the FSM transition rules
string transition_rule(string current_state, char input_char)
{
    // Check current state and input character, and return the next state
    if (current_state == "start")
        {
        // If the input character is an alphabet or underscore, transition to identifier state.
            if (isalpha(input_char) || input_char == '_')
                {
                    return "identifier";
                }
            // If the input character is a digit, transition to integer state.
            else if (isdigit(input_char))
                {
                    return "integer";
                }
            // If the input character is a comma or period, stay in the start state.
            else if (input_char == ',' || input_char == '.')
                {
                    return "start";
                }
        }
    else if (current_state == "identifier")
        {
            // If the input character is an alphabet, digit or underscore, stay in the identifier state.
            if (isalpha(input_char) || isdigit(input_char) || input_char == '_')
                {
                    return "identifier";
                }
            // If the input character is a comma or period, transition to the start state.
            else if (input_char == ',' || input_char == '.')
                {
                    return "start";
                }
        }
    else if (current_state == "integer")
        {
            // If the input character is a digit, stay in the integer state.
            if (isdigit(input_char))
                {
                    return "integer";
                }
    // If the input character is a comma or period, transition to the start state.
            else if (input_char == ',' || input_char == '.')
                {
                    return "start";
                }
        }
    // If none of the rules match, the input is invalid.
    return "invalid";
    }

int main()
{
    //prompt the user to input a string
    string input_str;
    cout << "Enter a string (100 characters max): ";
    cin >> input_str;
    // Set the initial state and token to "start"
    string current_state = "start";
    string current_token = "";

    // Loop through each character in the input string
    for (int i = 0; i < input_str.length(); i++) 
    {
        char input_char = input_str[i];
        // Get the next state based on the current state and input character
        current_state = transition_rule(current_state, input_char);
        // If the input is invalid, print an error message and exit
        if (current_state == "invalid") 
            {
                cout << "Invalid string beginning at: " << input_str.substr(i-1) << endl;
                break;
            } 
        else if (current_state == "start")
            {
                // If a token has ended, print it out with its type
                if (current_token != "") 
                    {
                        if (isdigit(current_token[0]))
                            {
                                cout << current_token << "\tpositive integer" << endl;
                            } 
                        else 
                            {
                                cout << current_token << "\tidentifier" << endl;
                            }
                    }
            current_token = ""; // Reset the current token
            } 
        else 
            { 
                // If the token is still ongoing, append the input character to it
                current_token += input_char;
            }
    }
    // Check for final token at end of input
    if (current_state != "invalid" && current_token != "") 
        {
            if (isdigit(current_token[0])) 
            {
                cout << current_token << "\tpositive integer" << endl;
            }
            else 
            {
                cout << current_token << "\tidentifier" << endl;
            }
        }
    return 0;
}