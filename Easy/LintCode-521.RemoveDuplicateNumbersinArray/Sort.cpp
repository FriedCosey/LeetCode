class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] != nums[i])
                nums[++i] = nums[j];
        }
        return i + 1;
        
    }
};
