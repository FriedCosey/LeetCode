class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int rowh = 0, rowe = matrix.size() - 1;
        int colh = 0, cole = matrix[0].size() - 1;
        
        while(rowh <= rowe && colh <= cole){
            int rowm = rowh + (rowe - rowh) / 2;
            int colm = colh + (cole - colh) / 2;
            //cout << rowm << " " << colm << endl;
            
            if(matrix[rowm][colm] > target){
                if(colm == 0)
                    rowe = rowm - 1, cole = matrix[0].size() - 1;
                else
                    cole = colm - 1;
            }
            else if(matrix[rowm][colm] < target){
                if(colm == matrix[0].size() - 1)
                    rowh = rowm + 1, colh = 0;
                else
                    colh = colm + 1;
            }
            else
                return true;
        }
        return false;
        
    }
};
