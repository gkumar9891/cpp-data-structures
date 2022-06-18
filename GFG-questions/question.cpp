#include <bits/stdc++.h>

using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%c", &A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
  public:
  
     void bubblesort(vector<int> &A, int N ) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N - 1; j++) {
                if(A[j] > A[j + 1]) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
        }
    }
    
    bool binarySearch(vector<int> &A, int N, int key) {
        
        int start = 0;
        int end = N - 1;
        int mid = (start + end) / 2;
        
        if(key == A[mid]) {
            return false;
        }
        
        
        while(start < end) {
        
        if(key > A[mid]) {
            start = mid + 1;
            mid = ( start + end ) / 2;
        }
        if( key < A[mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
        } 
        
        if(key == A[mid]) {
            return false;    
        }
            
        }
        
        
        return true;
    }
  
    int solve(int N, vector<int> &A) {
        // code here
        int mex = 0;
        int j = N;
        
        bubblesort(A, N);
        
        while(j--) {
            
        bool gotMex = true;
 
        gotMex = binarySearch(A, N, mex);
        
        if(gotMex == true) {
            break;
        }
            mex++;
        }
        
        return mex;
    }
    
    
    
   
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%c", &t);
    while(t--){
        
        int N; 
        scanf("%c", &N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        int res = obj.solve(N, A);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code End




   