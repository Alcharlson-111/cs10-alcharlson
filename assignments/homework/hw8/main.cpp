/*
Author: Aubrey Charlson
Class: CS111
Date: Today

Program:
    Inputs data from file, sorts, grades, and outputs to file.
    
Algorithmn steps:
    1. Get input file location
    2. Input to Linked List
    3. Sort LL
    4. Calculate Avg
    5. Grade
    6. Print to file
    7. Print to terminal
    8. Free heap
*/


#include "lib/ih/inhandling.h" // IO handling F(x)
#include "lib/m/math.h" // Math F(x)

string getFile();


int main()
{
    ifstream inFile("class111.txt");
    Node * head = new Node {nullptr, nullptr, nullptr}; 
    string file = getFile();
    addStu(head, file);
    sortLL(head);
    p2fLL(head);
    printLL(head);
    freeLL(head);
    return 0;

}

string getFile()
{
    string file;
    cout << "Please enter the file name:\t";
    getline(cin, file);
    return file;
}