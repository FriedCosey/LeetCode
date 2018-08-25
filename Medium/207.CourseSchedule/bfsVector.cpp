class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> inVertex(numCourses);
        vector<pair<int, int>>::iterator it;
        vector<vector<int>> outVertex(numCourses);
        for( it = prerequisites.begin() ; it != prerequisites.end() ; it++){
            inVertex[it->second].push_back(it->first);
            outVertex[it->first].push_back(it->second);
        }
        
        vector<int> inDegree(numCourses);
        for(int i = 0; i < numCourses; i++){
            inDegree[i] = inVertex[i].size();
        }
        
        for(int i = 0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses; j++){
                if(inDegree[j] == 0)
                    break;
            }
            if(j == numCourses)
                return false;
            inDegree[j] = -1;
            for(int k = 0; k < outVertex[j].size(); k++){
                inDegree[outVertex[j][k]]--;
            }
        }
        return true;
    }
};
