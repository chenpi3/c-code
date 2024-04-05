#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 15

enum Player {
    EMPTY = 0,
    PLAYER1 = 1,
    PLAYER2 = 2
};

enum GameState {
    ONGOING = 0,
    WIN_PLAYER1 = 1,
    WIN_PLAYER2 = 2,
    DRAW = 3
};

int board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(". ");
            }
            else if (board[i][j] == PLAYER1) {
                printf("X ");
            }
            else if (board[i][j] == PLAYER2) {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int checkWin(int player) {
    // 检查横向是否连成五子
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 4; j++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board[i][j + k] == player) {
                    count++;
                }
            }
            if (count == 5) {
                return 1;
            }
        }
    }

    // 检查纵向是否连成五子
    for (int i = 0; i < SIZE - 4; i++) {
        for (int j = 0; j < SIZE; j++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board[i + k][j] == player) {
                    count++;
                }
            }
            if (count == 5) {
                return 1;
            }
        }
    }

    // 检查斜向（左上至右下）是否连成五子
    for (int i = 0; i < SIZE - 4; i++) {
        for (int j = 0; j < SIZE - 4; j++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board[i + k][j + k] == player) {
                    count++;
                }
            }
            if (count == 5) {
                return 1;
            }
        }
    }

    // 检查斜向（右上至左下）是否连成五子
    for (int i = 0; i < SIZE - 4; i++) {
        for (int j = 4; j < SIZE; j++) {
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (board[i + k][j - k] == player) {
                    count++;
                }
            }
            if (count == 5) {
                return 1;
            }
        }
    }

    return 0;
}

int isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    initializeBoard();
    int currentPlayer = PLAYER1;
    int gameState = ONGOING;

    while (gameState == ONGOING) {
        printBoard();

        int row, col;
        printf("Player %d's turn. Enter row and column (0-%d): ", currentPlayer, SIZE - 1);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            gameState = (currentPlayer == PLAYER1) ? WIN_PLAYER1 : WIN_PLAYER2;
        }
        else if (isBoardFull()) {
            gameState = DRAW;
        }
        else {
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
        }
    }

    printBoard();

    if (gameState == WIN_PLAYER1) {
        printf("Player 1 wins!\n");
    }
    else if (gameState == WIN_PLAYER2) {
        printf("Player 2 wins!\n");
    }
    else if (gameState == DRAW) {
        printf("It's a draw!\n");
    }

    return 0;
}
