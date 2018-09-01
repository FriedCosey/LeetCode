class Solution {
public:
    int helper(TreeNode* node){
        if(!node)
            return 0;
        return max(helper(node->left), helper(node->right)) + 1; 
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int left = helper(root->left);
        int right = helper(root->right);
        if(abs(left - right) > 1)
            return false;
        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);
        if(!r || !l)
            return false;
        return true;
    }
};
