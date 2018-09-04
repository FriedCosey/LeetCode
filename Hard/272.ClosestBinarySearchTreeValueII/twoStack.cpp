class Solution {
public:
    TreeNode* getSucc(vector<TreeNode*>& succ){
        TreeNode* ret = succ.back();
        succ.pop_back();
        TreeNode* cur = ret->right;
        while(cur){
            succ.push_back(cur);
            cur = cur->left;
        }
        return ret;
    }
    
    TreeNode* getPred(vector<TreeNode*>& pred){
        TreeNode* ret = pred.back(); 
        pred.pop_back();
        TreeNode* cur = ret->left;
        while(cur){
            pred.push_back(cur);
            cur = cur->right;
        }
        return ret;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // predecessor smaller
        // successor larger
        vector<TreeNode*> succ; 
        vector<TreeNode*> pred;
        while(root){
            if(root->val > target){
                succ.push_back(root);
                root = root->left;
            }
            else{
                pred.push_back(root);
                root = root->right;
            }
        }
        
        vector<int> res;
        while(k--){
            if(pred.empty()){
                res.push_back(getSucc(succ)->val);
            }
            else if(succ.empty()){
                res.push_back(getPred(pred)->val);
            }
            else if(abs(pred.back()->val - target) < abs(succ.back()->val - target)){
                res.push_back(getPred(pred)->val);
            }
            else{
                res.push_back(getSucc(succ)->val);
            }
        }
        return res;
        
    }
    
};
