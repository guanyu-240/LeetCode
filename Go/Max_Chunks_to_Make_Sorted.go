func maxOfTwoInt(a int, b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func maxChunksToSorted(arr []int) int {
    // Keep track of the end of the chunk
    chunk_end := 0
    res := 0
    for i,x := range arr {
        chunk_end = maxOfTwoInt(x, chunk_end)
        if i == chunk_end {
            res ++ 
        }
    }
    
    return res
}
