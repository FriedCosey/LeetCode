class Solution {
public:
    bool noAtk(vector<string> grid, int row, int col){
        // check col 
        for(int i = 0; i < grid.size(); i++)
            if(grid[i][col] == 'Q')
                return false;
        // check diagonal left
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if(grid[i][j] == 'Q')
                return false;
        // check diagonal right
        for(int i = row - 1, j = col + 1; i >= 0 && j < grid.size(); i--, j++)
            if(grid[i][j] == 'Q')
                return false;
        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> grid, int row){
        if(row == grid.size()){
            res.push_back(grid);
            return;
        }
        for(int col = 0; col < grid.size(); col++){
            if(noAtk(grid, row, col)){
                grid[row][col] = 'Q';
                helper(res, grid, row + 1);
                grid[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> grid(n, string(n, '.'));
        
        helper(res, grid, 0);
        
        return res;
        
    }
};
