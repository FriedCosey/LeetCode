class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        int minVal = root->val;
        
        while(root){
            if(abs(root->val - target) < abs(target - minVal)){
                minVal = root->val;
            }
            if(target > root->val){
                root = root->right;
            }
            else if(target < root->val){
                root = root->left;
            }
            else    
                return root->val;
        }
        return minVal;
        
    }
};
