#include <stdio.h>

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char mark; // 'X' or 'O'

void drawBoard() {
    printf("\n %c | %c | %c \n---|---|---\n %c | %c | %c \n---|---|---\n %c | %c | %c \n", 
           board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}

int main() {
    int choice, player = 1;
    do {
        drawBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Invalid move!\n");
            player--;
        } else {
            board[row][col] = mark;
        }
        if (checkWin()) { drawBoard(); printf("Player %d wins!\n", player); return 0; }
        player++;
    } while (player <= 9);
    printf("It's a draw!\n");
    return 0;
}
