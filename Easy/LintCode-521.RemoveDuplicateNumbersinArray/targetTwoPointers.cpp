class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        int end = nums.size() - 1;
        for(int tar = 0; tar <= end; tar++){
            for(int i = tar + 1; i <= end;){
                if(nums[i] == nums[tar])
                    swap(nums[i], nums[end--]);
                else
                    i++;
            }
        }
        return end + 1;
        
    }
};
