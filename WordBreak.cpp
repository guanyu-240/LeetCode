class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        if (len == 0) {
            return false;
        }
        bool dp[len+1];
        fill_n(dp, len+1, false);
        dp[0] = true;
        for (int i = 0; i < len; i ++){
            if (dp[i] == true) {
                for (int j = i+1; j <= len; j++){
                    if (dict.find(s.substr(i, j-i)) != dict.end()) {
                        dp[j] = true;
                    }
                }
            }
        }
        return dp[len];
    }
};
