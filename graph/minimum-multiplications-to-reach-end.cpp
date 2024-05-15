// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/
#include <bits/stdc++.h>
#include "../ctemplate.h"

int minimumMultiplications(vector<int>& arr, int start, int end) {
    queue<pair<int, int>> q;
    vector<int> dist(100000, INT_MAX);
    dist[start] = 0;
    q.push({0, start});
    while(!q.empty()) {
        auto f = q.front();
        int number = f.first;
        int mul = f.second;

        q.pop();
        
        if(mul%100000 == end) {
            return number;
        }
        
        for(auto el: arr) {
            int num = (mul*el) % 100000;
            if(dist[num] > number+1) {
                dist[num] = number+1;
                q.push({number+1, num});
            }
        }
    }
    
    return -1;
}

int main() {

    int n;
    read(n);

    vector<int> arr(n);
    read(arr);

    int start, end;
    read(start);
    read(end);

    write(minimumMultiplications(arr, start, end));

    return 0;
}