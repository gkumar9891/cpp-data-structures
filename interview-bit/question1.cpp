#include <bits/stdc++.h>
using namespace std;

int traversal(vector < vector<int> > &grid, int startRow, int startCol, int endRow, int endCol, int step);

int solveProblem(vector<int> &A, vector<int> &B) {
     int res = 0, n = A.size();

    if(n<=1) return 0;

    for(int i = 1; i<n; i++){
        res += max(abs(A[i-1] - A[i]) , abs(B[i-1] - B[i]) );
     }

    return res;
}

int main() {
     vector <int> a = { 0, 1, 1 };
    vector <int> b = { 0, 1, 2 };

    cout << solveProblem(a, b);

    return 0;
}