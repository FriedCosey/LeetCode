class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1, n1_c = m - 1, n2_c = n - 1; 
        // 1 2 3 0 0 0, 2 5 6
        //while(pos >= 0 && n1_c >= 0 && n2_c >= 0){
        //    nums1[pos--] = nums1[n1_c] > nums2[n2_c] ? nums1[n1_c--] : nums2[n2_c--]; 
        //}
        while(pos >= 0 && n2_c >= 0){
            nums1[pos--] = n1_c >= 0 && nums1[n1_c] > nums2[n2_c] ? nums1[n1_c--] : nums2[n2_c--]; 
        }
    }
};
