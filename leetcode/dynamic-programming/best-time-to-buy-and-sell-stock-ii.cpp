// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solutions/2601230/recursion-to-linear-solution/
#include <bits/stdc++.h>
#include "../../ctemplate.h"

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int buy = prices[0];
    int sell = prices[0];
    int profit = 0;

    for(int i=1; i<n; ++i) {
        if(prices[i] < sell) {
            if(sell > buy) 
                profit += sell - buy;
            buy = prices[i];
        }
        sell = prices[i];
    }
    if(sell > buy) 
        profit += sell - buy;
    
    return profit;
}

int main() {

    int n;
    read(n);
    vector<int> arr(n);
    read(arr);

    write(maxProfit(arr));

    return 0;
}