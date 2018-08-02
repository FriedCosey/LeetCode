class Solution {
public:
    bool dfs(int pos, vector<int> nums){
        if(pos >= nums.size())
            return false;
        if(pos == nums.size() - 1)
            return true;
        for(int i = 1; i <= nums[pos]; i++){
            if(dfs(pos + i, nums)) 
                return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        // return dfs(0, nums);
        if(nums.size() == 1)
            return true;
        for(int i = 0; i < nums.size(); i++)
            nums[i] += i;
        int n = nums[0];
        for(int i = 0; i <= n; i++){
            if(nums[i] >= nums.size() - 1)
                return true;
            n = nums[i] > n ? nums[i] : n;
        }
        return false;
    }
};
