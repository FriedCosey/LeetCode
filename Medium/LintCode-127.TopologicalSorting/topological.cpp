class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        map<DirectedGraphNode*, int> inDegree;
        
        for(int i = 0; i < graph.size(); i++){
            if(inDegree.find(graph[i]) == inDegree.end())
                inDegree[graph[i]] = 0;
            for(int j = 0; j < graph[i]->neighbors.size(); j++){
                if(inDegree.find(graph[i]->neighbors[j]) == inDegree.end())
                    inDegree[graph[i]->neighbors[j]] = 1;
                else
                    inDegree[graph[i]->neighbors[j]]++;
            }
        }
        
        map<DirectedGraphNode*, int>::iterator it;
        queue<DirectedGraphNode*> start;
        for(it = inDegree.begin(); it != inDegree.end(); it++){
            if(it->second == 0)
                start.push(it->first);
        }
        
        vector<DirectedGraphNode*> res;
        while(!start.empty()){
            DirectedGraphNode* head = start.front();
            res.push_back(head);
            start.pop();
            for(int i = 0; i < head->neighbors.size(); i++){
                if(--inDegree[head->neighbors[i]] == 0)
                    start.push(head->neighbors[i]);
            }
        }
        return res;
    }
};
