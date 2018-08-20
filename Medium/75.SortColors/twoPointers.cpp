class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            while(left <= right && nums[left] == 0)
                left++;
            while(left <= right && (nums[right] == 1 || nums[right] == 2))
                right--;
            if(left <= right)
                swap(nums[right], nums[left]);
            else
                break;
            right--, left++;
        }
        right = nums.size() - 1;
        while(left <= right){
            while(left <= right && nums[left] == 1)
                left++;
            while(left <= right && nums[right] == 2)
                right--;
            if(left <= right)
                swap(nums[right], nums[left]);
            right--, left++;
        }
        
    }
};
