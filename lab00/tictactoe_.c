#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define BOARD_SIZE 7
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

/*
Cambie el codigo de manera que se pueda utilizar para tableros de 
3x3     4xx4     5x5    n x n 
Solo es necesario cambiar la variable BOARD_SIZE al principio del archivo
*/


void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;

    print_sep(BOARD_SIZE);
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(BOARD_SIZE);
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        char first = board[row][0];
        bool same = true;
        for (int column = 1; column < BOARD_SIZE; column++) {
            if (board[row][column] != first) {
                same = false;
                break;
            }
        }
        if (same && first != '-') {
            return first;
        }
    }

    // Check columns
    for (int column = 0; column < BOARD_SIZE; column++) {
        char first = board[0][column];
        bool same = true;
        for (int row = 1; row < BOARD_SIZE; row++) {
            if (board[row][column] != first) {
                same = false;
                break;
            }
        }
        if (same && first != '-') {
            return first;
        }
    }

    // Check diagonals
    char first = board[0][0];
    bool same = true;
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (board[i][i] != first) {
            same = false;
            break;
        }
    }
    if (same && first != '-') {
        return first;
    }

    first = board[0][BOARD_SIZE-1];
    same = true;
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE-i-1] != first) {
            same = false;
            break;
        }
    }
    if (same && first != '-') {
        return first;
    }
    // No winner
    return '-';
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    //Checks in every cell if there is one free
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int column = 0; column < BOARD_SIZE; column++)
        {
            if (board[row][column] == '-')
            {
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");
    char board [BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
    
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
