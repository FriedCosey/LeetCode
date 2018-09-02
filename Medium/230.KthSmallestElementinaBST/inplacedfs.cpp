class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        helper(root, k, ans);
        return ans;
    }
    void helper(TreeNode* root, int &k, int &ans){
        if(root->left)
            helper(root->left, k, ans);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        if(root->right)
            helper(root->right, k, ans);
        
    }
};
