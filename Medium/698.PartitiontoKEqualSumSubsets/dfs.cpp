class Solution {
public:
    bool helper(int group_sum, vector<int>& nums, vector<int>& sub, vector<bool>& used, int idx, int count, int start){
        if(sub[idx] == group_sum){
            if(idx == count - 2)
                return true;
            return helper(group_sum, nums, sub, used, idx + 1, count, 0);
        }
        
        for(int i = start; i < used.size() ;i++){
            if(used[i])
                continue;
            if(nums[i] + sub[idx] <= group_sum){
                sub[idx] += nums[i];
                used[i] = true;
                bool tmp = helper(group_sum, nums, sub, used, idx, count, i + 1);
                if(tmp)
                    return true;
                used[i] = false;
                sub[idx] -= nums[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        if(k == 1)
            return true;
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
        }
        if(sum % k)
            return false;
        
        vector<bool> used(nums.size(), false);
        vector<int> sub(k, 0);
        
        sub[0] = nums[0];
        used[0] = true;
        int group_sum = sum / k;
        int count = k;

        return helper(group_sum, nums, sub, used, 0, count, 0);
    }
};
