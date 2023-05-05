class Solution {
  public:
    long long solve(int n, vector<int> &arra, vector<int> &arrb) {
        // code here
        long long sum = 0;
        long long count = 0
        vector<int> a, b, c, d;
        
        sort(arra.begin(), arra.end());
        sort(arrb.begin(), arrb.end());
        
        for(int i = 0; i < n; i++) {
            if(arra[i] % 2 == 0) {
                b.push_back(arra[i]);
            } else {
                a.push_back(arra[i]);
            }
            
            if(arrb[i] % 2 == 0) {
                d.push_back(arrb[i]);
            } else {
                c.push_back(arrb[i]);
            }
            
            sum += arra[i] - arrb[i];
        }
        
        if(sum != 0 || a.size() != c.size()) {
            return -1;    
        }
        
        for(int i = 0; i < a.size(); i++) {
            count += abs(a[i] - c[i]) / 2;
        }
        
        for(int i = 0; i < b.size(); i++) {
            count += abs(b[i] - d[i]) / 2;
        }
        
        return count / 2;
    }
};