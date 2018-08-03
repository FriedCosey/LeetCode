class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int top = 0, bot = n - 1, right = n - 1, left = 0;
        int row = 0, col = 0, counter = 1;
        // right down left up
        while(right > left && bot > top){
            while(col != right)
                res[row][col++] = counter++;
            right--;
            while(row != bot)
                res[row++][col] = counter++;
            bot--;
            while(col != left)
                res[row][col--] = counter++;
            left++;
            while(row != top)
                res[row--][col] = counter++;
            top++;
            row++, col++; // right then down
        }
        if(top == bot && right == left){
            res[row][col] = counter++;
        }
        else if(top == bot && right > left){
            while(col <= right)
                res[row][col++] = counter++;
        }
        else if(right == left && bot > top){
            while(row <= bot)
                res[row++][col] = counter++;
        }
        return res;
    }
};
