#include <stdlib.h>  
#include <stdio.h>   
#include <stdbool.h> 
#include <assert.h>  
#define CELL 4     
#define CELL_MAX (CELL * CELL - 1)

void init_board(char board[CELL][CELL])
{
    for (int i = 0; i < CELL; i++)
    {
        for (int j = 0; j < CELL; j++)
        {
            board[i][j] = '-';
        }
    }
}

void print_sep(int length)
{
    printf("\t ");
    for (int i = 0; i < length; i++)
        printf("................");
    printf("\n");
}

void print_board(char board[CELL][CELL])
{
    int cell = 0;

    print_sep(CELL);
    for (int row = 0; row < CELL; ++row)
    {
        for (int column = 0; column < CELL; ++column)
        {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(CELL);
    }
}
char get_winner(char board[CELL][CELL])
{
    char winner = '-';
    for (int row = 0; row < CELL && winner == '-'; row++)
    {
        bool auxrow = true;
        bool auxcolumn = true;
        for (int column = 0; column < (CELL - 1); column++)
        {
            if (board[row][column] != board[row][column + 1])
            {
                auxrow = false;
                winner = '-';
            }
            if (board[column][row] != board[column + 1][row])
            {
                auxcolumn = false;
                winner = '-';
            }
            if (auxrow == true)
            {
                winner = board[row][column];
            }
            if (auxcolumn == true)
            {
                winner = board[column][row];
            }
        }
    }
    if (winner != '-')
        return winner;
    bool auxdiag = true;
    bool auxcontradiag = true;
    for (int row = 0; row < (CELL - 1); row++)
    {
        if (board[row][row] != board[row + 1][row + 1])
        {
            auxdiag = false;
            winner = '-';
        }
        if (board[row][(CELL - 1) - row] != board[row + 1][(CELL - 1) - (row + 1)])
        {
            auxcontradiag = false;
            winner = '-';
        }
        if (auxdiag == true)
        {
            winner = board[row][row];
        }
        if (auxcontradiag == true)
        {
            winner = board[row][(CELL - 1) - row];
        }
    }

    return winner;
}

bool has_free_cell(char board[CELL][CELL])
{
    bool has_free_cell = false;
    for (int i = 0; i < CELL; i++)
    {
        for (int j = 0; j < CELL; j++)
        {
            if (board[i][j] == '-')
            {
                has_free_cell = true;
            }
        }
    }
    return has_free_cell;
}

int main(void)
{
    printf("Tictactoe : \n");
    char board[CELL][CELL];
    init_board(board);
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board))
    {
        print_board(board);
        printf("\n Turno %c : - Elija posicion (numero del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0)
        {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX)
        {
            int row = cell / CELL;
            int colum = cell % CELL;
            if (board[row][colum] == '-')
            {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            }
            else
            {
                printf("\nCelda ocupada!\n");
            }
        }
    }
    print_board(board);
    if (winner == '-')
    {
        printf("Empate!\n");
    }
    else
    {
        printf("Ganó %c\n", winner);
    }
    return 0;
}