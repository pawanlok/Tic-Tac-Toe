#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

char current_marker;
int current_player;

void drawBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j < 2) cout << " | ";
        }
        if(i < 2) cout << "\n---|---|---\n";
    }
    cout << "\n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if(board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

bool checkWin() {
    // Rows, columns and diagonals
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == current_marker && board[i][1] == current_marker && board[i][2] == current_marker)
            return true;
        if(board[0][i] == current_marker && board[1][i] == current_marker && board[2][i] == current_marker)
            return true;
    }

    if(board[0][0] == current_marker && board[1][1] == current_marker && board[2][2] == current_marker)
        return true;
    if(board[0][2] == current_marker && board[1][1] == current_marker && board[2][0] == current_marker)
        return true;

    return false;
}

bool checkDraw() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void swapPlayerAndMarker() {
    if(current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    cout << "Tic-Tac-Toe Game!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> current_marker;

    while(current_marker != 'X' && current_marker != 'O') {
        cout << "Invalid marker. Choose X or O: ";
        cin >> current_marker;
    }

    current_player = (current_marker == 'X') ? 1 : 2;

    drawBoard();

    int slot;
    bool gameOver = false;

    while(!gameOver) {
        cout << "Player " << current_player << " (" << current_marker << "), enter your move (1-9): ";
        cin >> slot;

        if(slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        drawBoard();

        if(checkWin()) {
            cout << "Player " << current_player << " wins!\n";
            gameOver = true;
        } else if(checkDraw()) {
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            swapPlayerAndMarker();
        }
    }

    return 0;
}
