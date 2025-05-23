/*
Kattis - Hissing Microphone Problem

By: Aubrey Charlson
Date: 4/24

Hissing Microphone Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read string
2. find "ss" substring in the string
    - if found, print "hiss"
    - otherwise, print "no hiss"
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
    {
        solve();
    }
        return 0;
}

string answer(const string &line) {
    // FIXME3
    if (line.find("ss") != string::npos)
    {
        return "hiss";
    } else {return "no hiss";} //FIXED
    // implment algorithm step 2
    // return "hiss" if ss is found in line
    // otherwise, return "no hiss"
    
}

// unit testing answer()
void testAnswer() {
    // FIXME4
    assert(answer("This-should-pass") == "hiss");
    assert(answer("Not-in-this1") == "no hiss");
    assert(answer("Please-hiss:) ") == "hiss");//FIXED
    // write at least two test cases to test answer()
    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;
    // string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5
    getline(cin, line);//FIXED
    // read string into line
    cout << answer(line) << endl;
}