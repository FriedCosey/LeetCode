class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
                right--;
            // 1 2 4 8 6 3
            else
                left = mid + 1;
            // 1 2 3 4 9 8 7
        }
        return nums[left];
    }
};
