#include "board.h"

void fill(Node ***& grid)
{
    grid = new Node**[3]; // init new array for rows

    for(int i = 0; i < 3; i++)
    {
        grid[i] = new Node*[3]; // init col
        for(int j = 0; j < 3; j++)
        {
            grid[i][j] = new Node; // enter info
            grid[i][j]->fill = false;
            grid[i][j]->team = -1; 
        }
    }
}


void print(Node ***& grid)
{
    string ecel = "   |"; // print vars
    string xcel = " x |";
    string ocel = " o |";
    int row = 1; 

    // table build
    cout << right << setw(15) << string(13, '-') << endl; 
    for (int i = 0; i < 3; i++)
    {
        cout << row << " |";
        row++;
        for(int j = 0; j < 3; j++)
        {
            if (grid[i][j]->fill == false) //empty = empty cell
            {cout << ecel;}
            else if (grid[i][j]->fill == true && grid[i][j]->team == 1)
            {cout << xcel;} // team 1 = xcel
            else {cout << ocel;}
            // other = ocell
        }
        cout << endl 
        << right << setw(15) << string(13, '-') << endl;
    }
    cout << right 
    << setw(5) << "1" // print col labels
    << setw(4) << "2"
    << setw(4) << "3" 
    << endl;

}

void clean(Node ***& grid)
{ 
    for (int i = 0; i < 3; i++) // loop through and delete heap scaling down ptr levels
    {
        for (int j = 0; j < 3; j++)
        {
            delete grid[i][j]; 
        }
        delete[] grid[i];
    }
    delete[] grid;
}