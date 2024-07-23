#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentTurn = 'X';
bool isGameOver = false;

void printBoard() {
    system("clear");
    cout << "Tic-Tac-Toe Game" << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin() {
    vector<vector<int>> winPositions = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (const auto& pos : winPositions) {
        if (board[pos[0] / 3][pos[0] % 3] == board[pos[1] / 3][pos[1] % 3] &&
            board[pos[1] / 3][pos[1] % 3] == board[pos[2] / 3][pos[2] % 3]) {
            return true;
        }
    }
    return false;
}

bool isBoardFull() {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell != 'X' && cell != 'O') {
                return false;
            }
        }
    }
    return true;
}

void resetBoard() {
    char num = '1';
    for (auto& row : board) {
        for (auto& cell : row) {
            cell = num++;
        }
    }
    currentTurn = 'X';
    isGameOver = false;
}

void playGame() {
    while (!isGameOver) {
        printBoard();
        int choice;
        cout << "Turn of " << currentTurn << ": ";
        cin >> choice;
        
        if (choice < 1 || choice > 9) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied. Try again." << endl;
            continue;
        }

        board[row][col] = currentTurn;
        isGameOver = checkWin();

        if (isGameOver) {
            printBoard();
            cout << "Player " << currentTurn << " wins!" << endl;
            break;
        }

        if (isBoardFull()) {
            printBoard();
            cout << "The game is a draw!" << endl;
            break;
        }

        currentTurn = (currentTurn == 'X') ? 'O' : 'X';
    }
}

int main() {
    char playAgain;
    do {
        resetBoard();
        playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}
