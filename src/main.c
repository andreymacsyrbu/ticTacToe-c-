#include <stdio.h>

char grid[3][6] = {
    { '1', '|', '2', '|', '3', '\n'}, 
    { '4', '|', '5', '|', '6', '\n'},          
    { '7', '|', '8', '|', '9', '\n'} 
};

int winner = 0;
 // player 1 variables
int player1Input;
const char player1Symbol = 'X';

// player 2 variables
int player2Input;
const char player2Symbol = 'O';

// print the grid to the console
void printGrid(char array[3][6]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c", array[i][j]);
        }
    }
}

// to check the grid if one of the players won
void checkGrid(char symbol, int player) {
    if (grid[0][0] == symbol && grid[0][2] == symbol && grid[0][4] == symbol) {
        winner = player;
    }
    else if (grid[1][0] == symbol && grid[1][2] == symbol && grid[1][4] == symbol) {
        winner = player;
    }
    else if (grid[2][0] == symbol && grid[2][2] == symbol && grid[2][4] == symbol) {
        winner = player;
    }

    else if (grid[0][0] == symbol && grid[1][0] == symbol && grid[2][0] == symbol) {
        winner = player;
    }
    else if (grid[0][2] == symbol && grid[1][2] == symbol && grid[2][2] == symbol) {
        winner = player;
    }
    else if (grid[0][4] == symbol && grid[1][4] == symbol && grid[2][4] == symbol) {
        winner = player;
    }
    
    else if (grid[0][0] == symbol && grid[1][2] == symbol && grid[1][4] == symbol) {
        winner = player;
    }
    else if (grid[0][4] == symbol && grid[1][2] == symbol && grid[2][0] == symbol) {
        winner = player;
    }
}

// set the player turns on the grid
void setGrid(int playerInput, char symbol) {
    switch (playerInput) {
        case 1:
            grid[0][0] = symbol;
            break;
        case 2:
            grid[0][2] = symbol;
            break;
        case 3:
            grid[0][4] = symbol;
            break;
        case 4:
            grid[1][0] = symbol;
            break;
        case 5:
            grid[1][2] = symbol;
            break;
        case 6:
            grid[1][4] = symbol;
            break;
        case 7:
            grid[2][0] = symbol;
            break;
        case 8:
            grid[2][2] = symbol;
            break;
        case 9:
            grid[2][4] = symbol;
            break;
    }
}

int main() {
    printGrid(grid);

    // main game loop
    while (winner == 0) {
        printf("player1 : ");
        scanf("%d", &player1Input);
        setGrid(player1Input, player1Symbol);
        checkGrid(player1Symbol, 1);
        printGrid(grid);

        if (winner != 0) {
            break;
        }

        printf("player2 : ");
        scanf("%d", &player2Input);
        setGrid(player2Input, player2Symbol);
        checkGrid(player2Symbol, 2);
        printGrid(grid);
    }

    if (winner == 1) {
        printf("player1 won! \n");
    }
    else if (winner == 2) {
        printf("player2 won! \n");
    }

    return 0;
}
