/*
        (
      /   \     
    (      ) 
   / \
  (   ) 
*/

class Solution {
public:
    void dfs(int n, vector<string>& res, string& cur, int count){
        if(count > n || count < 0)
            return;
        if(cur.size() == n * 2){
            if(count == 0)
                res.push_back(cur);
            return;
        }
        for(int i = 0; i < 2; i++){
            if(i == 0){
                cur += '(';
                count++;
            }
            else if(i == 1){
                cur += ')';
                count--;
            }
            dfs(n, res, cur, count);
            if(cur.back() == '('){
                count--;
            }
            else
                count++;
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        dfs(n, res, cur, 0);
        return res;
    }
};
