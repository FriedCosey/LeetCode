class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<vector<int>> res;
        queue<NestedInteger> qList;
        for(int i = 0; i < nestedList.size(); i++){
            qList.push(nestedList[i]);
        }
        
        while(!qList.empty()){
            int total = qList.size();
            vector<int> tmp;
            for(int i = 0; i < total; i++){
                NestedInteger head = qList.front();
                qList.pop();
                if(head.isInteger()){
                    tmp.push_back(head.getInteger());
                }
                else{
                    vector<NestedInteger> tmp = head.getList();
                    for(int j = 0; j < tmp.size(); j++){
                        qList.push(tmp[j]);
                    }
                }
            }
            res.push_back(tmp);
        }
        
        int sum = 0, level = res.size();
        for(int i = 0; i < res.size(); i++){
            for(int j = 0; j < res[i].size(); j++){
                sum = sum + res[i][j] * level;
            }
            level--;
        }
        return sum;
        
    }
};
