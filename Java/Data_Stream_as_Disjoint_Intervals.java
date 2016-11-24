/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class SummaryRanges {
    private TreeMap<Integer, Integer> map;;
    /** Initialize your data structure here. */
    public SummaryRanges() {
        map = new TreeMap<>();
    }
    
    public void addNum(int val) {
        int candKey = val, candVal = val;
        Map.Entry<Integer, Integer> before = map.floorEntry(val);
        Map.Entry<Integer, Integer> after = map.higherEntry(val);
        if (before != null) {
            if (before.getValue() >= val) { return; } // no insertion needed
            else if (before.getValue() == val - 1) {
                candKey = before.getKey(); // "before" needs to be extended
            }
        }
        if (after != null && after.getKey() == val + 1) {
            map.remove(val+1); // "after" needs to be cleared
            candVal = after.getValue();
        }
        map.put(candKey, candVal);
    }
    
    public List<Interval> getIntervals() {
        List<Interval> ret = new LinkedList<Interval>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            ret.add(new Interval(entry.getKey(), entry.getValue()));
        }
        return ret;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * List<Interval> param_2 = obj.getIntervals();
 */
