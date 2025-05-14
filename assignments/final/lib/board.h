#ifndef board_h
#define board_h
#include "board.h"
#include <array> 
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
struct Node
{
    bool fill;
    int team;
};
void fill(Node ***&);
void print(Node ***&);
void clean(Node ***&);
#endif