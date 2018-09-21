class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& mem){
        if(i < 0)
            return 0;
        if(mem[i] != -1)
            return mem[i];
        
        int prepre = helper(nums, i - 2, mem) + nums[i];
        int pre = helper(nums, i - 1, mem);
        mem[i] = prepre > pre ? prepre : pre;
        return mem[i];
        
    }
    int rob(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return helper(nums, nums.size() - 1, mem);
    }
};
