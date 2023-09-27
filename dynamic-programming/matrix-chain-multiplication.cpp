#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int MCM(int arr[], int n, int i, int j) {
    if(i >= j) {
        return 0;
    }

    if(t[i][j] != -1) {
        return t[i][j];
    }

    int mn = INT_MAX;

    for(int k = i; k < j; k++) {
        int tempAns = MCM(arr, n, i, k) + MCM(arr, n, k+1, j) + arr[i-1] * arr[k] * arr[j];
    
        mn = min(mn, tempAns);
    }

    return t[i][j] = mn;
}   

int main() {

    int n = 5;
    int arr[] = {40, 20, 30, 10, 30};

    memset(t, -1, sizeof(t));

    cout << MCM(arr, n, 1, n-1);

    return 0;
} 
