#include "game.h"
// #include "board.h"
using namespace std;
int team()
{
    cout << "Please select a team:"
         << endl << "1: x"
         << endl << "2: o"
         << endl;
    int team = -1;
    cin >> team; // verify input
    while (team > 2 || team < 1)
    {
        cout << "Invalid entry. Please try again: " << endl;
        cin >> team;
    }
    return team;
}



void entry(Node ***& grid, int t)
{
    int x = -1;
    int y = -1;
    cout << "Please enter your co-ordanates seperated by a space: \"x y\""
         << endl << "Then hit return." << endl;
    while ((3 < x || x < 0 || 3 < y || y < 0))
    {
        cin >> x >> y; //verify input
        if ((3 < x || x < 0 || 3 < y || y < 0))
        {
            cout << endl
                 << "A value entered is outside of scope. Please try again: "
                 << endl;
        }
    }

    bool filled = false; // i was going to check if filled but 
    // this just handles the loop :/
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i < y -1) continue; //easy continue if wrong row/col
            if (j < x -1) continue;

            grid[i][j]->fill = true;
            grid[i][j]->team = t;
            filled = true;
            break;
        }
        if (filled) break;
    }
}



int checkWin(Node*** grid)
{
    // all 8 win conditions: 3 rows, 3 columns, 2 diagonals
    int lines[8][3][2] = {
        {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}}, {{2,0},{2,1},{2,2}}, // rows
        {{0,0},{1,0},{2,0}}, {{0,1},{1,1},{2,1}}, {{0,2},{1,2},{2,2}}, // columns
        {{0,0},{1,1},{2,2}}, {{0,2},{1,1},{2,0}}                      // diagonals
    };

    for (auto &line : lines)
    {
        int i1 = line[0][0], j1 = line[0][1];
        int i2 = line[1][0], j2 = line[1][1];
        int i3 = line[2][0], j3 = line[2][1];

        if (grid[i1][j1]->fill &&
            grid[i1][j1]->team == grid[i2][j2]->team &&
            grid[i2][j2]->team == grid[i3][j3]->team)
        {
            return grid[i1][j1]->team; // 1 or 2
        }
    }

    return 0; // no winner
}

int game(Node***&grid, int t)
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    print(grid);
    int t2 = 0;
    if (t == 2) t2 =1;
    else t2 = 2; 
    int turn = 0;
    while (true)
    {
        turn++;
        if (t == 1
        ){
            // player x move
            entry(grid, t);
            print(grid);
            

            // bot(grid, t2);
            // print(grid);
        }
        else
        {
            bot(grid, t2);
            print(grid);
            // entry(grid, t);
            // print(grid);
        }
        
        int result = checkWin(grid);
        if (result == 1)
        {
            cout << "Player X wins!" << endl;
            return 1;
        }

        // Check for draw before bot moves
        bool allFilled = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!grid[i][j]->fill)
                    allFilled = false;

        if (allFilled)
        {
            cout << "This game is a draw!" << endl;
            return 0;
        }

        if (t == 1
        ){
            // player o move
            // entry(grid, t);
            // print(grid);
            

            bot(grid, t2);
            print(grid);
        }
        else
        {
            // bot(grid, t2);
            // print(grid);
            entry(grid, t);
            print(grid);
        }
        
        result = checkWin(grid);
        if (result == 2)
        {
            cout << "Player O wins!" << endl;
            return 1;
        }

        // check again for draw
        allFilled = true;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!grid[i][j]->fill)
                    allFilled = false;

        if (allFilled)
        {
            cout << "This game is a draw!" << endl;
            return -1;
        }
    }
}
