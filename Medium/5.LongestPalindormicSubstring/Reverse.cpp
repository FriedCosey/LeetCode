/*
bad
dabab
*/

class Solution {
public:
    string reverse(string original){
        char tmp;
        string rev;
        for(int i = original.size() - 1; i >= 0; i--)
            rev += original[i];
        return rev;
        
    }
    string longestPalindrome(string s) {
        string rev = reverse(s);
        int table[s.length() + 1][s.length() + 1];
        int max = 0, row = 0, col = 0;
        for(int i = 0; i <= s.length(); i++)
            for(int j = 0; j <= s.length(); j++)
                table[i][j] = 0;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                if(rev[i-1] == s[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                    if(max < table[i][j]){
                        if(i - table[i][j] != s.length() - j)
                            continue;
                        max = table[i][j];
                        row = i, col = j;
                    }
                }
            }
        }
        string ans;
        for(int i = max, j = row - max; i > 0; i--, j++)
            ans += rev[j];
        return ans;
        
    }
};
