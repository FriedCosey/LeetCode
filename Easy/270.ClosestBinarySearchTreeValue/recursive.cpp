class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* next = target > root->val ? root->right : root->left; 
        if(!next)
            return root->val;
        int deeper = closestValue(next, target);
        return abs(root->val - target) > abs(deeper - target) ? deeper : root->val; 
    }
};
