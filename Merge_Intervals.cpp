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
    static bool compare(Interval it1, Interval it2){
        return it1.start < it2.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        ret.clear();
        int len = intervals.size();
        if (len <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), compare);
        ret.push_back(intervals[0]);
        for (int n = 1; n < len; n ++){
            if (intervals[n].start <= ret.back().end){
                ret.back().end = max(intervals[n].end, ret.back().end);
            }
            else{
                ret.push_back(intervals[n]);
            }
        }
        return ret;
    }
};
