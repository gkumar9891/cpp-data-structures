#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long sum=0,maxi=INT_MIN,j=0,cur=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(i-j+1==k){
            maxi=max(sum,maxi);
            cur=max(cur,sum);
        }
        if(i-j+1>k){
            sum-=a[j];
            cur=max(cur+a[i],sum);
            maxi=max(maxi,cur);
            j++;
        }
    }
    return maxi;
}

int main() {

    long long int a[] = {1, 1, 1, 1};
    long long int n = 4;
    cout << maxSumWithK(a, n, 2);
}