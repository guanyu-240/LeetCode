/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> employeeFreeTime(List<List<Interval>> schedule) {
        ArrayList<Interval> intervals = new ArrayList<Interval>();
        for (List<Interval> s : schedule) {
            for (Interval it : s) {
                intervals.add(it);
            }
        }
        
        List<Interval> res = new LinkedList<Interval>();
        Collections.sort(intervals, (i1, i2) -> (i1.start - i2.start));
        int start = -1, end = -1;
        for (Interval it : intervals) {
            if (it.start > end) {
                if (end != -1) {
                    res.add(new Interval(end, it.start));
                }
                
                start = it.start;
                end = it.end;
            } else {
                end = Math.max(end, it.end);
            }
        }
        
        return res;
    }
}
