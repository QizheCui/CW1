#include "q6_game.h"

int main(){
    char board[3][3];
    int move;
    char currentPlayer = 'X';

    initializeBoard(board);
    while (1){
        printBoard(board);
        printf("Player %c, enter your move: ", currentPlayer);
        int scanResult = scanf("%d", &move); // return the number of successfully scanned items, 1 if it is integer and 0 otherwise
        
        /*when encountered non-integer input, the scanf fail and leave the invalid input in the input buffer
        and we need to clean all chracters up to the next newline character,i.e. clean the input buffer*/
        while(scanResult == 0 || !isValidMove(board,move)){
            while (getchar() != '\n'){
            // clear input buffer
            }
            printf("Invalid move. Please try again: ");
            scanResult = scanf("%d", &move); // rescan until it is a valid integer
        }
        makeMove(board, move, currentPlayer);

        if (checkWin(board)){
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
        if (checkTie(board)){
            printBoard(board);
            printf("It is a tie.\n");
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}