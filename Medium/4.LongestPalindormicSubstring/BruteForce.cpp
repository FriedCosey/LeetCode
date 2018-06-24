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
        int max = 0;
        string ans;
        for(int len = 1; len <= s.size(); len++){
            for(int i = 0; i + len - 1 < s.size(); i++){
                string ori, rev;
                for(int j = i, k = len; k > 0; k--, j++){
                    ori += s[j];
                }
                rev = reverse(ori);
                if(ori == rev && ori.length() > max){
                    ans = ori;
                    max = ori.length();
                }
            }
        }
        return ans;
        
    }
};
