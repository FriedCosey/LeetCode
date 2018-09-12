class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0')
            return 0;
        
        int* dp = new int [s.size()];
        for(int i = 0; i < s.size(); i++) 
            dp[i] = 0;
        
        dp[0] = 1;
        stringstream ss;
        string c;
        c = s[0];
        c += s[1];
        ss.str(c);
        int tmp = 0;
        ss >> tmp;
        
        if(s.size() == 1)
            return 1;
        
        if(s[1] != '0')
            dp[1] = 1;
        if(tmp >= 10 && tmp <= 26){
            dp[1]++;
        }
        
        cout << dp[1] << endl;
        
        
        
        for(int i = 2; i < s.size(); i++){
            ss.clear();
            c.clear();
            c = s[i-1];
            c += s[i];
            ss.str(c);
            ss >> tmp;
            if(s[i] != '0')
                dp[i] = dp[i - 1];
            if(tmp >= 10 && tmp <= 26)
                dp[i] += dp[i - 2];
            cout << dp[i] << endl;
        }
        
        return dp[s.size() - 1];
        
    }
};
