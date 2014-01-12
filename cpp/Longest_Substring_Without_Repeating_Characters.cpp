class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        int ret = 0;
        int lastIndex[256];
        fill_n(lastIndex, 256, -1);
        int start = 0;
        for (int n = 0; n < len; n ++){
            char c = s[n];
            if (lastIndex[c] >= start) {
                start = lastIndex[c] + 1;
            }
            ret = max(ret, n - start + 1);
            lastIndex[c] = n;
        }
        return ret;
    }
};
