class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, mid = 0, right = arr.size() - 1;
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] < x)
                left = mid;
            else
                right = mid;
        }       
        vector<int> res;
        right = left + 1;
        for(int i = k; i > 0; i--){
            if(left == -1)
                break;
            else if(right == arr.size())
                left--;
            else if(abs(arr[left] - x) <= abs(arr[right] - x))
                left--;
            else
                right++;
        }
        for(int i = left + 1, j = k; j > 0; j--, i++)
            res.push_back(arr[i]);
        return res;
    }
};
