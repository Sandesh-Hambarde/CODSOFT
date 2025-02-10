#include <iostream>
using namespace std;

char board[3][3];

void displayBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin(char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == '-') return false;
    return true;
}

void playTicTacToe() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = '-';

    char currentPlayer = 'X';

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (1-3): ";
        int row, col;
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != '-') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "The game is a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Play again? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y')
        playTicTacToe();
    else
        cout << "Thanks for playing!\n";
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playTicTacToe();
    return 0;
}

