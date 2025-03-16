/*
Functions Lab
Updated By: Aubrey Charlson
CSCI 111
Date: 3/11/2025

Program prompts the user to enter two points in the form (x1, y1) and (x2, y2) and finds the distance between the two points using a function.
Algorithm steps:
   1. Define a function called findDistance(…) that takes four parameters x1, y1 and x2, y2 as two points
       a. finds the distance between them using the equation: √((x2-x1)^2 + (y2-y1)^2)
       b. returns the calculated distance value
   2. Prompt user to enter two points in (x, y) format
   3. Store them into 4 individual variables
   4. Call function getDistance by passing 4 entered numbers as arguments
   5. Display results with proper description. Format output numbers to 2 decimal points.
   6. Test and validate that program output is correct for a given set of input points.
   7. BONUS - (10 points) Using a loop repeat step 2-6 until the user wants to quit.
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
using namespace std;

const float epsilon = 1e-5; // 0.00001 accuracy upto 5 decimal points; error of margin

// function prototypes

// Function that calculates the distance between two points
// x1, y1 and x2, y2 and returns the calculated value
float findDistance(int, int, int, int);
bool gamestate();
// test function that runs automated testing
void test();

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main()
{
    int x1, y1, x2, y2; // variables to store two points (x1, y1) and (x2, y2)
    float dist; //FIXED 
    char ch;
    bool gs = true;

    //FIXME-bonus - 10 bonus points - add loop until user wants to quit
    while(gs) {
    // the loop will execute the following block of code
        {
            clearScreen();
            cout << "Program calculates distance between 2 points on a 2D coordinate." << endl;
            cout << "Enter a point in the form (x, y): ";
            // parse the input stream
            cin >> ch >> x1 >> ch >> y1 >> ch; // value stored in ch is ignored
            printf("(x1, y1) = (%d, %d)\n", x1, y1);

            cout << "Enter a second point in the form (x, y): ";
            //FIXME3 - Read/parse the second point and store data into variables x2 and y2
            cin >> ch >> x2 >> ch >> y2 >> ch; //FIXED

            //FIXME4 - Call test function
            test(); //FIXED

            //FIXME5 - call findDistance function passing proper arguments
            dist = findDistance(x1, y1, x2, y2); //FIXED

            //FIXME6 – Using printf function display the returned distance with proper description
            printf("The distance between %i, %i, & %i, %i is: %F \n", x1, x2, y1, y2, dist); //FIXED
            cin.ignore(1000,'\n');
            cout << "\nPress enter to continue: \n" << endl;
            cin.get();
            clearScreen();
            gs = gamestate();
        }
    }
    cin.ignore(1000, '\n');
    cout << "Enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;

}

float findDistance(int x1, int y1, int x2, int y2)
{
    // FIXME7 - Find the distance between (x1, y1) and (x2, y2)
    float distance;
    distance = sqrt( ( pow( (x2-x1), 2) ) + ( pow( (y2-y1), 2) ) );  //Fixed

    // following the algorithm in step 1
    // return the calculated distance
    return distance;
}

// test function that test findDistance function with 3 test cases
void test()
{
    float result =  findDistance(4, 3, 5, 1);
    float expected = 2.236067f;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin
    // FIXME8 - add at least two more test cases
    result =  findDistance(5, 8, 7, 3);
    expected = 5.385164f;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin

    result =  findDistance(3, 6, 9, 8);
    expected = 6.324555f;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin
    cerr << "all tests passed..." << endl;
}

bool gamestate()
{
    /* We will use an if statement to determine wether the program should continue. 
       If there were more than 2 states (on/off) I would instead use a switch */
    char uI; // For storing User Input
    cout << "Would you like to calculate another distance? (Y/N)" << endl;
    // Because I'm bored I am going to have this check user input before continuing using another while loop
    while (true) 
    {
        cin >> uI;
        cin.ignore(1, '\n'); // We are only looking for a Y or N so we will limit the input to 1 character or a return key

        if (uI == 'Y' || uI == 'y' || uI == 'N' || uI == 'n')
        {
            break;
        } //We don't need an 'else:continue' here  it will do that natively

    }
    if (uI == 'n' || uI == 'N' )
    {
        return false;
    } else {return true;}


    

}