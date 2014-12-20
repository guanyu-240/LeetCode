class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if (n <= 1) return n;
        int countDistinct = 1;
        int pos = 0;
        int ret = 0, maxCur = 1;
        for (int i = 1; i < n; i ++) {
            maxCur ++;
            if (s[i] != s[i-1]) {
                if (countDistinct == 1) {
                    countDistinct = 2;
                }
                else {
                    if (s[i] != s[pos-1]) {
                        maxCur = 1 + i-pos;
                    }
                }
                pos = i;
            }
            ret = max(ret, maxCur);
        }
        return ret;
    }
};
