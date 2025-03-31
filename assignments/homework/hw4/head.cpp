#include "head.h" // I thought this was cool in class so I wanted to try
#include <iostream>
#include <vector> 
#include <string> // To use strings
#include <istream> // For getline()
#include <sstream> // So I can adjust decimals before appending
#include <iomanip> // Adjust decimal precision
#include <cassert> // To test operations
#include <cmath>  // Required for fabs() -- In testing function

#define EPSILON 1e-6  // tolerance value

void greetUser()
{
    string uName;
    cout << "Please enter your name: \n" << endl; 
    getline(cin, uName);
    printBreak();
    cout << "Hello " << uName << "! Welcome to my program. \n" << endl;
    
}

void printResults(string operation, double results, vector<double> v1, int eoz)
{
    string output;
    string eozOutput = "";
    for (size_t i = 0; i != 5; i++)
    {
        ostringstream oss; //So I can adjust decimals before appending
        oss << fixed << setprecision(2) << v1[i]; 
        output += oss.str(); // Appends vector output
        if (i != v1.size() -1)
        {output += ", ";} // Adds a comma for readability
    }

    /*

    The following switch and conditional was born out necessity not choice
    I am too tired to rewrite so many things to get the floor function
    to print and test properly
    
    */
    
    if (eoz == 5)
    {
         cout << "The " << operation << " of " << output << " is "
         << results << fixed << setprecision(4) << "." << endl;
    }
    else 
    {
        switch (eoz)
        {
        case 0:
            eozOutput = "zero";
            break;
        case 1:
            eozOutput = "an odd number";
            break;
        case 2:
            eozOutput = "an even number";
            break;  
        }


        cout << "The " << operation << " of " << output << " is "
         << eozOutput << "." << endl;

    }
}

void menuChoice(bool& state)
{
    unsigned int choice;
    // double eoz;
    
    cout  << "Please select an option from the following menu: \n\n"
          << " 1. Sum \n\n"
          << " 2. Product \n\n"
          << " 3. Average \n\n"
          << " 4. Maximum value \n\n"
          << " 5. Minimum value \n\n"
          << " 6. Odd, Even or Zero \n\n"
          << " 7. All operations\n\n"
          << " 8. Exit \n\n" 
          << endl; 
    cin >> choice;

    if (choice == 8)
    {
        state = false;
        cout << "\n\nThank you for using the program. Goodbye!" << endl;
        return;
    }// break out of function before calling inputNum()

    string output;
    printBreak();
    vector<double> v1 = inputNum();

    switch (choice)
    {
    case 1:
        printBreak();    
        printResults("Sum", (outSum(v1)), v1, 5);
        printBreak();
        break;


    case 2:
        printBreak();
        printResults("Product", (outPro(v1)), v1, 5);
        printBreak();
        break;


    case 3:
        printBreak();    
        printResults("Average", (outAvg(v1)), v1, 5);
        printBreak();
        break;


    case 4:
        printBreak();
        printResults("Maximum value", (outMax(v1)), v1, 5);
        printBreak();
        break;


    case 5:
        printBreak();
        printResults("Minimum value", (outMin(v1)), v1, 5);
        printBreak();
        break;


    case 6:
        printBreak();         
        printResults("floor sum", 0, v1, (outEOZ(v1)));   
        printBreak();
        break; 

    case 7:
        printResults("Sum", (outSum(v1)), v1, 5);
        printBreak();
        printResults("Product", (outPro(v1)), v1, 5);
        printBreak();
        printResults("Average", (outAvg(v1)), v1, 5);
        printBreak();
        printResults("Maximum value", (outMax(v1)), v1, 5);
        printBreak();
        printResults("Minimum value", (outMin(v1)), v1, 5);
        printBreak();
        printResults("floor sum", 0, v1, (outEOZ(v1)));
        // To use the same function for print results
        printBreak();
        break;
    case 8:
        state = false;
        break;
        
    default:
        cout << "\nThis is not an option. Please try again. \n" << endl;
        break;
    }
    
    
          
}

