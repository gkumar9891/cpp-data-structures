// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/

#include <bits/stdc++.h>
using namespace std;

int t[201][201];
int solve(int e, int f) {
    if(f == 0 || f == 1)
        return f;
        
    if(e == 1)
        return f;
        
    if(e == 0)
        return 0;
        
    if(t[e][f] != -1)
        return t[e][f];
    
    int mn = INT_MAX;
    for(int k = 1; k <= f; k++) {
        int temp = 1 + max(solve(e-1, k-1), solve(e,f-k));
        mn = min(temp, mn);
    }
    return t[e][f] = mn;
}
int eggDrop(int e, int f) 
{
    memset(t, -1, sizeof(t));
    return solve(e,f);   
}

int main() {
    cout << eggDrop(2, 4);
}