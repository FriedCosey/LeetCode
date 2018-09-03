class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, int> interest1;
        
        for(int i = 0; i < list1.size(); i++){
            interest1[list1[i]] = i;
        }
        
        int sum = 2000;
        vector<string> res; 
        
        for(int i = 0; i < list2.size(); i++){
            if(interest1.find(list2[i]) != interest1.end()){
                if(interest1[list2[i]] + i > sum)
                    continue;
                else if(interest1[list2[i]] + i < sum){
                    sum = interest1[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                }
                else{
                    res.push_back(list2[i]);
                }
            }
        }
        
        return res;
    }
};
