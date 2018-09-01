class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> depth;
        depth.push(root);
        
        int level = 0;
        while(!depth.empty()){
            int total = depth.size();
            level++;
            for(int i = 0; i < total; i++){
                TreeNode* head = depth.front();
                depth.pop();
                if(head->left)
                    depth.push(head->left);
                if(head->right)
                    depth.push(head->right);
            }
        }
        return level;
        
    }
};
