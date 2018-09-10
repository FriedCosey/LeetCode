class Solution {
public:
    struct cord{
        int row = 0;
        int col = 0;
    };
    bool right(vector<vector<char>> board, int row, int col, char c){
        if(col + 1 < board[0].size() && c == board[row][col + 1])
            return true;
        return false;
    }
    bool left(vector<vector<char>> board, int row, int col, char c){
        if(col - 1 >= 0 && c == board[row][col - 1])
            return true;
        return false;
    }
    bool up(vector<vector<char>> board, int row, int col, char c){
        if(row - 1 >= 0 && c == board[row - 1][col])
            return true;
        return false;
    }
    bool down(vector<vector<char>> board, int row, int col, char c){
        if(row + 1 < board.size() && c == board[row + 1][col])
            return true;
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int pos, int row, int col){
        bool end = false;
        if(pos == word.size() - 1)
            return true;
        char c = board[row][col]; 
        board[row][col] = '0';
        if(right(board, row, col, word[pos + 1])){
            end = dfs(board, word, pos + 1, row, col + 1);
        }
        if(!end && left(board, row, col, word[pos + 1])){
            end = dfs(board, word, pos + 1, row, col - 1);
        }
        if(!end && up(board, row, col, word[pos + 1])){
            end = dfs(board, word, pos + 1, row - 1, col);
        }
        if(!end && down(board, row, col, word[pos + 1])){
            end = dfs(board, word, pos + 1, row + 1, col);
        }
        board[row][col] = c;
        return end;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        /*unordered_map<char, vector<cord>> lookup;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                cord tmp;
                tmp.row = i, tmp.col = j;
                lookup[board[i][j]].push_back(tmp);
            }
        }
        
        for(int i = 0; i < lookup[word[0]].size(); i++){
            cord tmp = lookup[word[0]][i];
            if(dfs(board, word, 0, tmp.row, tmp.col))
                return true;
        }*/
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                bool res = false;
                if(board[i][j] == word[0]){
                    res = dfs(board, word, 0, i, j);
                    if(res)
                        return true;
                }
            }
        }
        
        return false;
        
        
    }
};
