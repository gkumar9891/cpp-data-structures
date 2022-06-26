#include <iostream>
#define n 3
using namespace std;

void countingPath(string direction, int maze[n][n], int startRow, int startCol, int endRow, int endCol, int step) {
    if(startRow == endRow && startCol == endCol) {
        maze[startRow][startCol] = step;

        cout << direction << endl;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << maze[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return;
    }

    if(maze[startRow][startCol]) {
        return;
    }

    if(startRow > endRow || startCol > endCol) {
        return;
    }

    maze[startRow][startCol] = step;

    if(startRow <= endRow){
        countingPath(direction + 'D', maze, startRow + 1, startCol, endRow, endCol, step + 1);
    }

    if(startCol <= endCol) {
        countingPath(direction + 'R', maze, startRow, startCol + 1, endRow, endCol, step + 1);
    }

    if(startRow > 0) {
        countingPath(direction + 'U', maze, startRow - 1, startCol, endRow, endCol, step + 1);
    }

    if(startCol > 0 ) {
        countingPath(direction + 'L', maze, startRow, startCol - 1, endRow, endCol, step + 1);
    }

    maze[startRow][startCol] = 0;
}

int main() {

    int maze[n][n] = {{0,0,0}, {0,0,0}, {0,0,0}};
    countingPath("", maze, 0, 0, 2, 2, 1);

    return 0;
}