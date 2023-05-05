
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        
        map<int, int> container;
        int ans = 0;
        int sum = 0;
        
        for(int i = 0; i < lines.size(); i++) {
            int first = lines[i][0];
            int second = lines[i][1];
            
            container[first]++;
            container[second + 1]--;
        }
        
        for(auto el : container) {
            sum = sum + el.second;
            ans = max(sum, ans);
        }
        
        return ans;
    }
};