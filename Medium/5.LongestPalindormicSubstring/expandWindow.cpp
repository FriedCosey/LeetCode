class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    void expand(string s, int left, int right, int &start, int &longest){
        while(left >= 0 && right < s.size() && s[left] == s[right])
            left--, right++;
        if(right - left - 1 > longest)
            longest = right - left - 1, start = left + 1;
    }
    string longestPalindrome(string &s) {
        int start = 0, longest = 0;
        for(int mid = 0; mid < s.size(); mid++){
            // odd
            expand(s, mid, mid, start, longest);
            // even
            expand(s, mid, mid + 1, start, longest);
        }
        return s.substr(start, longest);
    }
};
