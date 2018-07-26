class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int **grid = new int* [n];
        for(int i = 0; i < n; i++)
            grid[i] = new int [m];
        int obst = 0;
        for(; obst < obstacleGrid[0].size(); obst++)
            if(obstacleGrid[0][obst] == 1) 
                break;
        for(int i = 0; i < obstacleGrid[0].size(); i++){
            grid[0][i] = i < obst ? 1 : 0;
        }
        for(obst = 0; obst < obstacleGrid.size(); obst++)
            if(obstacleGrid[obst][0] == 1) 
                break;
        for(int i = 0; i < obstacleGrid.size(); i++){
            grid[i][0] = i < obst ? 1 : 0;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                grid[i][j] = obstacleGrid[i][j] == 1 ? 0 : grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[n-1][m-1];
    }
};
