#include <bits/stdc++.h>
using namespace std;

int mod = 100000;
int minSubset(vector<int>& arr, int index, int sum, int target) {
    if(index == arr.size())
        return INT_MAX;
    
    if(sum == target)
        return 0;
    
    if(sum > target) {
        if(sum % mod == target)
            return 0;

        return INT_MAX;
    }
    
    int take = minSubset(arr, index, sum * arr[index], target);
    if(take != INT_MAX)
        take = 1 + take;

    int notTake = minSubset(arr, index+1, sum, target);
    
    return min(take, notTake);
}

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    int val = minSubset(arr, 0, start%mod, end) % mod;
    if(val == INT_MAX)
        return -1;
    
    return val;  
}

int main() {

    vector<int> arr = {3, 4, 65};

    cout << minimumMultiplications(arr, 7, 66175);    
    return 0;
}
