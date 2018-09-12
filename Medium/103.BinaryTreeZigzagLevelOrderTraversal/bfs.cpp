class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        int right = 1;
        
        vector<int> tmp;
        vector<TreeNode*> nodes;
        int counter = 0; 
        
        while(!bfs.empty()){
            int total = bfs.size();
            tmp.resize(total);
            counter = right == -1 ? total - 1 : 0;
            for(int i = 0; i < total; i++){
                TreeNode* cur = bfs.front();
                bfs.pop();
                tmp[counter] = cur->val; 
                counter += right;
                if(cur->left)
                    bfs.push(cur->left);
                if(cur->right)
                    bfs.push(cur->right);
            }
            res.push_back(tmp);
            tmp.clear();
            right *= -1;
        }
        return res;
        
    }
};
