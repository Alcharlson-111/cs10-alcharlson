#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){

    // List Vars
    string fullName;
    float s1, s2, perim, area;
    
    // Grab name var, greet user
    getline(cin, fullName); 
    cout << "Hello, " << fullName << 
        "welcome to the rectangle calculator. " << endl;

    // Grab vars for rectangle
    cout << "Enter the numeric length of two sides of your rectangle"
     << endl;
    cin >> s1 >> s2 ;

    // Save area and perimeter calculations to vars
    area = (s1*s2);
    perim = (2*s1) + (2*s2);

    // Return to user
    printf("Your rectangle with sides %f and %f has an area of %f anda perimeter of %f \n"
        , s1, s2, area, perim);


}