type Hit struct {
    ts int
    countByNow int
}

type HitCounter struct {
    hits []Hit
}
/** Initialize your data structure here. */
func Constructor() HitCounter {
    return HitCounter{hits : []Hit{}}
}

/** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
func (this *HitCounter) Hit(timestamp int)  {
    n := len(this.hits)
    if n > 0 && this.hits[n-1].ts == timestamp {
        this.hits[n-1].countByNow ++;
    } else {
        countByNowV := 1
        if n > 0 {
            countByNowV += this.hits[n-1].countByNow
        }
        this.hits = append(this.hits, Hit{ts: timestamp, countByNow: countByNowV})
    }
}

/** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
func (this *HitCounter) Gethits(timestamp int) int {
    n := len(this.hits)
    if n == 0 { return 0 }
    start := timestamp - 300
    
    if start <= 0 { return this.hits[n-1].countByNow }
    if start >= this.hits[n-1].ts { return 0 }
    left,right,target := 0,n-1,0
    
    for left <= right {
        target = (left + right)/2
        if this.hits[target].ts <= start && 
                target != n-1 && 
                this.hits[target+1].ts > start {
            break
        } else if this.hits[target].ts > start {
            right = target-1
        } else {
            left = target+1
        }
    }
    if right < 0 { return this.hits[n-1].countByNow }
    return this.hits[n-1].countByNow - this.hits[target].countByNow
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Hit(timestamp);
 * param_2 := obj.Gethits(timestamp);
 */
