/* 
Author: Aubrey Charlson
Class: CS110
Date 3/2

Purpose: To calculate the perimeter and area of a Triangle-
- based on user inputed variables assigned to the sides of-
- the triangle. 

*/



#include <iostream> // For input-output
#include <string>  // I don't yet know if I will need this -- Just in case
#include <cmath>  // To use a square root function in Heron's formula for triangle area
#include <limits>// To protect input stream 
#include <iomanip> // To set decimal limits on output

using namespace std;


/*--- Functions ---*/
void namePrompt(); // Request and return user's name
void calculatorFunctions(); // Calulates 
double calculatorInput(); // Verifies input integrity 
void calculatorLoop(); // Loop until user chooses to exit using the menu
bool menuOptions(); // Provide options for the user



int main(){
    namePrompt();
    calculatorLoop();

    return 0;
}



void namePrompt()
{
    string name;

    cout << "Welcome to the Triangle Calculator!\n\n"
        << "Please Enter your name:\t";
    getline(cin, name); 
    
    cout << "Hello, " << name << ", the Triangle Calculator will prompt you for the sides\n of a triangle then return "
        << "the area and perimeter\n of that triangle in the terminal. " << endl;
}

double calculatorInput()
{
    double input;

    while (true) {
        // Read input
        
        cout << "Please enter a side length then press return:\t" ;
        cin >> input;
        // cin.ignore(7, '/n'); // Allows up to 7 digits permitting up to 5 decimal places
       
        if (cin.fail()) // Checks for non numeric input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input type! Please try again.\n\n" << endl;
            continue;
        }
        if (input <=0) // Verifies input is positive
        {
            cout << "Invalid input! Please enter a value greater than zero.\n\n";
            continue;
        }
        return input;
    }
    
        
}

void calculatorFunctions()
{
    double l1 = 0 , l2 = 0, l3 = 0;
    double area, perim, s;    
    

    cout << "\n\n" << "Please enter three side lengths." << endl;
    
    while (true)
    {
        l1 = calculatorInput();
        l2 = calculatorInput();
        l3 = calculatorInput();
        
        if (  ((l1 + l2)< l3) || ((l1 + l3)< l2) || ((l3 + l2)< l1) )
        {
            cout << "\nThis is an impossible triangle.\n One of the sides exceeds the sum of the other two sides.\n"
            << "Please re-enter the sides of your triangle.\n";
            continue;

        }
        break;
    }


    perim = l1 + l2 + l3;
    s = perim/2;
    area = sqrt( (s-l1) * (s-l2) * (s-l3) );
 
    cout << "\n\n" << "The area of your triangle is:\t" << area << setprecision(7) << " and the perimeter of the triangle is:\t" << perim << setprecision(7) << endl;

}


bool menuOptions() 
{
    int selection; 
    cout << "Please make a selection:\n\t1.Calculate another triangle\n\t2.Exit\n" << endl;
    cin >> selection; 

    switch (selection)
    {
    case (1):
        return true;
        break; // Tells the calculator loop to continue

    case (2): 
        return false;
        break; // Tells the calculator loop to exit

    default:
        return false;
        break; // Defaults to exit loop
    }
}

void calculatorLoop() 
{
    bool unit = true;
    while (unit)
    {
        calculatorFunctions();
        unit = menuOptions();
    }
    cout << "\n\n\nThank you for using the Triangle Calculator!" << endl;
}
