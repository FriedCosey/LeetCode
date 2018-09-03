class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        vector<TreeNode*> traverse; 
        while(root != NULL || !traverse.empty()){
            if(root){
                traverse.push_back(root);
                root = root->left;
            }
            else{
                root = traverse.back();
                res.push_back(root->val);
                traverse.pop_back();
                root = root->right;
            }
        }
        return res;
    }
};
