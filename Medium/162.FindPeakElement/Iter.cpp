class Solution {
public:
    int isPeak(vector<int>& nums, int mid){
        if(mid == 0 && nums[mid] > nums[mid + 1])
            return mid;
        else if(mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
            return mid;
        else if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            int tmp = isPeak(nums, mid); 
            if(tmp != -1)
                return tmp;
            if(nums[mid] < nums[mid + 1])
                left = mid + 1;
            else if(nums[mid] < nums[mid - 1])
                right = mid - 1;
        }
        return nums[left] > nums[right] ? left : right;
    }
};
