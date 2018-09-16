class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int counter = 0;
        int rh = 0, re = matrix.size() - 1; 
        int ch = 0, ce = matrix[0].size() - 1; 
        while(rh <= re && ce >= ch){
            if(matrix[rh][ce] == target){
                rh++, ce--;
                counter++;
            }
            else if(matrix[rh][ce] < target)
                rh++;
            else if(matrix[rh][ce] > target)
                ce--;
        }
        return counter;
    }
};
