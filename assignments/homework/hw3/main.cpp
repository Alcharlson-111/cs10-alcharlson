
/* 
    Note to Professor: I know you had mentioned in class that you prefer 
    spaced functions. For the sake of line count I did mostly in-line functions. 
    I hope that this is still plenty readable. I wrote it in one-take then did 
    necessary debugs. 


*/

/*
Functions Program
Class: CS10
Author: Aubrey Charlson
Date: 3/11/2025

This program will be able to act as a calculator with the following functions: 
1. Addition
2. Subtraction
3. Multiplication
4. Division 
5. Division with remainder
6. Power operations
7. Square Root

Additionally, it will run a test to verify the functionality of all functions
then print the outputs to the terminal.
*/

#include <iostream> 
#include <cmath> // To keep me sane
#include <vector>
using namespace std;

bool test(), iValidation();
int printMenu();
void cLoop();
void printAll(float, float);
float add(float, float), sub(float, float), mlt(float, float),
     divi(float, float), rem(float, float), pwr(float, float),
     root(float);
// Declaring all functions at once to save space and increase legibility.  
     


int main() {
    float x, y;
    vector<int> xHist;
    vector<int> yHist;
    bool loop = true;
    int loopNum = 0;
    char r; 
    test();
    
    while (loop) {
        int menu = 0;

        // Show menu only when loopNum != 0
       

        // Loop for entering x and y values
        while (true) {
            cout << "Please enter two numbers separated by a space then press enter: \n";
            cin >> x >> y;

            if (iValidation()) {
                break;
            } else {
                cout << "Invalid input. ";
            }
        }
        
        // Store valid inputs and print them
        printAll(x, y);
        xHist.push_back(x);
        yHist.push_back(y);
        
        menu = printMenu();
        cout << "\n\n" << endl;
        switch (menu) {
            case 1:
                break;

            case 2:
                for (int i = loopNum; i >= 0; i--) {
                    printAll(xHist[i], yHist[i]);
                }
                cout << "\nPress enter to continue: \n" << endl;
                cin.get();
                cin.get(); // To consume the newline character
                cout << "\nContinue (Y/N):\n" << endl;
                cin >> r;
                if (r == 'n' || r == 'N')
                {loop = false;}
                cout << "\n\n" << endl;
                break;
                
            
            case 3:
            default:
                loop = false;
                break;
        }
        cout << "\n\n Loop Number: " << loopNum << "\n\n" <<endl;

        
        
        loopNum++;
    }

    return 0;
}

float add(float x, float y) { return x + y; }
float sub(float x, float y) { return x - y; }
float mlt(float x, float y) { return x * y; }
float divi(float x, float y) { return (y != 0) ? x / y : 0; } 
// Avoid division by zero using short hand conditional
float rem(float x, float y) { return static_cast<int>(x) % static_cast<int>(y); } 
// In order to avoid breaking the rest of the code which is float dependent
// I found a solution on stack exchange that allows for floats to be converted 
float pwr(float x, float y) { return pow(x, y); } 
float root(float h) { return (h >= 0) ? sqrt(h) : -1; }  
// Handle negative input using short hand conditional

bool test()
{
    if (!(add(9, 4) == 13)) { cout << "Operation failed at addition\n"; return false; }
    if (!(sub(4, 9) == -5)) { cout << "Operation failed at subtraction\n"; return false; }
    if (!(mlt(9, 4) == 36)) { cout << "Operation failed at multiplication\n"; return false; }
    if (!(divi(9, 4) == 2.25)) { cout << "Operation failed at division\n"; return false; }
    if (!(rem(9, 4) == 1)) { cout << "Operation failed at remainder division\n"; return false; }
    if (!(pwr(9, 4) == 6561)) { cout << "Operation failed at the power operation\n"; return false; }
    if (!(root(9) == 3)) { cout << "Operation failed at the square root operation\n"; return false; }

    return true;
}

void printAll(float x, float y)
{
    printf("The sum of \n %f + %f is %f\n\n", x, y, add(x, y));
    printf("The difference between \n %f - %f is %f\n\n", x, y, sub(x, y));
    printf("The product of\n %f * %f is %f\n\n", x, y, mlt(x, y));
    printf("The quotient of\n %f / %f is %f\n\n", x, y, divi(x, y));
    printf("The remainder of\n %f / %f is %f\n\n", x, y, rem(x, y));
    printf("The power of\n %f^%f is %f\n\n", x, y, pwr(x, y));
    printf("The square root of\n %f is %f\n\n", x, root(x));
    printf("The square root of\n %f is %f\n\n", y, root(y));
}


// Input validation 
bool iValidation () 
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
    return true;
}

int printMenu()
{
    int v;
    cout << "Please select an option from the list: \n"
        << "\t1. Continue\n"
        << "\t2. History\n"
        << "\t3. Exit\n";
    cin >> v;
    return v;
}