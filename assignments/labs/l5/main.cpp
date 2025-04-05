/*
    Loops Lab
    Updated By: Aubrey Charlson // FIXED 1
    CSCI 111
    Date: 4/5 FIXED 2

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    cout << "\nTriangle  " << height << " tall. \n" << endl;
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


void printFlippedTriangle(int height) {
    /* 
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *
    
    */
    // FIXME3 ...
    cout << "\nUpside down triangle  " << height << " tall. \n" << endl;
    int row = 1;
    int col = height;
    while (row <= height) 
    {
        for (int i = 0; i !=  col; i++)
            cout << "* ";


        row+=1;
        col--;
        cout << endl;
    }

    // FIXED 3
    
}


/*  
FIXME4
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   

*/
void printSquare(int height)
{
    cout << "\nSquare  " << height << " tall. \n" << endl;
    for (int row = height; row > 0; row--)
    {
        for (int col = height; col > 0; col--)
            cout << "*  ";
        cout << endl;
    }
} //FIXED 4


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

int main(int argc, char* argv[]) {
    // FIXME5 add a loop to make the program to continue to run until the user wants to quit
    int pass = 0;
    while (true) // FIXED 5
        {
        
        // FIXME6 call clearScreen function to clear the screen for each round of the loop
        clearScreen(); // FIXED 6
        
        
        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;
        // call printTriangle function passing user entered height
        printTriangle(height);

        // FIXME7
        // Call printFlippedTriangle passing proper argument
        // Manually test the function
        printFlippedTriangle(height); // FIXED 7

        // FIXME8
        // Call the function defined in FIXME4 passing proper argument
        // Manually test the function
        printSquare(height); // FIXED 8

        // FIXME9
        // prompt user to enter y/Y to continue anything else to quit
            cout << "\n\nProgram loop pass: " << pass << "." << endl;
            pass++;
            char ch; 
            cout << "\n\n Would you like to continue (y/n):  ";
            cin >> ch;
            // FIXED 9
            

        // FIXME10
        // Use conditional statements to break the loop or continue the loop
            if (ch == 121 || ch == 89)
                continue;
            else 
            {
                cout << "\n\nThank you for using this program! " << endl; 
                break;
            }
            // FIXED 10 
            
        }
        

    return 0;
}