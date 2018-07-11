class Solution {
public:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
        int last = left;
        swap(nums[left], nums[left + (right - left) / 2]);
        for(int i = left + 1; i <= right; i++){
            if(nums[i] < nums[left])
                swap(nums[++last], nums[i]);
        }
        swap(nums[last], nums[left]);
        quickSort(nums, last + 1, right);
        quickSort(nums, left, last - 1);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        quickSort(nums, 0, nums.size() - 1);
        int diff = INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int low = i + 1, high = nums.size() - 1;
            if(low >= high)
                break;
            // a + b + i = target
            if(abs(nums[low] + nums[high] + nums[i] - target) < diff){
                diff = abs(nums[low] + nums[high] + nums[i] - target);
                sum = nums[low] + nums[high] + nums[i]; 
            }
            while(low < high){
                if(nums[low] + nums[high] + nums[i] < target){
                    if(low + 1 >= high)
                        break;
                    else if(abs(nums[low + 1] + nums[high] + nums[i] - target) > diff) 
                        low++;
                    else{
                        diff = abs(nums[low + 1] + nums[high] + nums[i] - target);
                        sum = nums[low + 1] + nums[high] + nums[i];
                        low++;
                    }
                }
                else if(nums[low] + nums[high] + nums[i] > target){
                    if(high - 1 <= low) 
                        break;
                    else if (abs(nums[low] + nums[high - 1] + nums[i] - target) > diff) 
                        high--;
                    else{
                        diff = abs(nums[low] + nums[high - 1] + nums[i] - target);
                        sum = nums[low] + nums[high - 1] + nums[i];
                        high--;
                    }
                }
                else{   
                    sum = nums[low] + nums[high] + nums[i];
                    return sum;
                }
            }
        }
        return sum;
    }
};
