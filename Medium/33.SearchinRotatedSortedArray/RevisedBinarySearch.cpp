/*
3 4 5 6 7 8 1 2
target = 1; target = 3;
7 8 0 1 2 3 4 5
target = 0;
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[high]){ // Contains Other Sequence in Right 
                if(target < nums[mid] && target >= nums[low])
                    high = mid - 1; // Go Left 
                else
                    low = mid + 1; // Go Right
            }
            else if(nums[mid] < nums[high]){ // No Other equence in Right 
                if(target <= nums[high] && target > nums[mid])
                    low = mid + 1;
                else
                    high = mid - 1; // Go Left
            }
            else
                return -1;
        }
        return -1;
        
        
    }
};
