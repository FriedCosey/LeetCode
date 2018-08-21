class Solution {
public:
    void helper(vector<int>& nums, int pos, int left, int right){
        if(left >= right)
            return;
        int last = left;
        int mid = left + (right - left) / 2;
        swap(nums[left], nums[mid]);
        for(int i = last + 1; i <= right; i++){
            if(nums[left] > nums[i])
                swap(nums[i], nums[++last]);
        }
        swap(nums[left], nums[last]);
        if(pos == last)
            return;
        else if(pos > last)
            helper(nums, pos, last + 1, right);
        else
            helper(nums, pos, left, last - 1); 
    }
    int findKthLargest(vector<int>& nums, int k) {
        helper(nums, nums.size() - k, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }
};
