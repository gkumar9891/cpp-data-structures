class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        sort(arr, arr+n, [](Job a, Job b) {
            return a.dead < b.dead;
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i].dead > pq.size()) {
                pq.push(arr[i].profit);
                sum += arr[i].profit;
            }
            else if(arr[i].dead == pq.size()) {
                if(pq.top() < arr[i].profit) {
                    sum = (sum - pq.top()) + arr[i].profit;
                    pq.pop();
                    pq.push(arr[i].profit);
                }
            }
        }
        
        int time = pq.size();
        return {time, sum};
    } 
};