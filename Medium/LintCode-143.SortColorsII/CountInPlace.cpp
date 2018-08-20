class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int *numCount = new int [k + 1];
        for(int i = 0; i <= k; i++){
            numCount[i] = 0;
        }
        vector<int> ans(colors.size());
        for(int i = 0; i < colors.size(); i++){
            numCount[colors[i]]++;
        }
        int counter = 0;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j < numCount[i]; j++){
                colors[counter++] = i;
            }
        }

    }
};
