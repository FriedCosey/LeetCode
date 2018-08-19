class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numCount[3] = {0};
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            numCount[nums[i]]++;
        }
        int counter = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < numCount[i]; j++){
                nums[counter++] = i;
            }
        }
        
    }
};
