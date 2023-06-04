class Solution
{
  public:
    string reverseEqn (string s)
        {
            vector<string> numbers;
            vector<char> operations;
            
            string temp = "";
            
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                    operations.push_back(char(s[i]));
                    numbers.push_back(temp);
                    temp = "";
                } else {
                    temp += s[i];   
                }
            }
            numbers.push_back(temp);
            
            int i = numbers.size() - 1;
            int j = operations.size() - 1;
            
            string ans = "";
            
            while(j >= 0) {
                ans += numbers[i];
                ans += operations[j];
                
                j--;
                i--;
            }
            
            ans += numbers[0];
            
            return ans;
        }
};