class Solution {
public:
    void helper(TreeNode* node, vector<int>& res){
        if(node->left)
            helper(node->left, res);
        res.push_back(node->val);
        if(node->right)
            helper(node->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        helper(root, res);
        return res;
    }
};
