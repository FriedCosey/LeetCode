class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> start;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copy;
        copy[node] = root;
        start.push(node);
        
        while(!start.empty()){
            UndirectedGraphNode *head = start.front();
            start.pop();
            for(int i = 0; i < head->neighbors.size(); i++){
                if(copy.find(head->neighbors[i]) != copy.end()){
                    copy[head]->neighbors.push_back(copy[head->neighbors[i]]);
                }
                else{
                    UndirectedGraphNode *dup = new UndirectedGraphNode(head->neighbors[i]->label);
                    copy[head->neighbors[i]] = dup;
                    start.push(head->neighbors[i]);
                    copy[head]->neighbors.push_back(dup);
                }
            }
        }
        return root;
    }
};
