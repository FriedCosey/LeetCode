class Solution {
public:
    void generateNeighbor(vector<pair<int, int>> prerequisites, vector<vector<int>>& inVertex, vector<vector<int>>& outVertex){
        vector<pair<int, int>>::iterator it;
        vector<pair<int, int>>& pre = prerequisites;
        for(it = pre.begin(); it != pre.end(); it++){
            inVertex[it->first].push_back(it->second);
            outVertex[it->second].push_back(it->first);
        }
    }
    
    void countIndegree(vector<vector<int>> inVertex, vector<int>& inDegree, queue<int>& start){
        for(int i = 0; i < inVertex.size(); i++){
            inDegree[i] = inVertex[i].size();
            if(inDegree[i] == 0){
                start.push(i);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> inVertex(numCourses);
        vector<vector<int>> outVertex(numCourses);
        queue<int> start;
        
        generateNeighbor(prerequisites, inVertex, outVertex);
        countIndegree(inVertex, inDegree, start);
        
        vector<int> res;
        while(!start.empty()){
            int head = start.front();
            res.push_back(head);
            start.pop();
            inDegree[head] = -1;
            
            for(int i = 0; i < outVertex[head].size(); i++) {
                if(--inDegree[outVertex[head][i]] == 0)
                    start.push(outVertex[head][i]);
            }
        }
        vector<int> nothing;
        return res.size() == numCourses ? res : nothing;;
    }
};	
