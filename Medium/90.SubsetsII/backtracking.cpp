class Solution {
public:
    void helper(vector<int>& nums, int pos, vector<int> cur, vector<vector<int>>& res){
        if(pos == nums.size())
            return;
        for(int i = pos; i < nums.size(); i++){
            cur.push_back(nums[i]);
            res.push_back(cur);
            helper(nums, i + 1, cur, res);
            cur.pop_back();
            while(i < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        res.push_back(cur);
        helper(nums, 0, cur, res);
        return res;
            
        
    }
};
