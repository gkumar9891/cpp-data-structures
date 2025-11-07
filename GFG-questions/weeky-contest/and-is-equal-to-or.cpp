#include <bits/stdc++.h>
#include "../../ctemplate.h"

int findTotalCount(int count) {
    if(count == 1) {
        return 1;
    }
    return count + findTotalCount(count-1); 
}

long long ANDequalOR(int n, vector<int> arr) {
    long long count = 0;
    int i = 0;
    int j = 0;

    while(j < n) {
        if(arr[i] != arr[j]) {
            count += findTotalCount(j-i);
            i = j;
            continue;
        }
        
        j++;
    }

    count += findTotalCount(j-i);
    
    return count;
}

int main() {
    int n;
    read(n);
    vector<int> arr(n);
    read(arr);

    write(ANDequalOR(n, arr));

    return 0;
}