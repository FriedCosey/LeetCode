class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] == nums[left] && nums[mid] == nums[right])
                left++, right--;
            else if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        int pivot = left;
        left = 0, right = pivot - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                return true;
        }
        
        left = pivot, right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
        
    }
};
