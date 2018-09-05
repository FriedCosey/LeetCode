class Solution {
public:
    bool isPalindromic(string s){
        for(int i = 0, j = s.size() - 1; i <= j; i++, j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
    void helper(string s, vector<vector<string>> &res, vector<string> cur){
        for(int len = 1; len <= s.size(); len++){
            if(isPalindromic(s.substr(0, len))){
                cur.push_back(s.substr(0, len));
                if(len == s.size()){
                    res.push_back(cur);
                }
                else{
                    helper(s.substr(len), res, cur);
                    cur.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        helper(s, res, cur);
        return res;
    }
};
