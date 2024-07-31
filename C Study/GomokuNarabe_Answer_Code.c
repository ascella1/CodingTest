#include <stdio.h>

#define SIZE 15

void initBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int placeStone(char board[SIZE][SIZE], int x, int y, char stone);
int checkWin(char board[SIZE][SIZE], int x, int y, char stone);

int main() {
    char board[SIZE][SIZE];
    int x, y;
    char currentPlayer = 'X';
    int moveCount = 0;

    initBoard(board);

    while (1) {
        printBoard(board);
        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &x, &y);

        if (x < 1 || x > SIZE || y < 1 || y > SIZE) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (placeStone(board, x-1, y-1, currentPlayer)) {
            moveCount++;
            if (checkWin(board, x-1, y-1, currentPlayer)) {
                printBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }
            if (moveCount == SIZE * SIZE) {
                printBoard(board);
                printf("The game is a draw!\n");
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            printf("The cell is already occupied. Try again.\n");
        }
    }

    return 0;
}

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("   ");// 열에 숫자를 나타낼때, 각 셀에 맞게끔 공백을 둔 것
    for (int i = 1; i <= SIZE; i++) {
        printf("%3d", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i + 1); // %2d -> 2자리보다 작으면 여백을 추가해서 2자리를 확보하는 것
        for (int j = 0; j < SIZE; j++) {
            printf("  %c", board[i][j]);
        }
        printf("\n");
    }
}

int placeStone(char board[SIZE][SIZE], int x, int y, char stone) {
    if (board[x][y] == '.') { // stone 이 아무것도 놓여있지 않은 . 상태일때 
        board[x][y] = stone;
        return 1;
    }
    return 0;
}

int checkDirection(char board[SIZE][SIZE], int x, int y, char stone, int dx, int dy) {
    int count = 0;
    for (int i = -4; i <= 4; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == stone) {
            count++;
            if (count == 5) return 1;
        } else {
            count = 0;
        }
    }
    return 0;
}

int checkWin(char board[SIZE][SIZE], int x, int y, char stone) {
    return checkDirection(board, x, y, stone, 1, 0) || // Horizontal
           checkDirection(board, x, y, stone, 0, 1) || // Vertical
           checkDirection(board, x, y, stone, 1, 1) || // Diagonal /
           checkDirection(board, x, y, stone, 1, -1);  // Diagonal 
}
