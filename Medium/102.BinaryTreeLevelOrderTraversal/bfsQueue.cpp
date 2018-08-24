class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res; 
        vector<int> tmp{root->val};
        queue<TreeNode*> bfs;
        res.push_back(tmp);
        bfs.push(root);
        tmp.clear();
 
        int total = 1, i = 0;
        while(!bfs.empty()){
            for(int i = 0; i < total; i++){
                TreeNode* head = bfs.front();
                bfs.pop();
                if(head->left){
                    tmp.push_back(head->left->val);
                    bfs.push(head->left);
                }
                if(head->right){
                    tmp.push_back(head->right->val);
                    bfs.push(head->right);
                }
            }
            if(!tmp.empty()){
                total = tmp.size();
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;        
        
    }
};
