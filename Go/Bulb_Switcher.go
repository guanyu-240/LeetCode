func bulbSwitch(n int) int {
    cnt := 1
    for cnt*cnt <= n {
        cnt ++
    }
    return cnt-1
}
