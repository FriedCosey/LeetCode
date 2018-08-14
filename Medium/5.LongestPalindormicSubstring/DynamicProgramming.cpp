class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool **dp = new bool* [n];
        for(int i = 0; i < n; i++)
            dp[i] = new bool [n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = false;
        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int i = 1; i < n; i++)
            dp[i][i-1] = true;
        // initialize
        
        int start = 0, longest = 1; 
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                dp[i][i + len - 1] = (s[i] == s[i + len - 1]) && (dp[i + 1][i + len - 2]); 
                if(dp[i][i + len - 1])
                    start = i, longest = len; 
            }
        }
        return s.substr(start, longest);
        
    }
};
