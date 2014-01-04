class Solution {
public:
    /*
    Idea:
    n! can be splitted into n groups and group size is (n-1)!
    Therefore, at each time we can computer the group number by offset / (n-1)!
    And AvailableCharacters[groupNumber] is the character to append.
    Reason: For every group in every level, the highest bit is sorted in the increasing order.
    */ 
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string available("");
        for (int i = 1; i <= n; i ++) {
            available.append(1, '0' + i);
        }
        string ret("");
        int offset = k - 1, group = -1;
        int fact = 1;
        while (n > 0){
            fact = factorial(--n);
            group = offset / fact;
            offset %= fact;
            ret.append(1, available[group]);
            available.erase(group, 1);
        }
        return ret;
    }
    int factorial(int n) {
        int ret = 1;
        while (n > 0){
            ret *= n;
            n --;
        }
        return ret;
    }
};
