#include <stdio.h>
void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
int isValidMove(char board[3][3], int move);
void makeMove(char board[3][3], int move, char symbol);
int checkWin(char board[3][3]);
int checkTie(char board[3][3]);