// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

long maximumSumSubarray(int k, vector<int> &Arr , int n){
    int i = 0;
    int j = 0;
    long sum = 0;
    long ans = 0;
    
    while(j < Arr.size()) {
        sum += Arr[j];
        
        if(j-i+1 == k) {
            ans = max(ans, sum);
            sum = sum - Arr[i++];
            j++;
        } else if(j-i+1 < k) {
            j++;
        }
    }
    
    return ans;
}

int main() {

    int k, n;
    read(n);
    read(k);
    vector<int> arr(n);
    read(arr);

    write(maximumSumSubarray(k, arr, n));


    return 0;
}