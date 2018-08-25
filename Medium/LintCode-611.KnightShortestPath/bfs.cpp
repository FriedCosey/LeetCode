class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    bool isValid(vector<vector<bool>>& grid, Point p){
        if((p.x >= 0 && p.x < grid.size()) && (p.y >= 0 && p.y < grid[0].size()) && grid[p.x][p.y] == false)   return true;
        return false;
    }
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here
        int moves[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        
        
        if(grid.empty() || grid[0].empty())
            return -1;
        if(source.x == destination.x && source.y == destination.y)
            return 0;
            
        queue<Point> pos;
        pos.push(source);
        grid[source.x][source.y] = 1;
        int counter = 0;
        
        while(!pos.empty()){
            counter++;
            int total = pos.size();
            for(int i = 0; i < total; i++){
                Point cur = pos.front();
                pos.pop();
                for(int i = 0; i < 8; i++){
                    int x = cur.x + moves[i][0];
                    int y = cur.y + moves[i][1];
                    Point tmp(x, y);
                    if(!isValid(grid, tmp)){
                        continue;
                    }
                    if(x == destination.x && y == destination.y)
                        return counter;
                    pos.push(tmp);
                    grid[x][y] = true;
                }
            }
        }
        return -1;
    }
};
