class Solution {
public:
    void swap(char *i, char *k){
        char tmp = *i;
        *i = *k;
        *k = tmp;
    }
    void reverse(string& nums, int start, int end){
        for(int i = 0; i < (end - start) / 2 + 1; i++){
            swap(&nums[i + start], &nums[end - i]);
        }
    }
    void nextPermutation(string& nums) {
        int pos = nums.size() - 1;
        for(; pos > 0; pos--)
            if(nums[pos] > nums[pos-1])
                break;
        if(pos == 0){
            reverse(nums, 0, nums.size() - 1);
            return; 
        }
        pos--;
        for(int i = nums.size() - 1; i > pos; i--){
            if(nums[i] > nums[pos]){
                swap(&nums[i], &nums[pos]);
                break;
            }
        }
        reverse(nums, pos + 1, nums.size() - 1);
        return;
    }
    string getPermutation(int n, int k) {
        string input;
        for(int i = 1; i <= n; i++)
            input += ('0' + i);
        for(int i = 1; i < k; i++){
            nextPermutation(input);
        }
        return input;
        
    }
};
