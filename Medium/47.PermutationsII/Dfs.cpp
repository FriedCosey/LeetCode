// Still Working

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        bool *visited = new bool[nums.size()];
        for(int i = 0; i < nums.size(); i++)
            visited[i] = false;
        vector<int> cur;
        vector<vector<int>> res;
        return dfs(nums, visited, cur, res);
    }
    vector<vector<int>> dfs(vector<int>& nums, bool visited[], vector<int>& cur, vector<vector<int>>& res){
        if(cur.size() == nums.size()){   
            res.push_back(cur);
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, visited, cur, res);
                visited[i] = false;
                cur.pop_back();
            }
            
        }
        return res;
    }
};
