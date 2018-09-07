class Solution {
public:
    int compress(vector<char>& chars) {
        int lookChar[127] = {0};
        int i = 0;
        for(i = 0; i < chars.size(); i++){
            if(lookChar[chars[i]] != 0){
                chars.erase(chars.begin() + i);
                i--;
            }
            lookChar[chars[i]]++;
            if(i != 0 && chars[i] != chars[i - 1] && lookChar[chars[i - 1]] >= 1){
                if(lookChar[chars[i - 1]] == 1){
                    lookChar[chars[i - 1]] = 0;
                    continue;
                }
                    
                stringstream ss;
                ss << lookChar[chars[i - 1]];
                string s = ss.str();
                for(int j = 0; j < s.size(); j++){
                    chars.insert(chars.begin() + i + j, s[j]);
                }
                lookChar[chars[i - 1]] = 0;
                i += s.size();
            }
        }
        if(lookChar[chars[i - 1]] > 1){
            stringstream ss;
            ss << lookChar[chars[i - 1]];
            string s = ss.str();
            for(int i = 0; i < s.size(); i++){
                chars.push_back(s[i]);
            }
        }
        
        return chars.size();
        
    }
};
