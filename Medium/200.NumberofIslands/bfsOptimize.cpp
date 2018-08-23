class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int row, int col){
        if((row >= 0 && row < grid.size()) && (col >= 0 && col < grid[0].size())){
            if(grid[row][col] == '1')
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
        queue<pos> bfs;
        int count = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == '1'){ 
                    grid[row][col] = '0';
                    count++;
                    pos tmp(row, col);
                    bfs.push(tmp);
                    while(!bfs.empty()){
                        pos head = bfs.front();
                        int row = head.row, col = head.col;
                        bfs.pop();
                        if(isValid(grid, row + 1, col)){
                            grid[row + 1][col] = '0';
                            pos tmp(row + 1, col);
                            bfs.push(tmp);
                        }             
                        if(isValid(grid, row, col + 1)){
                            grid[row][col + 1] = '0';
                            pos tmp(row, col + 1);
                            bfs.push(tmp);
                        }
                        if(isValid(grid, row - 1, col)){
                            grid[row - 1][col] = '0';
                            pos tmp(row - 1, col);
                            bfs.push(tmp);
                        }
                        if(isValid(grid, row, col - 1)){
                            grid[row][col - 1] = '0';
                            pos tmp(row, col - 1);
                            bfs.push(tmp);
                        }
                    }
                }
            }
        }
        return count;
        
        
    }
};
