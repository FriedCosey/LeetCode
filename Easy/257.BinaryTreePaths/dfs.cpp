class Solution {
public:
    void helper(TreeNode* node, string path, vector<string>& res){
        stringstream ss; 
        ss << node->val;
        string tmp = ss.str();
        
        if(!node->left && !node->right){
            res.push_back(path + "->" + tmp);
        }
        
        if(node->left) 
            helper(node->left, path + "->" + tmp, res);
        if(node->right)
            helper(node->right, path + "->" + tmp, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)
            return res;
        stringstream ss;
        ss << root->val;
        string tmp = ss.str();
        
        string path = tmp;
        if(!root->left && !root->right)
            res.push_back(tmp);
        
        if(root->left)
            helper(root->left, path, res);
        if(root->right)
            helper(root->right, path, res);
        return res;
    }
};
