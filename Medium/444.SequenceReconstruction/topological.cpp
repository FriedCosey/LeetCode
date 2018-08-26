class Solution {
public:
    void countInVertex(vector<vector<int>>& seqs, unordered_map<int, unordered_set<int>>& inVertex){
        for(int i = 0; i < seqs.size(); i++){
            for(int j = 1; j < seqs[i].size(); j++){
                inVertex[seqs[i][j]].insert(seqs[i][j - 1]);
            }
        }
    }
    void countOutVertex(vector<vector<int>>& seqs, unordered_map<int, unordered_set<int>>& outVertex){
        for(int i = 0; i < seqs.size(); i++){
            for(int j = seqs[i].size() - 2; j >= 0; j--){
                outVertex[seqs[i][j]].insert(seqs[i][j + 1]);
            }
        }
    }
    void countInDegree(vector<int>& org, queue<int>& start, unordered_map<int, unordered_set<int>>& inVertex, unordered_map<int, int>& inDegree){
        for(int i = 0; i < org.size(); i++)
            inDegree[org[i]] = 0;
        unordered_map<int, unordered_set<int>>::iterator it; 
        for(it = inVertex.begin(); it != inVertex.end(); it++){
            inDegree[it->first] = it->second.size();
            if(inDegree[it->first] == 0){
                start.push(it->first);
            }
        }
        for(int i = 0; i < org.size(); i++)
            if(inDegree[org[i]] == 0)
                start.push(org[i]);
    }
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        unordered_set<int> nodes;
        for(int i = 0; i < seqs.size(); i++){
            for(int j = 0; j < seqs[i].size(); j++){
                if(nodes.find(seqs[i][j]) != nodes.end())
                    continue;
                nodes.insert(seqs[i][j]);
            }
        }
        if(nodes.size() != org.size())
            return false;
        
        
        unordered_map<int, unordered_set<int>> inVertex;
        countInVertex(seqs, inVertex);
        
        unordered_map<int, unordered_set<int>> outVertex;
        countOutVertex(seqs, outVertex);
        
        unordered_map<int, int> inDegree;
        queue<int> start;
        countInDegree(org, start, inVertex, inDegree);
        unordered_set<int>::iterator it; 
        
        int counter = 0;
        while(!start.empty() && start.size() == 1){
            int head = start.front();
            cout << head << endl;
            start.pop();
            if(org[counter] != head)
                return false;
            counter++; 
            for(it = outVertex[head].begin(); it != outVertex[head].end(); it++){
                if(--inDegree[*it] == 0)
                    start.push(*it);
            }
                
        }
        return counter == org.size() ? true : false;
        
        
    }
};
