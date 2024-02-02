#include "q6_game.h"

// need to initialize board, print board, is valid move, make move, check win
void initializeBoard(char board[3][3]){// input is a 3x3 array with characters
    int count = 1;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = count + '0'; // convert int to char
            count ++;
        }
    }
}

void printBoard(char board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%c", board[i][j]);
        }
        printf("\n"); // print new line after each row
    }
}

int isValidMove(char board[3][3], int move){
    for (int i=0; i<3;i++){
        for (int j=0; j<3; j++){
            if(board[i][j] == move + '0'){ // if the move can be found on board it means move is valid
                return 1;
            } 
            
        }
    }
    return 0; // the move was not made
}

void makeMove(char board[3][3], int move, char symbol){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j]== move+'0'){
                board[i][j] = symbol;
                return; // stop early
            }
        }
    }
}

int checkWin(char board[3][3]){
    // check rows
    for (int i=0; i<3; i++){
        if (board[i][0] == board [i][1] && board[i][1] == board[i][2]){
            return 1;
        }
    }
    // check columns
    for (int j=0; j<3; j++){
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return 1;
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]){
        return 1;
    }
    return 0;
}

int checkTie(char board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j]!='X' && board[i][j]!='O'){
                return 0; // some positions are still available
            }
        }
    }
    return 1; // if all positions are filled by 'X' or 'O' it is a tie
}