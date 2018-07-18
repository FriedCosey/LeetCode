class Solution {
public:
    int myAtoi(string str) {
        int num = 0;
        bool sign = false;
        int i = 0;
        while(str[i] == ' ' && i < str.size())
            i++;
        if(i < str.size() && (str[i] == '-' || str[i] == '+')){
            sign = str[i] == '-' ? true : false;
            i++;
        }
        for(; i < str.size(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                if(num > INT_MAX / 10){
                    return sign ? INT_MIN : INT_MAX;
                }
                else if(num == INT_MAX / 10 && str[i] > '7')
                    return sign ? INT_MIN : INT_MAX;
                num = num * 10 + str[i] - '0';
            }
            else
                break;
        }
        return sign ? -1 * num : num;
    }
};
