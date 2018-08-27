class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        
        double minDiff = abs(target - root->val);
        int minVal = root->val;
        
        while(root != NULL){
            cout << root->val << endl;
            if(target > root->val){
                if(!root->right)
                    return minVal;
                root = root->right;
            }
            else if(target < root->val){
                if(!root->left)
                    return minVal;
                root = root->left;
            }
            else    
                return root->val;
            if(abs(root->val - target) < minDiff){
                minDiff = abs(root->val - target);
                minVal = root->val;
            }
        }
        return minVal;
        
    }
};
