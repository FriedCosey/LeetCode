class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid = 0, low = 0, high = nums.size() - 1;
        while(low < high){
            if(nums[low] < nums[high])
                return nums[low];
            mid = low + (high - low) / 2;
            if(nums[mid] >= nums[low]) 
                low = mid + 1; // seqeunce in other side
            else 
                high = mid;
                
        }
        // 7 8 9 0 1 2 3 4 5
        // 2 3 5 1
        return nums[low];
    }
};
