#include <iostream>

using namespace std;

enum numTypes {BINARY, HEX, DECIMAL};

/*
These coding challenges were performed as end of chapter exercises from
the book "Think Like a Programmer" by V. Anton Spraul.

Chapter 2 - Allow the user to convert freely between binary, hex and decimal
*/

int binaryToDec()
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
    return total;
}

numTypes determineType(char selection)
{
    if (selection == 'B')
    {
        cout << endl << "Binary picked." << endl;
        return BINARY;
    }
    else if (selection == 'H')
    {
        cout << endl << "Hex picked." << endl;
        return HEX;
    }
    else
    {
        cout << endl << "Decimal picked." << endl;
        return DECIMAL;
    }
}

int main()
{
    char selection;
    numTypes inputType;
    numTypes outputType;
    while (selection != 'B' && selection != 'H' && selection != 'D')
    {
        cout << "Select your input type: [B]inary, [H]ex, [D]ecimal" << endl;
        //selection = cin.get();
        cin >> selection;
        cout << endl << endl;
    }
    inputType = determineType(selection);
    selection = '-';
    while (selection != 'B' && selection != 'H' && selection != 'D')
    {
        cout << "Select your output type: [B]inary, [H]ex, [D]ecimal" << endl;
        selection = cin.get();
        cout << endl << endl;
    }
    outputType = determineType(selection);

    cout << endl << "You selected: " << inputType << " for input and: " << outputType << " for output.";

    switch (inputType)
    {
        case BINARY:
            switch (outputType)
            {
                case BINARY:
                    cout << "No conversion needed." << endl;
                    break;
                case HEX:
                    //binaryToHex();
                    break;
                case DECIMAL:
                    cout << "Your number in decimal is " << binaryToDec();
                    break;
                default:
                    break;
            }
            break;
        case HEX:
            switch (outputType)
            {
                case BINARY:
                    //hexToBinary();
                    break;
                case HEX:
                    cout << "No conversion needed." << endl;
                    break;
                case DECIMAL:
                    //hexToDecimal();
                    break;
                default:
                    break;
            }
            break;
        case DECIMAL:
            switch (outputType)
            {
                case BINARY:
                    //decimalToBinary();
                    break;
                case HEX:
                    //decimalToHex();
                    break;
                case DECIMAL:
                    cout << "No conversion needed." << endl;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    cout << endl << "Thank you for using this number converter." << endl;
}