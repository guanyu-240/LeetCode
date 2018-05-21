func numFriendRequests(ages []int) int {
    var count_younger [121]int
    for i := 0; i < len(ages); i++ {
        count_younger[ages[i]] ++
    }
    
    count_friends := 0
    for age := 1; age <= 120; age ++ {
        if age/2 + 7 < age {
            count_friends += count_younger[age] * (count_younger[age-1] - count_younger[age/2+7]) + 
                                count_younger[age] * (count_younger[age] - 1)
        }
        count_younger[age] += count_younger[age-1]
    }
    
    return count_friends
}
