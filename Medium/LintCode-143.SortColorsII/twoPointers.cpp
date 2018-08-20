class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void helper(vector<int>& colors, int left, int right, int head, int end){
        if(right - left <= 0)
            return;
        int begin = head, last = end;
        int mid = left + (right - left) / 2;
        while(head <= end){
            while(head <= end && (colors[head] >= left && colors[head] <= mid))
                head++;
            while(head <= end && (colors[end] >= mid + 1 && colors[end] <= right))
                end--;
            if(head <= end)
                swap(colors[head], colors[end]);
            else
                break;
            head++, end--;
        }
            helper(colors, left, mid, begin, head - 1);
            helper(colors, mid + 1, right, head, last);
    }
    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        helper(colors, 1, k, 0, colors.size() - 1);
    }
};
