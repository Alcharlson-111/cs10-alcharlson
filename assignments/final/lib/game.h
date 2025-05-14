#ifndef game_h
#define game_h
#include "board.h"
#include "bot.h"
int team ();
void entry(Node ***&, int t);
int game(Node ***&grid, int t);
int checkWin(Node*** grid, int t);
#endif