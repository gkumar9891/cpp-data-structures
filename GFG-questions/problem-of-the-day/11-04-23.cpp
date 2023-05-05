class Solution {
public:
    int solve(int a, int b, int c) {
        
        if((((a + b) * 2) + 2) < c || (((a + c) * 2) + 2) < b || (((c + b) * 2) + 2) < a) {
            return -1;
        }
        
        return a + b + c;
    }
};