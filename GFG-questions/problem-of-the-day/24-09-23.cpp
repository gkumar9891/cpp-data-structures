#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] = arr[index] + n;
    }
    
    vector<int> ans;
    
    for(int i = 0; i < n; i++) {
        if((arr[i]/n) > 1)
            ans.push_back(i);
    }
    
    if(ans.size() > 0)
        return ans;
        
    return {-1};
}

int main() {
    int n = 5;
    int arr[n] = {2,3,1,2,3};
    
    duplicates(arr, n);
    
    return 0;
}