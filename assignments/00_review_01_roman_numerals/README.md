# Review 01 - Functions - Roman to Integer

- Accept [00_review_01_roman_numerals](https://classroom.github.com/a/_Tt02KfV)
- Get [main.cpp](main.cpp)
- Get [roman_numeral.h](roman_numeral.h)

---

## Description

Write a program that converts a positive integer into the Roman number and Roman number to positive integer.

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

| Symbol | Value |
| ------ | ----- |
| I      | 1     |
| IV     | 4     |
| V      | 5     |
| IX     | 9     |
| X      | 10    |
| XL     | 40    |
| L      | 50    |
| XC     | 90    |
| C      | 100   |
| CD     | 400   |
| D      | 500   |
| CM     | 900   |
| M      | 1000  |


## Approach

A number in Roman Numerals is a string of these symbols written in descending order(e.g. M’s first, followed by D’s, etc.). However, in a few specific cases, to avoid four characters being repeated in succession(such as IIII or XXXX), **subtractive notation** is often used as follows:

- **I** placed before **V** or **X** indicates 1 less, so 4 is **IV** (1 less than 5) and 9 is **IX** (1 less than 10).
- **X** placed before **L** or **C** indicates 10 less, so 40 is **XL** (10 less than 50) and 90 is **XC** (10 less than a 100).
- **C** placed before **D** or **M** indicates 100 less, so 400 is **CD** (100 less than 500) and 900 is **CM** (100 less than 1000).


**Example 1:**

In the case, the user wants to convert to Roman numerals, your program should take input, such as:
```
Input: num = 1978
Output: "MCMLXXVIII"
Explanation: M = 1000, CM = 900, LXX = 70, VIII = 8.
```

**Example 2:**

In the case, the user wants to convert to standard numerals, your program should take input such as:
```
Input: s = "CCCXLV"
Output: 345
Explanation: CCC = 300, XL = 40, V = 5
```  

**Constraints:**

1. `1 <= s.length <= 15`
2. `s` contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
3. A valid roman numeral in range [1, 3,999], which is `1 <= num <= 3999`


## Algorithm 

Implement functions in `includes/roman_numeral/roman_numeral.h`


### Integer to Roman Numerals

Implement the following function to convert integer numbers to roman numbers:

```c++
//convert integer numbers to roman numbers
string get_roman_numeral(int n);
//translates one digit, using the strings specified for the one, five, and ten values
string roman_digit(int n, string one, string five, string ten);
```

That `roman_digit` function translates one digit, using the strings specified for the one, five, and ten values. You would call the function as follows:

```c++
roman_ones = roman_digit(n % 10, "I", "V", "X");
n = n / 10;
roman_tens = roman_digit(n % 10, "X", "L", "C");
n = n / 10;
...
```


### Roman Numerals to Integer

1. Split the Roman Numeral string into Roman Symbols (characters).
1. Convert each symbol of Roman Numerals into the value it represents.
1. Take symbols one by one starting from index 0: 
    a. If the current value of the symbol is greater than or equal to the value of the next symbol, then add this value to the running total.
    b. else subtract this value by adding the value of the next symbol to the running total.

Implement the following function to convert roman numerals to integer numbers:

```c++
//covert one roman to number
int get_value(char a);
//convert roman numerals to integer numbers
int roman_to_decimal(string roman_numeral);
```

The program should also be able to convert a Roman numeral such as `MCMLXXVIII` to its decimal number representation and decimal number to a Roman numeral. Include a menu to select from the two options.


## Notes

- Make sure your program follows the style guide.
- You should have function prototypes and function definitions.
- You should NEVER have global variables (global constants OK)
- Check your answer [here](https://www.calculatorsoup.com/calculators/conversions/roman-numeral-converter.php)
