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