void printBreak()
{
    cout << "\n\n __________________________________________________________\n" 
         << endl;
}
vector<double> inputNum()
{
    vector<double> v1(5); // Easier than managing 5 variables
    cout << "Please enter 5 numbers: " << endl;
    cin >> v1[0]  >> v1[1]  >> v1[2]  >> v1[3]  >> v1[4] ;
    cin.ignore(100, '\n');
    return v1;
}

double outSum(vector<double> &v1)
{
    double total = 0;
    for (int i=0; i != 5; i++)
    {
        total += v1[i];
    }
    return total;
} 

double outPro(vector<double> &v1)
{
    double total = 1;
    for (int i=0; i != 5; i++)
    {
        total *= v1[i];
    }
    return total;
} 

double outAvg(vector<double> &v1)
{
    double total = (outSum(v1))/5;
    // Calls sum function and outputs average
    return total;
}

double outMax(vector<double> &v1)
{
    double cMax = v1[0]; // Set Current Max to the first number
    for(int i = 0; i!= 5; i++)
    {
        if (cMax <= v1[i]) // Compare Current max to each number in rotation
        {
            cMax = v1[i]; // If the cMax becomes current number if it is <=
        }
    }
    return cMax;
}
/*
By using this method I am able to check each number once so O = n;
*/
double outMin(vector<double> &v1)
{
    double cMin = v1[0]; // Set Current Min to the first number
    for(int i = 0; i!= 5; i++)
    {
        if (cMin >= v1[i]) // Compare Current min to each number in rotation
        {
            cMin = v1[i]; // If the cMin becomes current number if it is >=
        }
    }
    return cMin;
}

int outEOZ(vector<double> &v1)
{
    double sum = outSum(v1);
    int intSum = (int)sum; 
    int eoz;

    // If sum is zero return 0
    if (intSum == 0)
    {
        eoz = 0;
        return eoz;
    }
    
    if (sum < 0 && intSum != sum)
    {
        intSum--;  // Adjust for negative sums to floor it manually
    }

    // Check if the result is even or odd
    if (intSum % 2 == 0)
    {
        eoz = 2;  // Even sum
    }
    else
    {
        eoz = 1;  // Odd sum
    }
    cout << "\n\n" << endl; // For readability
    return eoz;
}

void program()
{
    testOperations();
    bool state = true;
    while (state)
    {
        menuChoice(state);
    }
}

void testOperations()
{
    vector<double> vt1 = {1, 0, 1.3, -100, 2};
    vector<double> vt2 = {4, -1, 9.88, 13, 4};
    vector<double> vt3 = {2, 1, -2, -1, 0};
    
    // Sum tests
    assert(fabs(outSum(vt1) - (-95.7)) < EPSILON);
    assert(fabs(outSum(vt2) - 29.88) < EPSILON);
    assert(fabs(outSum(vt3) - 0) < EPSILON);
    cout << "Operation [1/6 passed], 12 tests remaining...\n"; 

    // Product tests
    assert(outPro(vt1) == 0);  // Contains a zero, so product must be 0
    assert(fabs(outPro(vt2) - (-2055.04)) < EPSILON);  
    assert(outPro(vt3) == 0);  // Contains a zero, so product must be 0
    cout << "Operation [2/6 passed], 8 tests remaining...\n";

    // Average tests
    assert(fabs(outAvg(vt1) - (-19.14)) < EPSILON);
    assert(fabs(outAvg(vt2) - 5.976) < EPSILON);
    assert(fabs(outAvg(vt3) - 0) < EPSILON);
    cout << "Operation [3/6 passed], 9 tests remaining...\n";

    // Max tests
    assert(outMax(vt1) == 2);
    assert(outMax(vt2) == 13);
    assert(outMax(vt3) == 2);
    cout << "Operation [4/6 passed], 6 tests remaining...\n";

    // Min tests
    assert(outMin(vt1) == -100);
    assert(outMin(vt2) == -1);
    assert(outMin(vt3) == -2);
    cout << "Operation [5/6 passed], 3 tests remaining...\n";

    // Even/Odd/Zero tests (EOZ)
    assert(outEOZ(vt1) == 2);  // Even sum
    assert(outEOZ(vt2) == 1);  // Odd sum
    assert(outEOZ(vt3) == 0);  // Zero sum
    cout << "Operation [6/6 passed], All tests complete.\n\n" 
         << "Continuing to program.\n\n\n" << endl;
}