#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

// -- FUNCTIONS -- //
//Functions must be declared before the main function
int addNumbers(int firstNum, int secondNum = 0) //can set a default value for param, but must come after other params
{
    return firstNum + secondNum;
}

//Overloaded function - same name, different parameters
int addNumbers(int firstNum, int secondNum, int thirdNum)
{
    return firstNum + secondNum + thirdNum;
}
// -- SECTION END -- //



// -- TIME -- //
string secondsToTime(int seconds)
{
    string time;

    int hours = trunc(seconds / 3600);
    seconds = seconds % 3600;
    time = (hours > 9 ? "" : "0") + hours;

    int minutes = trunc (seconds / 60);
    seconds = seconds % 60;
    time += (minutes > 9 ? ":" : ":0") + minutes;

    if (seconds == 0) {time += ":00";} else if (seconds > 9 ) {time += ":" + seconds;} else {time += ":0" + seconds;}

    return time;
}
// -- SECTION END -- //



// -- RECURSION -- //
//Recursive functions call themselves
int getFactorial(int number)
{
    int sum;
    if (number == 1) {
        sum == 1;
    }
    else
    {
        sum = getFactorial(number - 1) * number;
    }
    return sum;
}
// -- SECTION END -- //



// -- REFERENCE PARAMETERS -- //
void rewindTime(int* year)
{
    cout << "Rewinding from " << *year << endl;
    *year = (*year > 20 ? *year - 20 : 0);
}

void  backToReality(int& year)
{
    year = 2021;
}
// -- SECTION END -- //



// -- CLASSES -- //
//Using classes helps to model real-world objects
class Animal 
{
    //Attributes of the model (e.g. size, shape) -- variables
    //Capabilities of the model (e.g. running, increasing temperature) -- functions

    //Private variables can only be changed by functions within that class - this is encapsulation
    private:
        int height; 
        int weight;
        string name;
        
        //Use static for variables that are shared by all objects of a class
        static int numAnimalTypes;

    public:
        int getHeight() { return height; }
        int getWeight() { return weight; }
        string getName() { return name; }

        //Encapsulation - protect stored values from outside changes
        void setHeight (int cm) { height = cm; }
        void setWeight (int kg) { height = kg; }
        void setName (string newName) {name = newName; }

        //Constructor - name MUST be identical to that of the class
        Animal(int, int, string);

        //Destructor
        ~Animal();

        //Overloaded constructor (i.e. receives different parameters)
        Animal();


        //Static methods are shared by all objects of a class - they can only use static variables
        static int getNumAnimalTypes() { return numAnimalTypes; }

        void toString();
};

//Declare class instance
int Animal::numAnimalTypes = 0;

Animal::Animal(int height, int weight, string name)
{
    this->height = height; 
    this->weight = weight;
    this->name = name;
    Animal::numAnimalTypes++;
}

Animal::~Animal()
{
    cout << "Animal: " << this -> name << " was destroyed." << endl;
}

Animal::Animal()
{
    Animal::numAnimalTypes++;
}

void Animal::toString()
{
    cout << this -> name << " is " << this -> height << " cms tall and " <<
        this -> weight << " kgs." << endl;
}

//Inheritance
class Cat : public Animal
{
    private:
        string sound = "Meow";
    
    public:
        void getSound()
        {
            cout << sound << endl;
        }
    
        Cat(int, int, string, string);

        Cat() : Animal(){};

        void toString();
    
};


Cat::Cat(int height, int weight, string name, string sound) :
Animal(height, weight, name)
{
    this -> sound = sound;
}

void Cat::toString()
{
    cout << this -> getName() << " is " << this -> getHeight() << " cms tall and " 
    << this -> getWeight() << " kgs. It says: " << this -> sound << endl;
}
// -- SECTION END -- //

