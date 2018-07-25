class Solution {
public:
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void quicksort(vector<int>& nums, int low, int high){
        if(low >= high)
            return;
        int mid = low + (high - low) / 2;
        swap(nums[mid], nums[low]);
        int last = low;
        for(int i = low + 1; i <= high; i++)
            if(nums[i] < nums[low])
                swap(nums[++last], nums[i]);
        swap(nums[last], nums[low]);
        quicksort(nums, low, last - 1);
        quicksort(nums, last + 1, high);
        
    }
    void dfs(vector<vector<int>>& res, vector<int>& num, vector<int> candidates, int target, int pos, int sum){
        if(sum >= target){
            if(sum == target)
                res.push_back(num);
            return;
        }
        // vector<int> used;
        for(int i = pos; i < candidates.size(); i++){
            //if(find(used.begin(), used.end(), candidates[i]) != used.end())
                //continue;
            if(i - 1 >= pos  && candidates[i] == candidates[i-1])
                continue;
            // used.push_back(candidates[i]);
            sum += candidates[i];
            num.push_back(candidates[i]);
            dfs(res, num, candidates, target, i + 1, sum);
            sum -= candidates[i];
            num.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        quicksort(candidates, 0, candidates.size() - 1);
        vector<vector<int>> res; vector<int> num;
        dfs(res, num, candidates, target, 0, 0);
        return res;
        
    }
};
