class Solution {
public:
    bool isAlphaNumeric(char &c){
        c = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            return true;
        else
            return false;
        
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left <= right){
            while(!isAlphaNumeric(s[left]))
                left++;
            while(!isAlphaNumeric(s[right]))
                right--;
            if(s[left] != s[right] && left < s.size() && right > 0)
                return false;
            left++, right--;
        }
        return true;
    }
};
