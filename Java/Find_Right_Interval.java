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
    public int[] findRightInterval(Interval[] intervals) {
        int n = intervals.length;
        int[] ret = new int[n];
        TreeMap<Integer, Integer> map = new TreeMap<>();
        int i = 0;
        for (i = 0; i < n; ++ i) {
            map.put(intervals[i].start, i);
        }
        for (i = 0; i < n; ++ i) {
            Map.Entry<Integer, Integer> entry = map.ceilingEntry(intervals[i].end);
            ret[i] = (entry == null ? -1 : entry.getValue()); 
        }
        return ret;
    }
}
