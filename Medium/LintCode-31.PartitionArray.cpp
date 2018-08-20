class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            while(left <= right && nums[left] < k)
                left++;
            while(left <= right && nums[right] >= k)
                right--;
            if(left <= right)
                swap(nums[left], nums[right]);
            else
                break;
            left++, right--;
        }
        return left;
    }
};
