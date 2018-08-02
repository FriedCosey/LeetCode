class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        //if(matrix.size() == 1)
         //   return matrix[0];
        int top = 0, bot = matrix.size() - 1, right = matrix[0].size() - 1, left = 0;
        int row = 0, col = 0;
        // right down left up
        while(right > left && bot > top){
            while(col != right)
                res.push_back(matrix[row][col++]);
            right--;
            while(row != bot)
                res.push_back(matrix[row++][col]);
            bot--;
            while(col != left)
                res.push_back(matrix[row][col--]);
            left++;
            while(row != top)
                res.push_back(matrix[row--][col]);
            top++;
            row++, col++; // right then down 
        }
        if(top == bot && right == left){
            res.push_back(matrix[row][col]);
        }
        else if(top == bot && right > left){
            while(col <= right)
                res.push_back(matrix[row][col++]);
        }
        else if(right == left && bot > top){
            while(row <= bot)
                res.push_back(matrix[row++][col]);
        }
        return res;
    }
};
