#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <iostream>

using namespace std;

//Declaration
//translates one digit, using the strings specified for the one, five, and ten values
string roman_digit(int n, string one, string five, string ten);
//convert integer numbers to roman numbers
string get_roman_numeral(int n);
//covert one roman to number
int get_value(char a);
//convert roman numerals to integer numbers
int roman_to_decimal(string roman_numeral);

//Definition

//TODO

#endif // ROMAN_NUMERAL_H