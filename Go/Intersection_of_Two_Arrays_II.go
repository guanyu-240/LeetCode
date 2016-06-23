func intersect(nums1 []int, nums2 []int) []int {
    m := make(map[int]int)
    ret := []int{}
    for i := range nums1 {
        m[nums1[i]] ++
    }
    for i := range nums2 {
        if m[nums2[i]] > 0 {
            ret = append(ret, nums2[i])
            m[nums2[i]] --
        }
    }
    return ret
}
