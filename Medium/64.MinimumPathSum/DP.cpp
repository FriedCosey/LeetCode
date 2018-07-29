class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> record(grid.size() + 1, vector<int>(grid[0].size() + 1, INT_MAX));
        record[0][1] = 0;
        for(int i = 1; i <= grid.size(); i++)
            for(int j = 1; j <= grid[0].size(); j++)
                record[i][j] = min(record[i-1][j], record[i][j-1]) + grid[i-1][j-1];
        return record[grid.size()][grid[0].size()];
    }
};
