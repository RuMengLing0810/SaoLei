#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define QuntityMine 10
void InitBoard(char board[ROWS][COLS], int r, int c, char set);
void DisplayBoard(char board[ROWS][COLS], int r, int c);
void FindMine(char Mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);