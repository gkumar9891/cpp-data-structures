
class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int, int>> container;
        
        container.push(make_pair(color[0], radius[0]));
        
        for(int i = 1; i < color.size(); i++) {
            if(!container.empty() && container.top().first == color[i] && container.top().second == radius[i]) {
                container.pop();
            } else {
                container.push(make_pair(color[i], radius[i]));
            }  
        }
        
        return container.size();
    }
};