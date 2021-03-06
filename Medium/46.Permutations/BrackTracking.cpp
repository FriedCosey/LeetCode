class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute(0, nums.size(), nums, res);
        return res;
    }
    void permute(int i, int j, vector<int>& nums, vector<vector<int>>& res) {
        if(i == j){
            res.push_back(nums);
        }
        else{
            for(int k = i; k < j; k++){
                swap(nums[k], nums[i]);
                permute(i+1, j, nums, res);
                swap(nums[k], nums[i]);
            }
        }
    }
    void swap(int &k, int &i){
        int temp = k;
        k = i;
        i = temp;
    }

};
