#include <bits/stdc++.h>
#include "../../debug.h"
using namespace std;

void booleanMatrix(vector<vector<int> > &matrix) {
    queue<pair<int,int>> q;
    vector<bool> row(matrix.size(), false);
    vector<bool> col(matrix[0].size(), false);

    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j])
                q.push({i, j});
        }
    }

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(row[r] == false) {
            for(int i = c; i >= 0; i--)
                matrix[r][i] = 1;
                
            for(int i = c; i < matrix[r].size(); i++)
                matrix[r][i] = 1;
        
            row[r] = true;
        }
            
            
        if(col[c] == false) {    
            for(int i = r; i >= 0; i--)
                matrix[i][c] = 1;
                
            for(int i = r; i < matrix.size(); i++)
                matrix[i][c] = 1;
            
            col[c] = true;
        }
    }
}

int main() {

    vector<vector<int>> grid = {{1, 0, 0},
                                {1, 0, 0},
                                {1, 0, 0},
                                {0, 0, 0}};

    booleanMatrix(grid);                   

    _print(grid);                            

    return 0;
}