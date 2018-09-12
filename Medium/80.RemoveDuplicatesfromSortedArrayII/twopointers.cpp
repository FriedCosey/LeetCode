class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i = 0, k = 1;
        for(int j = 1; j < nums.size(); j++){
            if(k < 2 && nums[j] == nums[i]){
                nums[++i] = nums[j]; 
                k++;
            }
            else if(nums[j] != nums[i]){
                k = 1;
                nums[++i] = nums[j];
            }
        }
        return i + 1;
        
    }
};
