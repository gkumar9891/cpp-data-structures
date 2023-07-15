#include "../ctemplate.h"
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int w, int n) {
    if(w == 0 || n == 0) {
        return 0;
    }

    if(wt[n-1] <= w) {
        return max(val[n-1] + knapsack(wt, val, w - wt[n-1], n - 1), knapsack(wt, val, w, n - 1));
    } else if(wt[n-1] > w) {
        return knapsack(wt, val, w, n - 1);
    }
}

int main() {
    int n;
    read(n);

    vector<int> wt(n);
    vector<int> val(n);
    read(wt);
    read(val);

    int w;
    read(w);

    cout << knapsack(wt, val, w, n) << endl;

    return 0;
}

