/**
 * Definition for an interval.
 * type Interval struct {
 *	   Start int
 *	   End   int
 * }
 */
type Intervals []Interval

func (slice Intervals) Len() int {
    return len(slice)
}
func (slice Intervals) Less(x,y int) bool {
    return slice[x].Start < slice[y].Start
}
func (slice Intervals) Swap(x,y int) {
    slice[x],slice[y] = slice[y],slice[x]
}

func merge(intervals []Interval) []Interval {
    ret := []Interval{}
    if len(intervals) == 0 { return ret }
    sort.Sort(Intervals(intervals))
    cand := intervals[0]
    for i := 1; i < len(intervals); i++ {
        if intervals[i].Start > cand.End {
            ret = append(ret, cand)
            cand = intervals[i]
        } else {
            if cand.End < intervals[i].End {
                cand.End = intervals[i].End
            }
        }
    }
    ret = append(ret, cand)
    return ret
}
