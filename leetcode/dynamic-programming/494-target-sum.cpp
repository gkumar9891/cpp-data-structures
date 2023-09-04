class Solution {
public:
    int memo[21][1001];
    int countSubset(vector<int> &arr, int &target, int index, int sum) {
        if(sum == target && index >= arr.size())
            return 1;
        if(index == arr.size())
            return 0;
        if(sum > target)
            return 0;

        if(memo[index][sum] != -1)
            return memo[index][sum];

                

        return memo[index][sum] = countSubset(arr, target, index + 1, sum + arr[index]) + countSubset(arr, target, index + 1, sum);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // if(nums.size() == 1) {
        //     return 0;
        // }
        
        memset(memo, -1, sizeof(memo));
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum < target)
            return 0;

        int newTarget = (target + sum) / 2;
        cout << sum << " " << newTarget;

        if((target + sum - (2*newTarget)) != 0)
            return 0;

        return countSubset(nums, newTarget, 0, 0); 
    }
};