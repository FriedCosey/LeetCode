class Solution {
public:
    int binarySearch(vector<int> nums, int target, int low, int high){
        int mid = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int low = 0, high = nums.size() - 1, mid = 0;
        // find smallest
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]) 
                low = mid + 1;
            else
                high = mid;
        }
        int pivot = high;
        int res = binarySearch(nums, target, 0, pivot - 1);
        if(res != -1)
            return res;
        else
            return binarySearch(nums, target, pivot, nums.size() - 1);
    }
};
