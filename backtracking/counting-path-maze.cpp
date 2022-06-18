#include <iostream>
#define n 3
using namespace std;

int countPath( string direction ,int maze[n][n], int startRow, int startCol, int endRow, int endCol ) {
    if(startRow == endRow && startCol == endCol) {
        cout << direction << endl;
        return 1; 
    }

    if(startRow > endRow ) {
        return 0;
    }

    if(startCol > endCol) {
          return 0;
    }

    return countPath(direction + 'V', maze, startRow + 1, startCol, endRow, endCol) + countPath(direction + 'D', maze, startRow + 1, startCol + 1, endRow, endCol) + countPath( direction + 'H', maze, startRow, startCol + 1, endRow, endCol); 
}


int main() {
    int maze[n][n] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << countPath( "", maze, 0, 0, 2, 2);

    return 0;
}
