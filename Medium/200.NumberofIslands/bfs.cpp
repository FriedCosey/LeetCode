class Solution {
public:
    bool isValid(vector<vector<char>>& grid, bool **visited, int row, int col){
        if((row >= 0 && row < grid.size()) && (col >= 0 && col < grid[0].size())){
            if(grid[row][col] == '1' && !visited[row][col])
                return true;
        }
        return false;
    }
    struct pos{
        pos(int row, int col){
            this->row = row;
            this->col = col;
        }
        int row = 0;
        int col = 0;
    };
    int numIslands(vector<vector<char>>& grid) {
        int row = 0, col = 0;
        if(grid.empty())
            return 0;
        bool **visited = new bool *[grid.size()];
        for(int i = 0; i < grid.size(); i++)
            visited[i] = new bool [grid[0].size()];
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                visited[i][j] = false;
            }
        }
        queue<pos> bfs;
        int count = 0;
        while(col < grid[0].size() && row < grid.size()){
            for(row = 0; row < grid.size(); row++){
                for(col = 0; col < grid[0].size(); col++){
                    if(grid[row][col] == '1' && !visited[row][col])
                        break;
                }
                if(col < grid[0].size() && grid[row][col] == '1' && !visited[row][col])
                    break;
            }
            if(col >= grid[0].size() || row >= grid.size())
                break;
            count++;
            visited[row][col] = true;
            pos tmp(row, col);
            bfs.push(tmp);
        
            while(!bfs.empty()){
                pos head = bfs.front();
                row = head.row, col = head.col;
                bfs.pop();
                if(isValid(grid, visited, row + 1, col)){
                    visited[row + 1][col] = true;
                    pos tmp(row + 1, col);
                    bfs.push(tmp);
                }             
                if(isValid(grid, visited, row, col + 1)){
                    visited[row][col + 1] = true;
                    pos tmp(row, col + 1);
                    bfs.push(tmp);
                }
                if(isValid(grid, visited, row - 1, col)){
                    visited[row - 1][col] = true;
                    pos tmp(row - 1, col);
                    bfs.push(tmp);
                }
                if(isValid(grid, visited, row, col - 1)){
                    visited[row][col - 1] = true;
                    pos tmp(row, col - 1);
                    bfs.push(tmp);
                }
            }
        }
        return count;
        
        
    }
};
