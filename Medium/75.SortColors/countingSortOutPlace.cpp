class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numCount[3] = {0};
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            numCount[nums[i]]++;
        }
        for(int i = 1; i < 3; i++){
            numCount[i] += numCount[i - 1];
        }
        for(int i = 0; i < nums.size(); i++){
            ans[--numCount[nums[i]]] = nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i++){
            nums[i] = ans[i];
        }
        
    }
};
