class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int range = 1;
        while(reader->get(range - 1) != INT_MAX){
            if(reader->get(range - 1) >= target)
                break;
            range *= 2;
        }
        
        int left = range / 2, right = range - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            int val = reader->get(mid);
            if(val == target)
                right = mid;
            else if(val > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return reader->get(left) == target ? left : -1;
    }
};
