class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        if(nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2 + 1;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] == target)
                left = mid;
            else
                right = mid - 1;
        }
        return nums[right] == target ? right : -1;
    }
};
