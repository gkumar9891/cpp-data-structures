// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
#include <bits/stdc++.h>
#include "../ctemplate.h"

int longestSubarrayWithSumK(vector<int> a, long long k) {
    int i = 0;
    int j = 0;

    int ans = 0;
    long long sum = 0;
    while(j < a.size()) {
        sum += a[j];

        while(sum > k) {
            sum = sum - a[i];
            i++;
        }

        if(sum == k) {
            ans = max(ans, j-i+1);
        }
        j++;
    }

    return ans;
}

int main() {

    int n, k;
    read(n);
    read(k);

    vector<int> a(n);
    read(a);

    write(longestSubarrayWithSumK(a, k));
    return 0;
}