func maxArea(height []int) int {
    start,end := 0,len(height)-1
    max_area,tmp_area := 0,0
    for start < end {
        if height[start] <= height[end] {
            tmp_area = height[start]*(end-start)
            start ++
        } else {
            tmp_area = height[end]*(end-start)
            end --
        }
        if tmp_area > max_area {
            max_area = tmp_area
        }
    }
    return max_area
}
