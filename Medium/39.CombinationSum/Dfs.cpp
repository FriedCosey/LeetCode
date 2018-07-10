class Solution {
public:
    void recSum(int& sum, vector<int>& candidates, int target, vector<vector<int>>& sol, vector<int>& tmp, int cur){
        if(sum >= target){
            if(sum == target) 
                sol.push_back(tmp);
            return;
        }
        for(int i = cur; i < candidates.size(); i++){
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            recSum(sum, candidates, target, sol, tmp, i);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<vector<int>> sol;
        vector<int> tmp;
        recSum(sum, candidates, target, sol, tmp, 0);
        return sol;
    }
};
