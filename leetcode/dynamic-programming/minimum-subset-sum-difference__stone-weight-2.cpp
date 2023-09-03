#include <bits/stdc++.h>
#include <climits>
using namespace std;

int dp[40][50000];

int allSubsets(vector<int> &arr, int index, int sumSubset1, int sumSubset2) {
    if(index == arr.size()) {
        return abs(sumSubset1 - sumSubset2);
    }

    if(dp[index][abs(sumSubset1 - sumSubset2)] != -1) {
        return dp[index][abs(sumSubset1 - sumSubset2)];
    }

    return dp[index][abs(sumSubset1 - sumSubset2)] = 
    min(
    allSubsets(arr, index + 1, sumSubset1 + arr[index], sumSubset2),
    allSubsets(arr, index + 1, sumSubset1, sumSubset2 + arr[index]) 
    );
}

int minDifference(vector<int> &arr) {
    return allSubsets(arr, 0, 0, 0);
}

int main() {
    memset(dp,-1,sizeof(dp));
    vector<int> arr = {1,2};
    cout << minDifference(arr);

    return 0;
}