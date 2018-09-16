class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int left = 0, right = matrix.size() - 1;
        // search row first
        while(left < right){
            int mid = left + (right - left) / 2; 
            if(matrix[mid][0] > target)
                right = mid - 1;
            else if(matrix[mid][0] < target)
                left = mid + 1;
            else
                return true;
        }
        int pivot = left;
        if(matrix[left][0] > target && left - 1 >= 0)
            pivot--;
        left = 0, right = matrix[left].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[pivot][mid] > target)
                right = mid - 1;
            else if(matrix[pivot][mid] < target)
                left = mid + 1;
            else
                return true;
        }
        return false;
        
        
    }
};
