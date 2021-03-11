#include <iostream>

using namespace std;

/*
These coding challenges were performed as end of chapter exercises from
the book "Think Like a Programmer" by V. Anton Spraul.

Chapter 2 - Converting a limitless binary number (entered character by character) to decimal
*/

int main()
{
    int total = 0;
    char digitChar;
    cout << "Enter a binary number. Press enter when done: " << endl;
    digitChar = cin.get();
    while(digitChar != 10)
    {
        total *= 2;
        if (digitChar == '1')
        {
            total +=1;
        }

        digitChar = cin.get();
    }    
    cout << endl << "Your number in decimal is: " << total;
}