#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

// List Vars
    string fullName;
    float s1, s2, perim, area, value;
    
    // Grab name var, greet user
    string promptName()
    
    {
        cout << "Please enter your full name: " << endl; 
        getline (cin, fullName);
        return fullName;
    }
    // Greet user explain program
    void greetUser (string name)
    
    {
        cout << "Hello, " << fullName <<
        " this calculator provides the area and perimiter"<<
        " of a rectangle." << endl;
    }

    // prompt for sides
    void promptSides (string name, float &s1, float &s2)
    
    {
        cout << fullName << ", please enter the length and" <<
        " width, seperated by a space." << endl;
        cin >> s1 >> s2; 
    }
    
    // Calculate area and perimeter of rectangle
    float calP (float s1, float s2)
    
    {
        perim = (s1*2) + (s2*2);
        return perim;
    }
    
    float calA (float s1, float s2) 
    
    {
        area = s1*s2;
        return area;
    }
    void calcAll (float s1, float s2, float &area, float &perim)
    {
        perim = calP(s1,s2);
        area = calA(s1,s2);
    }
    void printVals(float s1, float s2, float area, float perim)
    
    {
        printf("A rectangle with a width of %f and length of %f will have the area %f, and a perimeter of %f\n", s1,s2,area,perim);
    }

    
int main(){
    fullName = promptName();
    greetUser(fullName);
    promptSides(fullName, s1, s2); 
    calcAll(s1, s2, area, perim);
    printVals(s1,s2,area,perim);
}