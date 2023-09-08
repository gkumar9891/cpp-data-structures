#include <bits/stdc++.h>
using namespace std;
int memo[30][1000];

int countSubset(vector<int> &arr, int &target, int index, int sum) {
    if(sum == target)
        return 1;
    if(index == arr.size())
        return 0;
    if(sum > target)
        return 0;

    if(memo[index][sum] != -1)
        return memo[index][sum];

    return memo[index][sum] = countSubset(arr, target, index + 1, sum + arr[index]) + countSubset(arr, target, index + 1, sum);

}

int countSubsetOfDifference(vector<int> &arr, int &diff) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int target = (diff + sum) / 2; //because of some formula to get the target  

    //code for count sum of subset with given target
    return countSubset(arr, target, 0, 0);
}

int main() {
    memset(memo, -1, sizeof(memo));

    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout << countSubsetOfDifference(arr, diff);

    return 0;
}