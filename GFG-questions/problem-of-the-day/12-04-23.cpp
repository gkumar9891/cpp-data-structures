
class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code her
        int half = n / 2;
        sort(arr.begin(), arr.begin() + half);
        reverse(arr.begin(), arr.begin() + half);
        
        sort(arr.begin() + half, arr.end());
        reverse(arr.begin() + half, arr.end());
        
        int ans = 0;
        int j = half;
        int size = half;
        for(int i = 0; i < half; i++) {
            size = half;
            j = half;
            while(j < n && !(arr[i] >= 5*arr[j])) {
             j++;
             size--;
            }
            
            ans = ans + size;
        }
      
      return ans;  
    }  
};