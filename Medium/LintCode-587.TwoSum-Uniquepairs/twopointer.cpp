class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int count = 0, left = 0, right = nums.size() - 1; 
        
        while(left < right){
            if(nums[left] + nums[right] > target)
                right--;
            else if(nums[left] + nums[right] < target)
                left++;
            else{
                count++;
                while(nums[left + 1] == nums[left])
                    left++;
                left++;
                while(nums[right - 1] == nums[right])
                    right--;
                right--;
            }
        }
        return count;
    }
};
