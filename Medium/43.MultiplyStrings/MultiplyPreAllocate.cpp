class Solution {
public:
    string multiply(string num1, string num2) {
        int tmp = 0, carry = 0;
        string res(num1.size() + num2.size(), '0');
        for(int j = num2.size() - 1; j >= 0; j--){
            carry = 0;
            for(int i = num1.size() - 1; i >= 0; i--){
                tmp = (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                res[i+j+1] = tmp % 10 + '0';
            }
            res[j] += carry;
        }
        int i = 0;
        for(i = 0; i < res.size() - 1; i++)
            if(res[i] != '0')
                break;
        res = res.substr(i);
        return res;
    }
};
