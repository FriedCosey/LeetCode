class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return " "; 
        stringstream ss;
        ss << root->val;
        return ss.str() + '|' + serialize(root->left) + '|' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return helper(data, pos);
    }
    
    TreeNode* helper(string data, int& pos){
        if(data[pos] == ' '){
            pos += 2;
            return NULL;
        }
        else{
            int origin = pos;
            while(pos < data.size() && data[pos] != '|')
                pos++;
            stringstream ss;
            ss.str(data.substr(origin, pos - origin));
            pos++;
            int tmp = 0;
            ss >> tmp;
            TreeNode* cur = new TreeNode(tmp);
            cur->left = helper(data, pos); 
            cur->right = helper(data, pos);
            return cur;
        }
    }
};
