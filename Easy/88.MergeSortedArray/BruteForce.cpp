class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0, i = 0;
        for(; i < m && j < n; i++){
            if(nums2[j] < nums1[i]){
                nums1.insert(nums1.begin() + i, nums2[j++]);
                m++;
                nums1.pop_back();
            }
        }
        for(; j < n; i++, j++){
            nums1[i] = nums2[j];
        }
    }
};
