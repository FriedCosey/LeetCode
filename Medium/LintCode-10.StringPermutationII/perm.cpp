class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        // write your code here
        vector<string> res;
        permute(0, str.size(), str, res);
        return res;
    }
    void permute(int i, int j, string str, vector<string>& res) {
        if(i == j){
            res.push_back(str);
        }
        else{
            unordered_set<char> used;
            for(int k = i; k < j; k++){
                if(used.find(str[k]) != used.end())
                    continue;
                used.insert(str[k]);
                swap(str[k], str[i]);
                permute(i+1, j, str, res);
                swap(str[k], str[i]);
            }
        }
    }
};
