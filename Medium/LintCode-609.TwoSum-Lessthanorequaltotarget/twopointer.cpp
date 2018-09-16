class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // write your code here
        int head = 0, end = nums.size() - 1;
        int count = 0;
        sort(nums.begin(), nums.end());
        
        while(head < end){
            if(nums[head] + nums[end] <= target){
                count += (end - head);
                head++;
            }
            else if(nums[head] + nums[end] > target){
                end--;
            }
        }
        
        return count;
    }
};
