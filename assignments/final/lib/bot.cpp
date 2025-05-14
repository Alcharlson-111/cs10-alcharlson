#include "bot.h"
void bot(Node ***&grid, int botTeam)
{
    int player = (botTeam == 1) ? 2 : 1;

    // all win/block lines
    int lines[8][3][2] = {
        {{0,0},{0,1},{0,2}}, {{1,0},{1,1},{1,2}}, {{2,0},{2,1},{2,2}}, // rows
        {{0,0},{1,0},{2,0}}, {{0,1},{1,1},{2,1}}, {{0,2},{1,2},{2,2}}, // cols
        {{0,0},{1,1},{2,2}}, {{0,2},{1,1},{2,0}}                      // diagonals
    };

    // try to block player win
    for (auto &line : lines)
    {
        int count = 0, emptyX = -1, emptyY = -1;
        for (int i = 0; i < 3; ++i)
        {
            int x = line[i][0], y = line[i][1];
            if (grid[x][y]->fill && grid[x][y]->team == player)
                count++;
            else if (!grid[x][y]->fill)
                emptyX = x, emptyY = y;
        }

        if (count == 2 && emptyX != -1)
        {
            grid[emptyX][emptyY]->fill = true;
            grid[emptyX][emptyY]->team = botTeam;
            return;
        }
    }

    // fallback: first empty cell
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!grid[i][j]->fill)
            {
                grid[i][j]->fill = true;
                grid[i][j]->team = botTeam;
                return;
            }
}