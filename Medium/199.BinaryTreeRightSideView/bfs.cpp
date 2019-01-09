class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()){
            int size = bfs.size();
            for(int i = 0; i < size; i++){
                if(i == 0)
                    res.push_back(bfs.front()->val);
                TreeNode* head = bfs.front();
                bfs.pop();
                if(head->right)
                    bfs.push(head->right);
                if(head->left)
                    bfs.push(head->left);
            }
        }
        return res;
        
        
    }
};
