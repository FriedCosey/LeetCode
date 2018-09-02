class Solution {
public:
    void countElements(TreeNode* node, int& counter){
        if(!node)
            return;
        counter++;
        countElements(node->left, counter);
        countElements(node->right, counter);
    }
    int kthSmallest(TreeNode* root, int k) {
        int left = 0;
        countElements(root->left, left);
        if(k == left + 1)
            return root->val;
        else if(k > left + 1){
            return kthSmallest(root->right, k - left - 1);
        }
        else{
            return kthSmallest(root->left, k);
        }
    }
};
