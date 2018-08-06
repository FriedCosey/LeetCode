ass Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            nums[i] = i + 1;
        int counter = 1, pos = 1;
        for(int i = 0; i < n - 1; i++)
            counter *= (pos++);
        k--;
        string res;
        for(int i = 0; i < n - 1; i++){
            res += '0' + nums[k / counter];
            nums.erase(nums.begin() + k / counter);
            k %= counter;
            counter /= (--pos);
        }
        res += '0' + nums[0];
        return res;
    }
};
