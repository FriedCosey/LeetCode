// TLE
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int sum, int& min){
        if(sum > min)
            return;
        if(col == grid[0].size() - 1 && row == grid.size() - 1){
            sum += grid[row][col];
            if(sum < min)
                min = sum;
            return;
        }
        for(int i = 0; i < 2; i++){
            sum += grid[row][col];
            if(i == 0 && col + 1 < grid[0].size())
                dfs(grid, row, col + 1, sum, min);
            else if(i == 1 && row + 1 < grid.size())
                dfs(grid, row + 1, col, sum, min);
            sum -= grid[row][col];
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int min = INT_MAX;
        dfs(grid, 0, 0, 0, min);
        return min;
    }
};
