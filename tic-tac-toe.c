#include <stdio.h>
#include <stdbool.h>

#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '

char board[3][3];

void initialize_board();
void print_board();
bool is_moves_left();
int evaluate();
int minimax(int depth, bool is_max);
void ai_move();
void player_move();
void to_lowercase(char str[]);

int main() {
    initialize_board();
    printf("Welcome to Tic-Tac-Toe!\n");
    print_board();

    while (true) {
        player_move();
        print_board();
        if (evaluate() == -10) {
            printf("Player wins!\n");
            break;
        }
        if (!is_moves_left()) {
            printf("It's a draw!\n");
            break;
        }

        ai_move();
        print_board();
        if (evaluate() == 10) {
            printf("AI wins!\n");
            break;
        }
        if (!is_moves_left()) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}

void initialize_board() {
	int i,j;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
	int i,j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

bool is_moves_left() {
	int i,j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                return true;
            }
        }
    }
    return false;
}

int evaluate() {
	  int row,col;
    
    for (row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == AI)
                return +10;
            else if (board[row][0] == PLAYER)
                return -10;
        }
    }

   
    for (col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == AI)
                return +10;
            else if (board[0][col] == PLAYER)
                return -10;
        }
    }

   
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == AI)
            return +10;
        else if (board[0][0] == PLAYER)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == AI)
            return +10;
        else if (board[0][2] == PLAYER)
            return -10;
    }

    return 0;
}

int minimax(int depth, bool is_max) {
    int score = evaluate();

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (!is_moves_left())
        return 0;

    if (is_max) {
        int best = -1000 ,i,j;
        
        for ( i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = AI;
                    best = (best > minimax(depth + 1, !is_max)) ? best : minimax(depth + 1, !is_max);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } else {
        int best = 1000,i,j;

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER;
                    best = (best < minimax(depth + 1, !is_max)) ? best : minimax(depth + 1, !is_max);
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

void ai_move() {
    int best_val = -1000;
    int best_move_row = -1;
    int best_move_col = -1;
    int i,j;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                int move_val = minimax(0, false);
                board[i][j] = EMPTY;

                if (move_val > best_val) {
                    best_move_row = i;
                    best_move_col = j;
                    best_val = move_val;
                }
            }
        }
    }

    board[best_move_row][best_move_col] = AI;
    printf("AI has made a move at (%d, %d)\n", best_move_row + 1, best_move_col + 1);
}

void player_move() {
    int row, col;

    while (true) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        row--; col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

