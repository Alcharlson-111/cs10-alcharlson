#pragma once
using namespace std;
#include <cmath>
#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <istream> 
#include <string>
#include <vector> 
#include <cassert>
#include <algorithm>

// #include <cstdio> 


// Generate random number
int randomNumber();

// User Handling
void greeting(); 

// Guess Handling
void readNumber(int&);
void guessAssignment(int&, vector<int>&); 
int checkGuess(int, int&); 
void tests();
bool game();
void menu(); 