class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        stringstream ss;
        int num  = 0, num1 = 0, num2 = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                num1 = nums.back(), nums.pop_back();
                num2 = nums.back(), nums.pop_back();
                num = num1 + num2;
                nums.push_back(num);
            }
            else if(tokens[i] == "/"){
                num1 = nums.back(), nums.pop_back();
                num2 = nums.back(), nums.pop_back();
                num = num2 / num1;
                nums.push_back(num);
            }
            else if(tokens[i] == "*"){
                num1 = nums.back(), nums.pop_back();
                num2 = nums.back(), nums.pop_back();
                num = num2 * num1;
                nums.push_back(num);
            }
            else if(tokens[i] == "-"){
                num1 = nums.back(), nums.pop_back();
                num2 = nums.back(), nums.pop_back();
                num = num2 - num1;
                nums.push_back(num);
                
            }
            else{
                ss.clear();
                ss.str(tokens[i]);
                ss >> num;
                nums.push_back(num);
            }
        }
        return nums[0];
        
        
    }
};
