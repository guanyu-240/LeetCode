/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        if (intervals.length <= 1) return 0;
        Arrays.sort(intervals, new Comparator<Interval>() {
            @Override
            public int compare(Interval i1, Interval i2) {
                return i1.start - i2.start;
            }
        });
        
        int x1 = 0, x2 = 1;
        int ret = 0;
        while (x2 < intervals.length) {
            if (intervals[x1].end <= intervals[x2].start) {
                x1 = x2;
                ++ x2;
            }
            else if (intervals[x1].end > intervals[x2].end) { // in this case, x1 should be removed
                x1 = x2;
                x2 ++;
                ret ++;
            }
            else {
                x2 ++;
                ret ++;
            }
        }
        return ret;
    }
}
