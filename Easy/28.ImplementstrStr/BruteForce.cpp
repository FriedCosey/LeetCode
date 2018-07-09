class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty() || haystack.size() < needle.size())
            return -1;
        int i = 0, j = 0;
        for(i = 0; i <= haystack.size() - needle.size(); i++){
            for(j = 0; j < needle.size(); j++){
                if(haystack[i + j] != needle[j])
                    break;
            }
            if(j == needle.size())
                break;
        }
        return j == needle.size() ? i : -1;
    }
};
