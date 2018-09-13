class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool **dp = new bool* [n];
        for(int i = 0; i < n; i++){
            dp[i] = new bool [n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = i == j ? true : false;
            }
        }
        
        for(int i = 1; i < n; i++){
            dp[i][i - 1] = true;
        }
        
        int counter = n;
        
        for(int len = 2; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                dp[i][i + len - 1] = (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]);
                if(dp[i][i + len - 1])
                    counter++;
            }
        }
        
        return counter;
    }
};
