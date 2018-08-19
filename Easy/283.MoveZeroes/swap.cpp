class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastZ = 0, lastN = 0;
        while(lastZ < nums.size() && lastN < nums.size()){
            while(lastZ < nums.size() && nums[lastZ] != 0)
                lastZ++;
            lastN = lastZ + 1;
            while(lastN < nums.size() && nums[lastN] == 0)
                lastN++;
            if(lastZ < nums.size() && lastN < nums.size())
                swap(nums[lastZ], nums[lastN]);
            lastZ++, lastN++;
        }
    }
};
