// word break
class Solution {
public:
    void helper(string& s, int pos, unordered_set<string>& words, string& origin, vector<string>& res){
        string old = s;
        for(int len = 1; len + pos <= s.size(); len++){
            if(words.find(s.substr(pos, len)) == words.end())
                continue;
            if(pos + len == s.size()){
                res.push_back(s);
                s = origin;
                return;
            }
            s.insert(s.begin() + pos + len, ' ');
            helper(s, pos + len + 1, words, origin, res);
            s = old;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
            
        unordered_set<string> words;
        for(int i = 0; i < wordDict.size(); i++){
            words.insert(wordDict[i]);
        }
        vector<string> res;
        int pos = 0;
        helper(s, pos, words, s, res);
        return res;
    }
};
