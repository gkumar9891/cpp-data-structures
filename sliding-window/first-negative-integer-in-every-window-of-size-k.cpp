// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

#define lli long long int

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int k) {
                                                
    vector<long long> ans;
    list<long long> l;
    
    lli i = 0;
    lli j = 0;
    
    while(j < N) {
        if(A[j] < 0) {
            l.push_back(A[j]);
        }
        
        if(j-i+1 == k) {
            if(l.size() == 0) {
                ans.push_back(0);
            } else if (l.front() == A[i]) {
                ans.push_back(l.front());
                l.pop_front();
            } else {
                ans.push_back(l.front());
            }
            
            j++;
            i++;
        }
        
        if(j - i + 1 < k) {
            j++;
        }
    }
    
    return ans;
                                                
}

int main() {
    lli n, k;
    read(n);
    lli arr[n];
    for(lli i = 0; i < n; i++) {
        cin >> arr[i];
    }

    read(k);

    write(printFirstNegativeInteger(arr, n, k));


    return 0;
}