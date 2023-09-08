#include <bits/stdc++.h>
using namespace std;

bool isSubsetAvailable(vector<int> &arr, int index, int target, int sum) {
    if(index > arr.size() - 1)
        return false;

    if(target < sum)
        return false;

    if(target == sum)
        return true;
    
    if(isSubsetAvailable(arr, index + 1, target, sum + arr[index])) {
        return true;
    } if( isSubsetAvailable(arr, index + 1, target, sum) ) {
        return true;
    }

    return false;
}

bool isPartitionPossible(vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum % 2 != 0)
        return false;

    return isSubsetAvailable(arr, 0,sum / 2, 0);
}

int main() {
    vector<int> arr = {1, 5, 11, 5};
    cout << isPartitionPossible(arr);
    return 0;
}