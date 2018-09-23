class Solution {
public:
    int helper(TreeNode* root, vector<int>& res, int level){
        if(root == NULL)
            return level;
        int lev = max(helper(root->left, res, level + 1), helper(root->right, res, level + 1)) - 1;
        if(level + 1 > res.size() ){
            res.resize(lev + 1, INT_MIN);
            res[lev] = root->val;
        }
        else{
            if(root->val > res[lev]){
                res[lev] = root->val;
            }
        }
        return lev;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
        
    }
};
