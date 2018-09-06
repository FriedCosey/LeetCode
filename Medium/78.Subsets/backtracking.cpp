class Solution {
public:
    void helper(vector<int> nums, int pos, vector<vector<int>>& res, vector<int> cur){
        if(pos == nums.size())
            return;
        for(int i = pos; i < nums.size(); i++){
            cur.push_back(nums[i]);
            res.push_back(cur);
            helper(nums, i + 1, res, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        res.push_back(cur);
        helper(nums, 0, res, cur);
        return res;
    }
};
