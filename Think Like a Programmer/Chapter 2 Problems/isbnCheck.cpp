#include <iostream>

using namespace std;

/*
These coding challenges were performed as end of chapter exercises from
the book "Think Like a Programmer" by V. Anton Spraul.

Chapter 2 - Checking whether an ISBN is valid

--------------------------------
RULES FOR VALIDITY CHECK OF ISBN
--------------------------------
1. Calculate 10 x the first digit, plus 9 times the second digit etc. until
you reach the last digit, which you multiply by 1 before adding to the total.

2. The last digit is the check digit, and may have values 0-9 or 10, which is
represented by the character 'X'. 

3. If the sum you calculated leaves a remainder of 0 when divided by 11, the 
ISBN number is valid.
*/

bool checkIsbn(string isbn)
{
    int total = 0;
    for (int i = 0; i < 9; i ++) //first 9 digits
    {
        total += (10 - i) * ((int)isbn.at(i) - '0');
    }
    if (isbn.at(9) == 'X') // check digit
    {
        total += 10;
    }
    else
    {
        total += (int)isbn.at(9) - '0';
    }
    cout << "Total: " << total;
    
    if (total % 11 == 0)
    {
        return true;
    }
    return false;    
}

/*
This method takes a 9-digit ISBN number and calculates the check digit
to make a valid 10-digit ISBN number
*/
char isbnCheckDigit(string isbn)
{
    char checkDigit;
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        total += (10 - i) * ((int)isbn.at(i) - '0');
    }
    //cout << endl << "TOTAL " << total << endl;
    total = 11 - (total % 11);
    //cout << endl << "TOTAL: " << total << endl;
    if (total == 10)
    {
        checkDigit = 'X';
    }
    else if (total == 11)
    {
        checkDigit = '0';
    }
    else
    {
        checkDigit = '0' + total;
    }
    
    return checkDigit;
}

int main()
{
    if (checkIsbn("007462542X"))
    {
        cout << endl << "That ISBN is valid.";
    }
    else
    {
        cout << endl << "That ISBN is NOT valid.";
    }

    cout << endl << "The check digit for 011211242 is " << isbnCheckDigit("011211242");
}