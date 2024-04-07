#include <iostream>
#include <vector>

using namespace std;

const int N = 9; 


bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {

    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}


bool solveSudoku(vector<vector<int>>& grid) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (grid[row][col] == 0) { 
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            return true; 
                        }
                        grid[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    vector<vector<int>> grid = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku solution:\n";
        for (const auto& row : grid) {
            for (int num : row) {
                cout << num << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