int main()
{
    // -- OUTPUT -- //
    {
    cout << "Hello World" << endl;
    
    cout << endl;
    }
    // -- SECTION END -- //



    // -- DATA TYPES -- // 
    {
    const double PI = 3.1415926535; //const = can't be changed
    char myChar = 'A'; //1 byte of memory
    bool isBool = true; // 1 byte of memory
    int myInt = 23; //4 bytes of memory
    float myFloat = 1.1234567; //7 decimal digits of precision - 4 bytes of memory
    double myDouble = 1.123456789012345; //15 decimal digits of precision - 8 bytes of memory

    cout << "My float: " << myFloat << endl;

    /*
    Other Data Types:

    short int : >= 16 bits
    long int : >= 32 bits
    long long int : >= 64 bits
    unsigned int : same as unsigned int
    long double : > double size
    */

    cout << "Size of int: " << sizeof(myInt) << endl; //use sizeof to find out how much memory a variable uses

    cout << endl;
    }
    // -- SECTION END -- //



    // -- ARITHMETIC OPERATORS -- //
    {
    /*
    + : addition
    - : subtraction
    * : multiplication
    / : division
    % : modulo (remainder after division)
    ++ : increment +1
    -- : decrement -1
    */

    //Arithmetic operations follow the order of operations laid out by bodmas:

    cout << "1 + 2 - 3 * 2 = " << 1 + 2 - 3 * 2 << endl; //-3
    cout << "(1 + 2 - 3) * 2 = " << (1 + 2 - 3) * 2 << endl; //0

    cout << endl;
    }
    // -- SECTION END -- // 



    // -- INCREMENTING VARIABLES -- //
    {
    //Increment and decrement operations can occur before or after a line is executed,
    //depending on whether they are before or after the variable name
    int ten = 10;

    cout << "Increment after: 10++ = " << ten++ << endl; //10
    ten = 10;
    cout << "Increment before: ++10 = " << ++ten << endl; //11
    ten = 10;
    cout << "Decrement after: 10-- = " << ten-- << endl; //10
    ten = 10;
    cout << "Decrement before: --10 = " << --ten << endl; //9

    //You can also use shorthand to apply arithmetic operations to the current value of a variable
    ten = 10;
    ten += 5;
    cout << "10 += 5 : " << ten << endl; //15
    ten = 10;
    ten -= 5;
    cout << "10 -= 5 : " << ten << endl; //5

    cout << endl;
    }
    // -- SECTION END -- //



    // -- CASTING -- //
    {
    //Casting can be used when you want to treat variables/values as if they are of a certain type

    cout << "4 / 5 = " << 4 / 5 << endl; //rounds down to 0
    cout << "(float) 4 / 5 = " << (float) 4 / 5 << endl;

    cout << endl;
    }
    // -- SECTION END -- //



    // -- COMPARISON AND LOGICAL OPERATORS -- //
    {
    /*
    Comparison operators:
    == : equal to
    != : not equal to
    > : greater than
    < : less than
    >= : greater than or equal to
    <= : less than or equal to
    */

    /*
    && : and (all conditions must be true)
    || : or (one of the conditions must be true)
    ! : not (condition must be false)
    */

    }
    // -- SECTION END -- //



    // -- IF OPERATORS -- //
    {
    int age = 23;
    int ageAtLastExam = 20;
    bool isSober = true;

    if (age < 17)
    {
        cout << "You are too young to drive." << endl;
    }
    else if (age >= 70 && ageAtLastExam < 70)
    {
        cout << "You must renew your licence when you turn 70." << endl;
    }
    else if (age >= 70 && age - ageAtLastExam > 3)
    {
        cout << "You must get renew your license every 3 years after turning 70." << endl;
    }
    else
    {
        cout << "You may drive." << endl;
    }

    cout << endl;
    }
    // -- SECTION END -- //



    // -- SWITCH STATEMENTS -- //
    {
    //Use switch statements when you want to check for a large number of different variable values

    int userSelection = 3;

    switch (userSelection)
    {
        case 1:
            cout << "Ham" << endl;
            break;
        case 2: 
            cout << "Cheese" << endl;
            break;
        case 3: cout << "Coke" << endl;
            break;
        default:
            cout << "ERROR: INVALID SELECTION" << endl;
    }

    cout << endl;
    }
    // -- SECTION END -- // 



    // -- TERNARY OPERATOR -- //
    {
    //Shorthand method for performing one operation if a conidtion is true and another if it is false;
    //i.e. variable = (condition) ? true : false

    int getLargestNum = 5 > 2 ? 5 : 2; // sets value to 5 if condition (5 > 2) is true; sets valu to 2 if false

    }
    // -- SECTION END -- //



    // -- ARRAYS -- //
    {
    //Arrays contain a collection of variables or objects

    int lotteryNos[6]; //array of 6 integers
    int winningNos[6] = {10, 22, 25, 41, 44, 49}; //initialised array

    cout << "The first winning lottery number is: " << winningNos[0] << endl;

    //Multi-dimensional arrays are arrays of arrays
    //(e.g. an array of size 5, where each elemnent contains its own array of size 6)

    char rubixFace[3][3] = 
    {
        {'R', 'W', 'Y'}, //outer array 1
        {'B', 'Y', 'B'}, //outer array 2 
        {'O', 'G', 'W'} // outer array 3 
    }; //each item in the outer array contains an array of 3 chars

    cout << "Colour in middle right square: " << rubixFace[1][2] << endl;

    //change the 3rd item in the second outer array
    rubixFace[1][2] = 'W';

    cout << "Colour in middle right square: " << rubixFace[1][2] << endl;

    cout << endl;
    }
    // -- SECTION END -- //



    // -- FOR LOOPS -- //
    {
    //Used to execute code a certain number of times
    for (int i = 1; i <= 10; i++)
    {
        cout << i << endl;
    }

    //You can nest for loops
    //Print chess board (B = BLack, W = White)
    for (int col = 0; col < 8; col++)
    {
        for (int row = 0; row < 8; row++)
        {
            if ((row + col) % 2 == 0)
            {
                cout <<"W ";
            }
            else
            {
                cout << "B ";
            }
        }
        cout << endl;
    }

    cout << endl;
    }
    // -- SECTION END -- //



    // -- WHILE LOOPS -- //
    {
    //Used for repeating a section of code based on a given condition
    //Use when you don't know how many times you want a loop to iterate

    srand (time(NULL)); //generate a random seed - cause different number each execution rather than compilation
    int randNum =  (rand() % 100) + 1; //pick a random number from 1-100

    int count = 0;

    while (randNum != 100)
    {
        count++;
        randNum = (rand() % 100) + 1;
    }

    cout << "The number of random numbers generated before 100 was found is: " << count << endl;

    cout << endl;
    }
    // -- SECTION END -- //



    // -- USER INPUT AND DO WHILE LOOPS -- //
    {

    srand(time(NULL)); //generate a random seed - cause different number each execution rather than compilation
    int randNum = (rand() % 10) + 1; //pick a random number from 1-10

    string userGuess = "";
    int intUserGuess = 0;

    /*
    //Simple game that asks the user to guess a random number between 1 and 10
    //Takes input continuously until correct answer is given

    do
    {
        cout << "Guess the number between 1 & 10: ";
        getline(cin, userGuess); //take user input and store it in string variable userGuess

        intUserGuess = stoi(userGuess); //convert string input to integer

        cout << intUserGuess << endl;
    } while (intUserGuess != randNum);
    */
    cout << "You win!" << endl;

    cout << endl;
    }
    // -- SECTION END -- //



    // -- STRINGS -- //
    {
    //In C, strings are stored as arrays of characters
    char greatArr[6] = {'G', 'r', 'e', 'a', 't', '\0'}; //0 = end line
    //C++ contains a string data type
    string scott = " Scott!";

    cout << greatArr + scott << endl << endl;

    /*
    //Take user's name as input and repeat it back to them
    string userName;
    cout << "Enter your name: ";
    getline(cin, userName);

    cout << "Welcome " << userName << endl << endl;
    */

    /*
    //Simple quiz to test if user knows eulers constant
    const double eulersConstant = 0.57721;
    string eulerGuess;
    double eulerGuessdouble;    

    cout << "What is Euler's constant? ";
    getline(cin, eulerGuess);

    eulerGuessdouble = stod(eulerGuess);

    if (eulerGuessdouble == eulersConstant)
    {
        cout << "Correct!" << endl;
    }
    else
    {
        cout << "Incorrect!" << endl;
    }
    */

    /*
    //Demonstrating String operations
    string userWord;
    cout << "Enter a word: ";
    getline(cin, userWord);

    //You can get the number of characters in a string using the .size method
    cout << endl << "The number of characters in your word is: " << userWord.size() << endl;
    //You can check if a string is empty using the .empty method
    cout << "The string you entered was " << (userWord.empty() ? "empty." : "not empty.") << endl;
    //You can add more characters to the end of a string using the .append method
    cout << userWord.append(" is a great word!") << endl;
    */

    //You can compare strings as follows
    string first = "first";
    string second = "second";

    cout << endl << "Compare \"" << first << "\" to \"" << second << "\": " << first.compare(second) << endl; //return -1 if passed string is alphabetically higher
    cout << endl << "Compare \"" << first << "\" to \"" << first << "\": " << first.compare(first) << endl; //Return 0 if two strings are equal
    cout << endl << "Compare \"" << second << "\" to \"" << first << "\": " << second.compare(first) << endl << endl; //return 1 if passed string is alphabetically lower

    //You can change the value of a string using the assign function
    first.assign("third");

    cout << "New value of \"first\" is: \"" << first << "\"" << endl;

    //You can using the .substr method to get a substring of a string, starting at a given index and for a given number of characters
    //You can find the index at which a given substring begins in a given string using .find
    //the second argument of .find is the index you want to start searching from - in this case, we start from 0
    cout << "The starting index of \"" << second.substr(3, 3) << "\" in \"" << second << "\" is: " << second.find(second.substr(3, 3), 0) << endl;
    //If you search for a substring that doesn't exist in a given string, npos (-1) will be returned
    //npos is a static member constant with the greatest possible value for an element of type size_t
    //npos may be output as "4294967295" in place of "-1", as this is the largest possible unsigned int
    cout << "The starting index of \"" << first << "\" in \"" << second << "\" is: " << second.find(first, 0) << endl << endl;

    //You can insert, delete or replace characters at a given index in a string as follows:
    string myGuitar = "dot";

    cout << "My guitar is an " << myGuitar.insert(0, "Epichead ") << endl;
    cout << "The brand of my guitar is " << myGuitar.erase(8, 4) << endl; //first param = starting index, second param = no of characters to erase
    cout << "Just kidding, my guitar is actually an " << myGuitar.replace(3, 5, "phone") << endl; //first = start index, second = num chars to erase, third = string to insert at index

    cout << endl;
    }
    // -- SECTION END -- //



    // -- VECTORS -- //
    {
    //This data structure is similar to arrays, but its size can be altered after it's initialised
    vector <int> studentGrades(0);

    int jamesGrades[5] = {70, 60, 55, 80, 75};
    int alexGrades[5] = {40, 48, 78, 53, 56};

    studentGrades.insert(studentGrades.begin(), jamesGrades, jamesGrades+5); //iterator, first to add, last to add
    studentGrades.insert(studentGrades.begin(), alexGrades, alexGrades+5);

    studentGrades.insert(studentGrades.end() - 2, 98); //add a single element at a given index

    //Add a value at the end of a vector using the .push_back method
    studentGrades.push_back(50);

    int average = 0;

    for (int &grade : studentGrades) //for each loop - use & to pass by reference
    {
        cout << grade << " ";
        average += grade;
    }

    //Add a value at the end of a vector using the .push_back method

    cout << endl << "The last grade is: " << studentGrades.back() << endl; //.back for last element in vector,
    cout << "Average grade: " << average / studentGrades.size() << endl; //.size for number of elements
    cout << "First element: " << studentGrades.front() << endl; //.front for first element
    cout << "The vector is " << (studentGrades.empty() ? "empty." : "not empty.") << endl; //.empty return 1 if empty, 0 otherwise

    studentGrades.pop_back(); //remove final element 
    
    cout << endl;
    }
    // -- SECTION END -- //


    // -- RECURSION DEMONSTRATION -- //
    {
    //See recursion definition at top
    int numToFactorial = 5;
    cout << "The factorial of " << numToFactorial << " is " << getFactorial(numToFactorial) << endl;

    cout << endl;
    }
    // -- SECTION END -- //



    // -- FILE I/O -- //
    {
    string currLocation = "Gerudo Valley";

    ofstream writer("location.txt");

    if (! writer)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    else
    {
        writer << currLocation;
        writer.close();
    }
    /*
    Different ofstream parameters cause different io functionality
    ios::binary : treat the file as binary
    ios::in : open a file to read input
    ios::trunc : Default
    ios::out : open a file to write output
    */
    ofstream writer2("location.txt", ios::app); //an ofstream to write to the end of an existing file

    if (! writer2)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    else
    {
        writer2 << " - Hyrule" << endl;
        writer2.close();
    }

    char letter;

    ifstream reader("location.txt");

    if(! reader)
    {
        cout << "Error opening file" << endl;
        return -1;
    }
    else
    {
        for (int i = 0; ! reader.eof(); i++)
        {
            reader.get(letter);
            cout << letter;
        }
    }
    cout << endl;
    reader.close();

    cout << endl;
    }
    // -- SECTION END -- //



    // -- EXCEPTION HANDLING -- //
    {
    //Catch exceptions to provide system crashes and provide useful error messages

    int number = 0;

    try 
    {
        if (number != 0)
        {
            cout << 2/number << endl;
        }
        else throw (number);
    }
    catch (int number)
    {
        cout << number << " is not a valid denominator for division." << endl;
    }

    cout << endl;
    }
    // -- SECTION END -- //



    // -- POINTERS -- //
    {
    //Use reference operator & to get the memory address of where a variable is stored
    //When you pass by reference, any changes will persist outside of the function that took the reference parameter
    string myMemory = "EXPANDING MIND";

    string* memoryPointer = &myMemory; 

    cout << "Address of my memory: " << memoryPointer << endl;
    cout << "Data in my memory: " << *memoryPointer << endl; //* to dereference a pointer to get the data at that location

    //You can also create pointers to data structures such as arrays
    int longLostNums[6] = {4, 8, 15, 16, 23, 42};

    int* lostNumsPtr = longLostNums;

    cout << "Array address: " << lostNumsPtr << "\nValue at address 1: " << *lostNumsPtr << endl;
    lostNumsPtr++; //increment pointer to get next value in array
    cout << "Array address: " << lostNumsPtr << "\nValue at address 2: " << *lostNumsPtr << endl;
    //array names are just pointers to an array, meaning they can be dereferenced to get the value
    cout << "Array address: " << longLostNums << "\nValue of lost numbers: " << *longLostNums << endl << endl;

    int year = 2021;

    rewindTime(&year); //pass a parameter by reference.
    cout << "The year is now " << year << endl;

    int& yearRef = year; //& denotes REFERENCE PARAMETER
    yearRef++;
    cout << "Time has passed. It is now " << year << endl << endl;

    backToReality(yearRef);

    cout << "What a crazy dream! The year is ACTUALLY " << year << endl;

    /*
    POINTERS VS REFERENCES

    Use pointers if you don't want to initialise at declaration

    References can't change what they are pointing at, but pointers can

    */

    cout << endl;
    }
    // -- SECTION END -- //



    // -- CLASSES DEMONSTRATION -- //
    //The following code demonstrates how to instantiate objects of the classes you've declared
    Animal frog;

    frog.setHeight(10);
    frog.setWeight(1);
    frog.setName("Frog");

    frog.toString();


    Animal horse(150, 380, "Horse");

    horse.toString();

    Cat nubbin = Cat(40, 20, "Nubbin", "MEOWZAS");

    //Call superclass toString method
    nubbin.Animal::toString();

    // -- SECTION END -- //

return 0;
}