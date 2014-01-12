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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        Interval newInt = newInterval;
        vector<Interval> ret;
        bool inserted = false;
        for (int n = 0; n < intervals.size(); n ++){
            Interval cur = intervals[n];
            if (cur.start > newInt.end) {
                if (inserted == false) {
                    ret.push_back(newInt);
                    inserted = true;
                }
                ret.push_back(cur);
            }
            else if (cur.end < newInt.start) {
                ret.push_back(cur);
            }
            else {
                newInt.start = min(cur.start, newInt.start);
                newInt.end = max(cur.end, newInt.end);
            }
        }
        if (inserted == false) {
            ret.push_back(newInt);
            inserted = true;
        }
        return ret;
    }
};
