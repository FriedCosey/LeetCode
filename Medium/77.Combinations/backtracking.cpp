class Solution {
public:
   void helper(int pos, int n, int k, vector<int> cur, vector<vector<int>>& res){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = pos; i <= n; i++){
            cur.push_back(i);
            helper(i + 1, n, k, cur, res);
            cur.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<vector<int>> res;
        helper(1, n, k, cur, res);
        return res;
    }
};
