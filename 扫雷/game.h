#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define QuntityMine 10
void InitBoard(char board[ROWS][COLS], int r, int c, char set);
void DisplayBoard(char board[ROWS][COLS], int r, int c);
void FindMine(char Mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);
// 颜色宏
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define MAGENTA "\033[35m"
#define GRAY    "\033[90m"