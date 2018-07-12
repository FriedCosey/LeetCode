class Solution {
public:
    void combine(int pos, string digits, string& cur, vector<string>& res, string convertChar[]){
        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < convertChar[digits[pos]-'0'-2].size(); i++){
            cur += convertChar[digits[pos]-'0'-2][i];
            combine(pos + 1, digits, cur, res, convertChar);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string convertChar[8];
        char tmp = 'a';
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 3; j++){
                convertChar[i] += tmp;
                tmp++;
            }
            if(i == 5 || i == 7)
                convertChar[i] += tmp, tmp++;
        }
        string cur;
        combine(0, digits, cur, res, convertChar);
        return res;
    }
};
