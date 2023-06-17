class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        
        vector<int> ans(n+1, 0);
        ans[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            if(i%2 == 0) {
                ans[i] = 2;
            } else if(ans[i] == 0) {
                ans[i] = i;
                int j = i + i ;
                while(j <= n) {
                    if(!ans[j])
                        ans[j] = ans[i];
                    j = j + i;
                }
            }
        }
        
        return ans;
    }
};ww