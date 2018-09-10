class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int start = 0, j = 0, i = 0;
        unordered_map<char, string> lookup;
        unordered_map<string, char> lookback;
        
        for(i = 0; i <= str.size(); i++){
            if(i == str.size() || str[i] == ' '){
                string cur = str.substr(start, i - start);
                start = ++i;
                if(lookup.find(pattern[j]) == lookup.end()){
                    if(lookback.find(cur) != lookback.end()){
                        return false;
                    }
                    lookup[pattern[j]] = cur;
                    lookback[cur] = pattern[j];
                }
                else{
                    if(lookup[pattern[j]] != cur)
                        return false;
                }
                j++;
            }
        }
        
        if(j != pattern.size())
            return false;
        return true;
        
    }
};
