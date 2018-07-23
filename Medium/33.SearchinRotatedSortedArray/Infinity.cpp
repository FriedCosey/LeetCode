class Solution {
public:
    int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // nums[0] > nums[mid] -> nums[mid] other sequence nums[0] > target
        // Eg: 7 8 9 10 0 1 2 3
        double num = 0;
        if(nums[0] <= target){
            if(nums[0] <= nums[mid])
                num = nums[mid];
            else
                num = INT_MAX;

        }
        else if(nums[0] > target){
            if(nums[0] > nums[mid]){
                num = nums[mid];
            }
            else
                num = INT_MIN;
        }
        //else
        //    return 0;
        if (num < target)
            low = mid + 1;
        else if (num > target)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
};
