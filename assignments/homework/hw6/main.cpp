/*
Author: Aubrey Charlson
Date: 4/29
Class: CSCI111

    Program: take string input, return same string without repeated chars. 

    Algorithmn steps:
        1. F(x) for taking string input;
        2. F(x) for appending chars to new string, return new string
        3. Run in main
        4. F(x) tests
*/

#include <iostream> 
#include <string> 
#include <cassert>

using namespace std;

string inputHandling();
void outputHandling(string &str);
void tests();

int main(int argc, char* argv[]) 
{
    if(argc == 2 && string(argv[1]) == "test")
    {tests();}
    string str = inputHandling();
    outputHandling(str);
    // cout << "\nDEBUG: " << str;
    cout << str;
}

string inputHandling()
{
    string tmp; // Init string
    // cout << "Enter a string: ";

    cin >> tmp; // Input to string
    // cout << "\nDEBUG: " << tmp << endl;

    return tmp; // Return string
}
void outputHandling(string &str)
{
    int current = 0, end = str.length(); // init loop conditions
    string tmp, cTmp, pTmp; // init tmp char containers
    string sTmp; // init temp string
    while (current < end)
    {
        cTmp = str.at(current); // set to current itterator
        if (current + 1 == end) // if last loop
        {
            // adds final character without checking

            // cout << "DEBUG Last pass. ";
            sTmp.append(cTmp);
            break; // break loop to avoid out-of-range err
        }


        int parser = current + 1;
        pTmp = str.at(parser);
        // Set parser values

        if (cTmp != pTmp) // verify next character 
        {sTmp.append(cTmp);} // save current to temp string

        // cout << "DEBUG " << sTmp;
        current++; // move iterator

    }
    str = sTmp; // save new string to old value
    // cout << "DEBUG: " << str << endl;

}

void tests()
{
    string str1 = "password"; // Init string to change
    outputHandling(str1); // Call function
    assert(str1 == "pasword"); // Test for change
    cout << "Test [1/3] passed" << endl; // Inform user
    str1 = "aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccc";
    outputHandling(str1); // repeat process
    assert(str1 == "abc");
    cout << "Test [2/3] passed" << endl;
    str1 = "pleassefiixmystriiing";
    outputHandling(str1);
    assert(str1 == "pleasefixmystring");
    cout << "Test [3/3] passed" << endl;
}
