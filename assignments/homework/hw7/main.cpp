/*
Author: Aubrey Charlson
Class: CSCI 111
Date: 5/7

Program info: 
Divides a series of integers dillemeted by a space into two integers.
The max integer always goes to the least recent integer to recieve - 
an addition. 

Algorithmn steps:
    1. Get the number of pieces : getSize()
    2. Get string of pieces and fill array : getPieces()
    3. Add pieces to Alice & Bob : splitPieces()
        a. Sort array in descending order
        b. Loop through array
        c. Conditionally add integer to Alice or Bob 
    4. Tests() to confirm function
    5. Cry after 5th attempt
*/




#include <iostream>
#include <algorithm> // for sort
#include <limits> // for cin.ignore
#include <cassert>
using namespace std;

int getSize();
void getPieces(int size, int arr1[]);
void splitPieces(int size, int arr1[], int &, int &);
void tests();

int main(int argc, char* argv[]) 
{
    if(argc == 2 && string(argv[1]) == "test")
    {tests(); return 0;}
    int a = 0, b = 0; // initialize bob & alice
    int size = getSize(); 
    // initilize size
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // clear left over input from getSize();

    int arr1[100]; // initialize array

    getPieces(size, arr1);
    splitPieces(size, arr1, a, b);
    cout << a << " " << b << endl;
    // print alice' and bob's totals
    return 0;
}

int getSize() 
{
    int size;
    cin >> size;
    return size;
    // initializes variable to capture and
    // return the number of pieces
}

void getPieces(int size, int arr1[]) 
{
    for (int i = 0; i < size; ++i) 
    { // runs until there are no more pieces
        cin >> arr1[i]; 
        // fills pieces into array

    }
}

void splitPieces(int size, int arr1[], int &a, int &b) {
    // sort descending
    sort(arr1, arr1 + size, greater<int>());

    for (int i = 0; i < size; ++i) 
    { // runs until there are no more pieces
        if (i % 2 == 0) a += arr1[i]; 
        // on even alice gets piece
        else b += arr1[i];
        // on odd it goes to bob
    }
    
}

void tests()
{
    int a1[5] = {6, 2, 3, 1, 1};
    int a2[10] = {9, 4, 3, 2, 5, 2, 7, 4, 8, 8};
    int a3[7] = {5, 2, 6, 5, 9};
    int s1 = 5, s2 = 10, s3 = 7;
    // init test array and pieces


    int a = 0, b = 0; // init bob & alice
    splitPieces(s1,a1, a, b);
    // split up pieces
    assert(a == 9); // verify outcome
    assert(b == 4);
    a = 0; 
    b = 0;
    cout << " test [1/3] complete." << endl;
    // confirm completion

    // repeat:

    splitPieces(s2, a2, a, b);
    assert(a == 28);
    assert(b == 24);
    a = 0; 
    b = 0;
    cout << " test [2/3] complete." << endl;

    splitPieces(s3, a3, a, b);
    assert(a == 16);
    assert(b == 11);
    cout << " test [3/3] complete." << endl;
}