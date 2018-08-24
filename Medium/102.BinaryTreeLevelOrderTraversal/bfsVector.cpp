class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res; 
        vector<int> tmp{root->val};
        vector<TreeNode*> bfs;
        res.push_back(tmp);
        bfs.push_back(root);
        tmp.clear();
 
        int total = 1, i = 0;
        while(i < total){
            TreeNode *head = bfs[i++];
            if(head->left){
                tmp.push_back(head->left->val);
                bfs.push_back(head->left);
            }
            if(head->right){
                tmp.push_back(head->right->val);
                bfs.push_back(head->right);
            }
            if(i == total && tmp.empty())
                break;
            if(i == total && !tmp.empty()){
                res.push_back(tmp);
                bfs.erase(bfs.begin(), bfs.begin() + total);
                total = tmp.size();
                i = 0;
                tmp.clear();
            }
        }
        return res;        
        
    }
};
