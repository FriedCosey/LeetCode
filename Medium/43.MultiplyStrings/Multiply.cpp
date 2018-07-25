class Solution {
public:
    string multiply(string num1, string num2) {
        int tmp = 0, carry = 0, idx = 0, counter = 0;
        string res;
        if(num1.size() == 1 && num1[0] == '0')
            return "0";
        if(num2.size() == 1 && num2[0] == '0')
            return "0";
        for(int pos = 0, j = num2.size() - 1; j >= 0; j--, pos++){
            carry = 0;
            idx = res.size() - pos - 1;
            counter = pos;
            for(int i = num1.size() - 1; i >= 0; i--){
                tmp = (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                if(res.size() >= counter + 1){
                    tmp = res[idx] - '0' + tmp;
                    carry = tmp / 10;
                    res[idx] = tmp % 10 + '0';
                    idx--;
                }
                else{
                    char t = '0' + tmp % 10;
                    res = t + res;
                }
                 counter++;
            }
            if(carry > 0){
                char t = '0' + carry;
                res = t + res;
            }
        }
        return res;
    }
};
