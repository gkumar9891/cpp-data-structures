class Solution
{
public:

    int search(long long prefixSum[], int low, int high, long long sum, long long temp) {
        int mid, index = -1;
        
        long long first, second, diff = INT_MAX;
        
        while(low <= high) {
            mid = (low + high) / 2;
            first = prefixSum[mid] - temp;
            second = sum - prefixSum[mid];
            if(abs(first - second) < diff) {
                index = mid;
                diff = abs(first - second);
            } 
            
            if(first < second) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return index;
    }

    long long minDifference(int N, vector<int> &A) {
        // code here
    
        long long prefixSum[N];
        prefixSum[0] = A[0];
    
        for(int i = 1; i < N; i++) {
            prefixSum[i] = A[i] + prefixSum[i - 1];
        }
        
        long long ans = INT_MAX;
        long long w, x, y, z;
        
        for(int i = 2; i < N - 1; i++) {
            int index = search(prefixSum, 0, i - 1, prefixSum[i - 1], 0);
            w = prefixSum[index];
            x = prefixSum[i - 1] - w;
            index = search(prefixSum, i, N - 1, prefixSum[N - 1], prefixSum[i - 1]);
            y = prefixSum[index] - prefixSum[i - 1];
            z = prefixSum[N - 1] - prefixSum[index];
            
            ans = min(ans, max({w, x, y, z}) - min({w, x, y, z}));
        }
        
        return ans;
        
    }
};