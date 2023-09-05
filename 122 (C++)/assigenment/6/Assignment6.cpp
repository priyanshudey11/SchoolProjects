/*
Priyanshu Dey 
2/21/2023
This program reverses from little to big endian, or vice versa. Prints out the user-entered number in hexadecimal 
and binary, reverse the endianness, and prints the reverse in hexadecimal and binary.
*/
// include input/output stream library
#include <iostream>
// declare constant values for integer and byte sizes
// in bytes
const int INTSIZE = 4; 
// in bits
const int BYTESIZE = 8; 
// nibble, in bits
const int NIBSIZE = 4; 

// define union to allow for easy conversion between integer and byte representations
union integer4 
    {
    // integer representation of the union
    unsigned int intrep; 
    // array of bytes representing the integer
    unsigned char byterep[INTSIZE]; 
    };

// function to get hexadecimal digit for a given value
char get_hex_digit(int value) 
    {
        if (value < 10) 
            {
                return value + '0';
            } 
        else 
            {
                return value - 10 + 'A';
            }
    }

// function to print a byte in hexadecimal format
void prHex(unsigned char c)
    {
        std::cout << get_hex_digit((c >> 4) & 0xF) << get_hex_digit(c & 0xF) << " ";
    }

// function to print a byte in binary format
void prBin(unsigned char c) 
    {
    for (int i = 7; i >= 0; i--) 
        {
            std::cout << ((c >> i) & 1);
        }
    }

// main function
int main()
{
    //asks for number
    integer4 num;
    std::cout << "Enter an unsigned integer in base 10 => ";
    std::cin >> num.intrep;
    //prints hex
    std::cout << "In hex: " << std::endl;
    for (int i = INTSIZE - 1; i >= 0; i--) 
        {
            prHex(num.byterep[i]);
        }
    std::cout << std::endl;
    //prints binary
    std::cout << "In binary: " << std::endl;
    for (int i = INTSIZE - 1; i >= 0; i--) 
        {
            prBin(num.byterep[i]);
            std::cout << " ";
        }
    std::cout << std::endl;
    //Reverse endian
    std::cout << "\nReverse endian: " << std::endl;
    integer4 reversed;
    //funcition to referverse endian
    for (int i = 0; i < INTSIZE; i++) 
        {
            reversed.byterep[i] = num.byterep[INTSIZE - i - 1];
        }
    //hex
    std::cout << "In hex: " << std::endl;
    for (int i = INTSIZE - 1; i >= 0; i--) 
        {
            prHex(reversed.byterep[i]);
        }
    std::cout << std::endl;
    //binary 
    std::cout << "In binary: " << std::endl;
    for (int i = INTSIZE - 1; i >= 0; i--) 
        {
            prBin(reversed.byterep[i]);
            std::cout << " ";
        }
    std::cout << std::endl;
    // return statement to exit the program
    return 0; 
}