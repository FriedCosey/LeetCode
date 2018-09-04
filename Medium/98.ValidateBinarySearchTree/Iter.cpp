class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        vector<TreeNode*> inOrder; 
        TreeNode* pre = NULL; 
        
        while(root != NULL || !inOrder.empty()){
            if(root){
                inOrder.push_back(root);
                root = root->left;
            }
            else{
                root = inOrder.back();
                inOrder.pop_back();
                if(pre && pre->val >= root->val)
                    return false;
                pre = root;
                root = root->right;
            }
        }
        return true;
        
    }
};
