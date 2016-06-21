// Priority Queue Implementation
type NumCount struct {
    number int
    count int
    index int
}

type PriorityQueue []*NumCount

func (pq PriorityQueue) Len() int { return len(pq)}

func (pq PriorityQueue) Less(i,j int) bool{
    return pq[i].count > pq[j].count
}
func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*NumCount)
	*pq = append(*pq, item)
	item.index = n
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	item.index = -1 // for safety
	*pq = old[0 : n-1]
	return item
}
func topKFrequent(nums []int, k int) []int {
    m := make(map[int]int)
    for _,v := range nums {
        m[v] ++
    }
    pq := make(PriorityQueue, len(m))
    i := 0
    for k,v := range m {
        pq[i] = &NumCount{number: k, count: v, index: i}
        i ++
    }
    heap.Init(&pq)
    ret := make([]int, k)
    ret_ptr := 0
    for pq.Len() > 0 && k > 0 {
        ret[ret_ptr] = heap.Pop(&pq).(*NumCount).number
        ret_ptr++
        k --
    }
    return ret
}
