// About Static Bool: https://stackoverflow.com/questions/26131112/why-stdsort-requires-static-compare-function
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool interCompare(const Interval& i, const Interval& j){
        return i.start < j.start;
    }
        
    vector<Interval> merge(vector<Interval>& intervals) {
        // new interval when right < min || left > max
        sort(intervals.begin(), intervals.end(), interCompare);
        if(intervals.empty())
            return intervals;
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start <= res.back().end)
                res.back().end = intervals[i].end > res.back().end ? intervals[i].end : res.back().end;
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
