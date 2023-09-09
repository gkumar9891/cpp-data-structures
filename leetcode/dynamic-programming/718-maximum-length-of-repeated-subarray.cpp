class Solution {
public:
int t[1001][1001];
int ans;
int LCS(vector<int> &x, vector<int>& y, int m, int n, int count) {
    if(m == -1 || n == -1)
        return 0;

    if(t[m][n] != -1)
        return t[m][n];        

    if(x[m] == y[n]) {
        t[m][n] = 1+LCS(x, y, m-1, n-1, count+1);
    } else {
        t[m][n] = 0;
    }

    LCS(x, y, m, n-1, 0);
    LCS(x, y, m-1, n, 0);
   
    ans = max(ans, t[m][n]);

    return t[m][n];
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(t, -1, sizeof(t));
        ans = 0;
        LCS(nums1, nums2, nums1.size()-1, nums2.size()-1, 0);
        return ans;
    }
};