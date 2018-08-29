class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
     int helper(TreeNode** res, TreeNode* node, int& minVal){
        if(!node)
            return 0;
            
        int tmp = node->val + helper(res, node->left, minVal) + helper(res, node->right, minVal);
        
        if(tmp <= minVal){
            minVal = tmp;
            *res = node;
        }
        return tmp;
            
        
                
     }
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        int minVal = INT_MAX;
        TreeNode* res = root;
        helper(&res, root, minVal);
        return res;
    }
};
