class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, mid = 0, high = nums.size() - 1;
        int left = 0, right = 0;
        vector<int> res(2);
        res[0]  = -1, res[1] = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target){
                left = right = mid;
                break;
            }
            else if(nums[mid] < target){
                low = mid + 1;
                if(nums[low] == target){
                    left = right = low;
                    break;
                }
                while(low + 1 < nums.size() && nums[low + 1] == nums[low])
                    low++;
            }
            else{
                high = mid - 1;
                if(nums[high] == target){
                    left = right = high; 
                    break;
                }
                while(high - 1 >= 0 && nums[high - 1] == nums[high])
                    high--;
            }
        }
        if(low <= high){
            while(right + 1 < nums.size() && nums[right + 1] == nums[right])
                right++;
            while(left - 1 >= 0 && nums[left - 1] == nums[left])
                left--;
            res[0] = left;
            res[1] = right;
        }
        return res;
    }
};
