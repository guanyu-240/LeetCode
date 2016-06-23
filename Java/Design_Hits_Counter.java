public class HitCounter {
    private static class Hit {
        private int ts;
        private int count;
        public Hit(int ts, int count) {
            this.ts = ts;
            this.count = count;
        }
        public int getTs() {
            return this.ts;
        }
        public int getCount() {
            return this.count;
        }
        public void addCount() {
            this.count ++;
        }
    }
    /** Initialize your data structure here. */
    private ArrayList<Hit> hits;
    private Hit last;
    public HitCounter() {
        hits = new ArrayList<Hit>();
        last = null;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        if (last == null || last.getTs() < timestamp) {
            last = new Hit(timestamp, (last == null ? 1 : last.getCount()+1));
            hits.add(last);
        }
        else {
            last.addCount();
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        if (last == null) return 0;
        int n = hits.size();
        int start = Math.max(timestamp - 300, 0);
        /* then find the first Hit obj with ts >= start */
        if (start > last.getTs()) return 0;
        if (start == 0) return last.getCount();
        int left = 0, right = n-1, target = 0;
        while (left <= right) {
            target = (left + right)/2;
            if (hits.get(target).getTs() <= start && 
                (target != n-1 && hits.get(target+1).getTs() > start)) {
                break;
            }
            else if (hits.get(target).getTs() > start) { right = target - 1; }
            else { left = target + 1; }
        }
        if (right < 0) target = -1;
        else if (left >= n) target = n-1;
        return target >= 0 ? last.getCount() - hits.get(target).getCount() : last.getCount();
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
