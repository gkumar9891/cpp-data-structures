#include <iostream>
using namespace std;
#define n 4

void display(bool board[n][n], int row, int col) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(bool board[n][n], int row, int col) {
    for(int i = row; i >= 0; i--) {
        if(board[i][col]) {
            return false;
        }
    }

    for(int i = row - 1, j = col + 1; i >= 0 && j < n  ; i--, j++) {
        if(board[i][j]) {
            return false;
        }
    }

    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) {
            return false;
        }
    }

    return true;
}

bool nQueen(bool board[n][n], int row, int col){
        if(row == n) {
            display(board, n, n);
            cout << endl;
        }
        
        for(int i = 0; i < n; i++) {
            if(isSafe(board, row, i)){
                board[row][i] = 1;
                nQueen(board, row + 1, i);
                board[row][i] = 0;
        }}
}

int main() {

    bool board[n][n] = {{0, 0 , 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    nQueen(board, 0, 0);
 //   display(board, n, n);
 
    return 0;
}