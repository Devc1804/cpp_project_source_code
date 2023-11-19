#include <iostream>
using namespace std;

const int A = 4;

// This function is to print the current board
void Board(int board[A][A]) {
    cout<<endl;
    for (int i= 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            cout <<board[i][j] <<"\t";
        }
        cout << endl;
    }
}

// This function is to check if the game is over
bool isGameOver(int board[A][A]) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// this function is to generate a random number (2 or 4)
int generateRandomNumber() {
    int randomNumber = rand() % 2;
    if (randomNumber == 0) {
        return 2;
    } else {
        return 4;
    }
}

// this function to add a new random number to the board
void addRandomNumber(int board[A][A]) {
    int row, col;
    do {
        row = rand() % A;
        col = rand() % A;
    } while (board[row][col] != 0);
    board[row][col] = generateRandomNumber();
}

// this function is to shift all non-0 values to the left
void shiftLeft(int board[A][A]) {
    for (int i = 0; i < A; i++) {
        int k = 0;
        for (int j = 0; j < A; j++) {
            if (board[i][j] != 0) {
                board[i][k++] = board[i][j];
            }
        }
        while (k < A) {
            board[i][k++] = 0;
        }
    }
}

// merging equal values after shifting left
void mergeLeft(int board[A][A]) {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }
    }
}

// shift downwards
void shiftDown(int board[A][A]) {
    for (int j = 0; j < A; j++) {
        int k = A - 1;
        for (int i = A - 1; i >= 0; i--) {
            if (board[i][j] != 0) {
                board[k--][j] = board[i][j];
            }
        }
        while (k >= 0) {
            board[k--][j] = 0;
        }
    }
}

// merging equal values after shifting down
void mergeDown(int board[A][A]) {
    for (int j = 0; j < A; j++) {
        for (int i = A - 1; i > 0; i--) {
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
    }
}

// shifting right
void shiftRight(int board[A][A]) {
    for (int i = 0; i < A; i++) {
        int k = A - 1;
        for (int j = A - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                board[i][k--] = board[i][j];
            }
        }
        while (k >= 0) {
            board[i][k--] = 0;
        }
    }
}

// merging equal values after shifting right
void mergeRight(int board[A][A]) {
    for (int i = 0; i < A; i++) {
        for (int j = A - 1; j > 0; j--) {
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
            }
        }
    }
}

// shift all non-0 values upwards
void shiftUp(int board[A][A]) {
    for (int j = 0; j < A; j++) {
        int k = 0;
        for (int i = 0; i < A; i++) {
            if (board[i][j] != 0) {
                board[k++][j] = board[i][j];
            }
        }
        while (k < A) {
            board[k++][j] = 0;
        }
    }
}

// merge equal values after shifting up
void mergeUp(int board[A][A]) {
    for (int j = 0; j < A; j++) {
        for (int i = 0; i < A - 1; i++) {
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
    }
}

int main() {
//    srand(time(0));

    int board[A][A] = {0};

    // Add two random numbers to the board
    addRandomNumber(board);
    addRandomNumber(board);

    char input;

    while (true) {
        Board(board);

        cout << "Enter your move (a: left, s: down, d: right, w: up, m: quit): ";
        cin >> input;

        if (input == 'm') {
            cout<<"Well Tried";
            break;
        }

        switch (input) {
            case 'a':
                shiftLeft(board);
                mergeLeft(board);
                shiftLeft(board);
                break;
            case 's':
                shiftDown(board);
                mergeDown(board);
                shiftDown(board);
                break;
            case 'd':
                shiftRight(board);
                mergeRight(board);
                shiftRight(board);
                break;
            case 'w':
                shiftUp(board);
                mergeUp(board);
                shiftUp(board);
                break;
            default:
                cout << "Invalid move! Try again." <<endl;
                continue;
        }

        if (!isGameOver(board)) {
            addRandomNumber(board);
        } else {
            cout << "Game over!" <<endl;
            break;
        }
    }

    return 0;
}
