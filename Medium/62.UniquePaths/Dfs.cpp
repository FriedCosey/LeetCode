// Time Limit Exceeded

class Solution {
public:
    void dfs(int &path, int row, int col, int m, int n){
        if(row >= n || col >= m)
            return;
        if(row == n - 1 && col == m - 1){
            path++;
            return;
        }
        for(int i = 0; i < 2; i++){
            if(i == 0)
                dfs(path, row + 1, col, m, n);
            else
                dfs(path, row, col + 1, m, n);
        }
    }
    int uniquePaths(int m, int n) {
        int path = 0;
        dfs(path, 0, 0, m, n);
        return path;
    }
};
