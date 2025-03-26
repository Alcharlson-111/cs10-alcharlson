/*
Conditional Lab

FIXME1: Write programmer information
Class: CS10
Debugger: Aubrey Charlson

FIXME2: Today's Date
Date 3/25/25

Program finds statistical values of two given numbers using user-defined functions.

A menu-driven program that demonstrates user-defined functions, automated testing conditional statements and loop.
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
 
using namespace std;
 
// function prototypes

// function prints menu options
void printMenu(void);
 
// function prompts user to enter two numbers
// the numbers are stored in the parameters provided
void getTwoNumbers(double &, double &);
 
// function takes two numbers; finds and returns the sum of the two
double findSum(const double &, const double &);
 
// function takes two numbers; finds and returns the 2nd subtracted from the first
double findDifference(const double &, const double &);
 
// function takes two numbers; finds and returns the product of them
double findProduct(const double &, const double &);
 
// function takes two numbers; finds; returns the quotient of first divided by the second
double findQuotient(const double &, const double &);
 
// function takes two numbers; finds and returns the average of the two
void findAverage(const double &, const double &, double &);
 
// function takes two numbers; finds and returns the larger of the two
double findLarger(const double &, const double &);
 
// function takes two numbers; finds and returns the smaller of the two
double findSmaller(const double &, const double &);
 
void test();

bool program();

// function clears the screen using system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    bool keepRunning = true;
    if(argc == 2 && string(argv[1]) == "test") {
        test();
        exit(EXIT_SUCCESS); // exit the program
    }
    else {
        // this loop will keep the program running until user wants to quit
        while (true) {
            if (!program()) // call program
                break; // break loop if program returned false
            cin.ignore(100, '\n');
            cout << "Enter to continue...";
            cin.get();
            clearScreen();
        }
    }
    cin.ignore(100, '\n');
    cout << "Enter to quit the program.\n";
    cout << "Good bye..." << endl;
    cin.get();
    return 0;
}

void printMenu(void) {
    cout << "Menu options:\n";
    cout << "[1] Add two numbers\n";
    cout << "[2] Subtract two numbers\n";
    cout << "[3] Multiply two numbers\n";
    cout << "[4] Divide two numbers\n";
    cout << "[5] Find larger of two numbers\n";
    cout << "[6] Find smaller of two numbers\n";
    cout << "[7] Find average of two numbers\n";
    cout << "[8] Quit the program\n";
    cout << "Enter one of the menu options [1-8]: ";
}

void getTwoNumbers(double &n1, double &n2) {
    cout << "Enter two numbers separated by a space: ";
    cin >> n1 >> n2;
}

double findSum(const double &n1, const double &n2) {
    return (n1 + n2);
}

double findDifference(const double &n1, const double &n2) {
    //FIXME3 - subtract n2 from n1 and return the difference
    return (n1 - n2); //FIXED
}

double findProduct(const double &n1, const double &n2) {
    //FIXME4 - multiply n1 by n2 and return the product
    return (n1 * n2); //FIXED
}

void findAverage(const double &n1, const double &n2, double &avg) {
    //FIXME5 - find the average of n1 and n2 and update avg
    //FIXME6 - Must call findSum function to find the sum of n1 and n2
    *&avg = (findSum(n2, n1) / 2); //FIXES 5 & 6 
    // Note: this void function doesn't return a value but
    // the average will be stored in avg
}   

double findLarger(const double &n1, const double &n2) {
    //find the larger of n1 and n2 and return it
    double larger = (n1 >= n2) ? n1 : n2;
    return larger;
}

double findSmaller(const double &n1, const double &n2) {
    //FIXME7 - find the smaller of n1 and n2 and return it
    return ((n1 <= n2) ? n1 : n2); //FIXED
}

double findQuotient(const double &n1, const double &n2) {
    //FIXME8 - divide n1 by n2 and return the quotient
    return (n1 / n2); //FIXED
}

// functions to run automated testing for various user-defined functions
void test() {
    double avg;
    double answer = findSum(10, 12.5);
    double expected = 22.5;
    assert(answer == expected); // test case 1
    assert(findSum(-5, 10.5) == 5.5); // test case 2

    // FIXME9 – Using assert function write at least 2 test cases for each of the following functions
    // findDifference(), findProduct(), findLarger(),
    assert(findDifference(10, -5) == 15);
    assert(findDifference(-3.33, 1) == -2.33);
    assert(findProduct(2, 3.1415) == 6.283);
    assert(findProduct(-2, -2) == 4);
    assert(findLarger(-10000, 10) == -10000);
    assert(findLarger(10.1111,10.1112) ==10.1112); 
    // findSmaller(), findQuotient(), findAverage()
    assert(findSmaller(10.1111, 10.1112) == 10.1111);
    assert(findSmaller(1, -10) == -10);
    assert(findQuotient(3.1415, 2) == 1.57075);
    assert(findQuotient(.5, .25) == 2);  
    findAverage(13, 222, avg);
    assert(avg == 117.5);
    findAverage(-3, 15, avg);
    assert(avg == 6);
    //FIXED                                           
    printf("%s\n", "all test cases passed...");
}

// the crux of the program that uses all the defined functions
// the program is menu driven
bool program() {
    int option = 1; // variable to store user entered option
    double num1=0, num2=0; // variables to store two numbers entered by user
    // display menu options
    printMenu();
    // Input validation
    do {
        if (cin >> option && option >= 1 && option <= 8) {
            //input is valid, break loop
            break;
        }
        else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid option, please enter a value between 1 and 8" << endl;
        }
    } while (true);
            
    // Call the function(s) or perform some operations based on user input
    switch(option) {
        case 1:
        {
            // get two numbers and store them into num1 and num2 using function
            getTwoNumbers(num1, num2);
            // call findSum function; store the returned value in sum variable
            double sum = findSum(num1, num2);
            // display the result with proper description
            printf("%.2f + %.2f = %.2f\n", num1, num2, sum);
            break;
        }
        case 2:
        {
            //FIXME10: call getTwoNumbers function
            getTwoNumbers(num1, num2);
            //FIXME11: call findDifference function and print the result
            printf("%.2f - %.2f = %.2f\n", num1, num2, (findDifference(num1, num2)));
            break;
        }
        case 3:
        {
            getTwoNumbers(num1, num2);
            //FIXME12: get two numbers and find their product using functions
            printf("%.2f * %.2f = %.2f\n", num1, num2, (findProduct(num1, num2)));
            break;
        }
        // FIXME13: complete the rest of the cases 4, 6, and 7
        case 4:
        {
            getTwoNumbers(num1, num2);
            printf("%.2f / %.2f = %.2f\n", num1, num2, (findQuotient(num1, num2)));
            break;
        }
        case 5:
        {
            // get two numbers
            getTwoNumbers(num1, num2);
            // find the larger of the two numbers
            double max = findLarger(num1, num2);
            // print the result
            printf("larger between %.2f & %.2f is %.2f\n", num1, num2, max);
            break;
        }
        case 6:
        {
            // get two numbers
            getTwoNumbers(num1, num2);
            // find the larger of the two numbers
            double min = findSmaller(num1, num2);
            // print the result
            printf("smaller between %.2f & %.2f is %.2f\n", num1, num2, min);
            break;
        }
        case 7 :
        {
            // get two numbers
            getTwoNumbers(num1, num2);
            double avg;
            findAverage(num1, num2, avg);
            printf("the average of %.2f & %.2f is %.2f\n", num1, num2, avg);
            break;
        }
        case 8:
        default: // must be option 8
            return false; // exit the program
    }
    return true;
}