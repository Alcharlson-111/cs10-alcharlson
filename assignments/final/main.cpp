/*
Author: Aubrey Charlson
Date: 5/14
Class: CS111

Program: A repeatable game of tictactoe where the bot tries to prevent player win.


*/

#include "lib/board.h"
#include "lib/game.h"
#include "lib/bot.h"
#include <fstream>


int main()
{
    Node*** grid;
    int wins =0;
    int games =0;
    char ch;
    do
    {
        int t = team(); // init team
        fill(grid); // create grid
        int result = game(grid, t); // save game result
        clean(grid); // clean heap
        games++; // increase game count
        if (result == 1) wins++;
        cout << "Play again? [y/n]:   ";  // determine replay
        cin >> ch;
        if (ch == 'y' || ch == 'Y') continue;
        else {
            ofstream out("out.txt");// output to file
            out << string(25, '=')
                << endl
                << "Wins: " << wins 
                << "    Win Ratio: " << wins 
                << "/" << games;
                break;
        }
    } while (true);
    
    
    
    return 0;
}

