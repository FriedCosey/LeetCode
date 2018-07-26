class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int *record = new int [nums.size()], max = nums[0];
        record[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            record[i] = (record[i-1] > 0 ? record[i-1] : 0) + nums[i];
            max = record[i] > max ? record[i] : max;
        }
        return max;
    }
};
