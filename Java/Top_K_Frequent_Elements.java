public class Solution {
    class NumCount implements Comparable<NumCount> {
        int number;
        int count;
        public NumCount(int number, int count) {
            this.number = number;
            this.count = count;
        }
        public int compareTo(NumCount nc) {
            return count - nc.count;
        } 
    }
    
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        Integer tmp = null;
        for (int x : nums) {
            tmp = m.get(x);
            if (tmp == null) m.put(x, 1);
            else m.put(x, tmp+1);
        }
        PriorityQueue<NumCount> pq = new PriorityQueue<NumCount>();
        for (Map.Entry<Integer, Integer> e : m.entrySet()) {
            pq.add(new NumCount(e.getKey(), e.getValue()));
            if (pq.size() > k) pq.poll();
        }
        List<Integer> ret = new LinkedList<Integer>();
        for (NumCount nc : pq) {
            ret.add(nc.number);
        }
        return ret;
    }
}
