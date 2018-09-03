class Solution {
public:
    bool findNode(TreeNode* node, TreeNode* p, TreeNode *q){
        if(node == NULL)
            return false;
        if(node == p)
            return true;
        if(node == q)
            return true;
        bool tmp = findNode(node->left, p, q);
        if(tmp) 
            return true;
        tmp = findNode(node->right, p, q);
        if(tmp)
            return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == p || root == q)
            return root;
        bool left = findNode(root->left, p, q);
        bool right = findNode(root->right, p, q);
        if(left == true && right == true)
            return root;
        
        if(left) 
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
        
    }
};
