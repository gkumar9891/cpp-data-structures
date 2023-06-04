class Solution {
  public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool isSafe(int n, int m, int x, int y) {
        if(x < 1 || y < 1 || x > n || y > m) {
            return 0;
        }
        
        return 1;
    }
    
    int getCount(int n, int m, vector<int> &x, vector<int> &y) {
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x[0] + dx[i];
            int ny = x[1] + dy[i];
            
            if(isSafe(n, m, nx, ny)) {
             
             if(nx == y[0] && ny == y[1])
                return -1;
             
             count++;   
            }
        }
        
        return count;
    }
    
    int minimumThorns(int n, int m, vector<int> &x, vector<int> &y) {
        // code here
        int tx = getCount(n, m, x, y);
        int ty = getCount(n, m, y, x);
        return min(tx, ty);
    }
};