#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 9;
const int EMPTY = 0;

// Function to print the Sudoku grid
void printGrid(vector<vector<int>> &grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// Function to check if a number can be placed in a particular position
bool isSafe(vector<vector<int>> &grid, int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check column
    for (int y = 0; y < N; y++)
        if (grid[y][col] == num)
            return false;

    // Check grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku puzzle
bool solveSudoku(vector<vector<int>> &grid) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == EMPTY) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }
    if (!isEmpty)
        return true;

    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(nums.begin(), nums.end());
    for (int num : nums) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = EMPTY;
        }
    }
    return false;
}

// This function is to generate a Sudoku puzzle
void generateSudoku(vector<vector<int>> &grid) {
    srand(time(nullptr));

    // Fill the grid with zeros
    for (int i = 0; i < N; i++) {
        vector<int> row(N, 0);
        grid.push_back(row);
    }

    // This solves the Sudoku puzzle
    solveSudoku(grid);

    int numToRemove = 40;
    while (numToRemove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            numToRemove--;
        }
    }
}

int main() {
    vector<vector<int>> grid;
    generateSudoku(grid);
    cout << "Generated Sudoku Puzzle: " << endl;
    printGrid(grid);
    cout<<"If you want to see the solution type 'yes'"<<endl;
    string a;
    cin>>a;
    if(a=="yes"){
        cout << "\nSolving Sudoku Puzzle..." ;
        if (solveSudoku(grid)) {
            cout << "\nSolved Sudoku Puzzle: " << endl;
            printGrid(grid);
        } else {
            cout << "No solution exists." << endl;
        }

    }
    return 0;
}
 