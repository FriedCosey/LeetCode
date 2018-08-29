class Solution {
public:
    void helper(TreeNode* root, TreeNode** pre){
        if(!root)
            return;
        helper(root->right, pre);
        helper(root->left, pre);
        root->right = *pre;
        root->left = NULL;
        *pre = root;
    }
    void flatten(TreeNode* root) {
        TreeNode* nothing = NULL;
        helper(root, &nothing);
    }
};
