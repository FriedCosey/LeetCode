class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int num_r = matrix.size(), num_c = matrix[0].size();
        int left = 0, right = num_r * num_c - 1; 
        
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(matrix[mid / num_c][mid % num_c] < target)
                left = mid + 1;
            else if(matrix[mid / num_c][mid % num_c] > target)
                right = mid - 1;
            else
                return true;
        }
        return false;
        
    }
};
