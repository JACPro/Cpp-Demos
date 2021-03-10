#include <iostream>

using namespace std;

/*
These coding challenges were performed as end of chapter exercises from
the book "Think Like a Programmer" by V. Anton Spraul.

Chapter 2 - Drawing shapes character by character
*/

void downwardsTriangle()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 8 - (2 * i); k++)
        {
            cout << "#";
        }
        cout << endl;
    }   
}

void upwardsTriangle()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 8 - (2 * (3-i)); k++)
        {
            cout << "#";
        }
        cout << endl;
    }   
}

void diamond()
{
    upwardsTriangle();
    downwardsTriangle();
}

void crossSpace(int count)
{
    for (int j = 0; j < count; j++)
    {
        cout << " ";
    }
}

void crossHash(int count)
{
    for (int k = 0; k <= count; k++)
    {
        cout << "#";
    }
}

void cross()
{
    //top half
    for (int i = 0; i < 4; i++)
    {
        crossSpace(i);
        crossHash(i);
        crossSpace(12 - (i * 4));
        crossHash(i);
        cout << endl;        
    }

    //bottom half
    for (int i = 3; i >= 0; i--)
    {
        crossSpace(i);
        crossHash(i);
        crossSpace(12 - (i * 4));
        crossHash(i);
        cout << endl;        
    }
}

void square()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if (row == 0 || row == 7)
            {
                cout << "#";
            }
            else if (col == 0 || col == 7)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    // cout << "Downwards Triangle: " << endl;
    // downwardsTriangle();
    // cout << endl << "Upwards Triangle:" << endl;
    // upwardsTriangle();
    // cout << endl << "Diamond:" << endl;
    // diamond();
    // cout << endl << "Cross:" << endl;
    //cross();
    // cout << endl << "Square:" << endl;
    //square();
}