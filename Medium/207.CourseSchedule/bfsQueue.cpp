class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // write your code here     
        vector<vector<int>> inVertex(numCourses);
        vector<pair<int, int>>::iterator it;
        vector<vector<int>> outVertex(numCourses);
        for( it = prerequisites.begin() ; it != prerequisites.end() ; it++){
            inVertex[it->second].push_back(it->first);
            outVertex[it->first].push_back(it->second);
        }
        
        vector<int> inDegree(numCourses);
        queue<int> bfs;
        for(int i = 0; i < numCourses; i++){
            inDegree[i] = inVertex[i].size();
            if(inDegree[i] == 0)
                bfs.push(i);
        }
        
        int counter = 0;
        while(!bfs.empty()){
            int head = bfs.front();
            counter++; 
            bfs.pop();
            inDegree[head] = -1;
            for(int i = 0; i < outVertex[head].size(); i++){
                if(--inDegree[outVertex[head][i]] == 0)
                    bfs.push(outVertex[head][i]);
            }
        }
        return counter == numCourses ? true : false;
    }
};
