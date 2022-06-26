#include <iostream>
#include <cmath>
#define n 9
using namespace std;

bool isSafe(int board[n][n], int row, int col, int num) {
    //for check in row
    for(int i = 0; i < n; i++) {
        if(board[row][i] == num) {
            return false;
        }
    }

    //for check in col
    for(int i = 0; i < n; i++) {
        if(board[i][col] == num) {
            return false;
        }
    }

     //for check in its 3 * 3 block
    int sqroot = (int)(sqrt(n));

    int start = row - row % 3;
    int end = col - col % 3;

    for(int i = start; i < start + sqroot; i++) {
        for(int j = end; j < end + sqroot; j++) {
            if(board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void display(int board[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << board[i][j] << " ";
         }
        cout << endl;
    }
}

bool sudokuSolver(int board[n][n]) {
    int row = -1;
    int col = -1;

    bool isLeftEmpty = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) {
                row = i;
                col = j;
                isLeftEmpty = false;
                break;
            }
        }

        if(isLeftEmpty == false) {
            break;
        }
    }

    if(isLeftEmpty == true) {
        return true;
    }

    for(int num = 1; num <= n; num++) {
        if(isSafe(board, row, col, num)) {
            board[row][col] = num;
            if(sudokuSolver(board)) {
                return true;
            } else {
            //backtracking
            board[row][col] = 0;
         }
        }
    }


    return false;
}

int main() {
    int board[n][n] = { 
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(sudokuSolver(board)) {
        display(board);
    } else {
        cout << "cannot solve sudoku";
    };



    return 0;
}


