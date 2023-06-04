class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1, sum2, sum3;
        sum1 = sum2 = sum3 = 0;
        
        for(int i = 0; i < n1; i++)
            sum1 += s1[i];
            
        for(int i = 0; i < n2; i++)
            sum2 += s2[i];    
        
        for(int i = 0; i < n3; i++)
            sum3 += s3[i];
        
        int i, j, k;
        
        i = j = k = 0;
        
        int minimum = min(sum1, min(sum2, sum3));
        
        while(i <= n1 && j <= n2 && k <= n3) {
            if(sum1 > minimum)
                sum1 -= s1[i++];
                
            if(sum2 > minimum)
                sum2 -= s2[j++];
         
            if(sum3 > minimum)
                sum3 -= s3[k++];
                
            if(sum1 == sum2 && sum1 == sum3) {
                return sum1;
            }
            
            
            minimum = min(sum1, min(sum2, sum3));
        }
        
        return 0;
    }
};