class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        map<int, bool> usedNum; 
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(usedNum.find(nums[i]) == usedNum.end()){
                usedNum[nums[i]] = true;
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
