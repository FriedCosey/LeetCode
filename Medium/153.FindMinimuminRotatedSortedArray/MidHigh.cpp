class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid = 0, low = 0, high = nums.size() - 1;
        while(low < high){
            mid = low + (high - low) / 2;
            if(nums[mid] < nums[high]) 
                high = mid;
            else if(nums[mid] > nums[high])
                low = mid + 1;
            //else if(nums[mid] > nums[low])
               // low = mid + 1;
        }
        // 7 8 9 0 1 2 3 4 5
        // 0 1 2 3 4 5 7 8 9
        return nums[high];
    }
};
