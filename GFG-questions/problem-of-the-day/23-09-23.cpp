#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
    int sum = accumulate(arr, arr+n, 0);
    
    int tSum = 0;
    
    for(int i = 0; i < n; i++) {
        if(tSum == (sum - arr[i] - tSum))
            return i+1;
            
        tSum += arr[i];
    }
    
    return -1;
}

int main() {
    int n = 5;
    int arr[] = {1,3,5,2,2};
    
    cout << solve(arr, n);
    
    return 0;
    
}