/*
Homework 5
Class: CS10
Author: Aubrey Charlson
Date: 4/5 

1. Function for random number generation
2. Function to read number from terminal
3. Function to check input number to random number
4. Function to test checkGuess 3x
5. Function for game
*/
#include <iostream> 
#include <cstdlib> //For rand() random number
#include <vector> 
#include <cassert> // For Tests
// #include <time.h>

int ranNum();
int readNum(int x);
int inNum();
int checkGuess(int x, int y);
void testGuess();
void pageBreak();
void game();



int main(){
    game();
    
}

int ranNum()
{
    
    srand (time(NULL)); //intialize random seed
    int rNum = rand() % 20 + 1;
    return rNum;

}

int readNum(int x)
{
    while (true)
        {srand (time(NULL));
        if (x < 1 || x > 20)
        {
            x = rand() % 20 + 1;
        }
        else
        {
            return x;
            break;
        }}
}

int inNum()
{
    int num;
    std::cout << "Please enter a number: ";
    std::cin >> num; 
    return num;
}
int checkGuess(int x, int y)
{
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 2;
    }
}

void testGuess()
{
    assert((checkGuess(1, 2)) == -1);
    assert((checkGuess(3, 2)) == 2);
    assert((checkGuess(1, 1)) == 0);
}

void pageBreak()
{
    std::cout << "\n\n_______________________________________\n\n";
}
void game()
{
    int passes = 0;
   
    testGuess();
    int rNum = ranNum();
    rNum = readNum(rNum); // this will return a new random number if != 1>x<20
    std::cout << rNum;



}