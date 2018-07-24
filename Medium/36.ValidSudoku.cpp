class Solution {
public:
    // board[i][j] : board[i][j+1] ~ board[i][9]
    // board[i][j] : board[i+1][j] ~ board[9][j]
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            map<char, int> check;
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == '.')
                    continue;
                if(check.find(board[i][j]) != check.end())
                    return false;
                check[board[i][j]] = j;
            }
        }
        for(int i = 0; i < board.size(); i++){
            map<char, int> check;
            for(int j = 0; j < board[i].size(); j++){
                if(board[j][i] == '.')
                    continue;
                if(check.find(board[j][i]) != check.end())
                    return false;
                check[board[j][i]] = j;
            }
        }
        // 0 1 2  3 4 5
        for(int k = 0; k < 3; k++){
            for(int i = 0; i < board.size(); i++){
                map<char, int> check;
                for(int j = 0; j < 9; j++){
                    if(j == 3 || j == 6)
                        i++;
                    if(board[i][j%3+k*3] == '.')
                        continue;
                    if(check.find(board[i][j%3+k*3]) != check.end())
                        return false;
                    check[board[i][j%3+k*3]] = j;
                }
            }
        }
        return true;
    }
};
