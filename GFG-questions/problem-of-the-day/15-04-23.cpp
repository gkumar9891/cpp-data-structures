class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
    
        int current = -1;
        unordered_map<int, int> container;
        
        
        for(int i = 0; i < n; i++) {
            if(container.find(arr[i]) != container.end()) {
                current = current + time[arr[i] - 1];
            } else {
                current++;
                container[arr[i]] = current;
            }
        }
        
        return current;
    }
};