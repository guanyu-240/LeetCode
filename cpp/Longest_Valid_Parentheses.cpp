class Solution {
public:
    /*
    Idea: Dynamic Programming
    Store the longest valid parentheses ending at i
    1 When i is ')':
    1.1 If i-1 is '(', then dp[i] is at least 2. Need to consider i-2. 
    1.1.1 If i-2 is a '(', it can not change.
    1.1.2 If i-2 is a ')': 
    1.1.2.1 If this ')' is not a valid ending, dp[i] is still 2
    1.1.2.2 If this ')' is a valid ending, dp[i] = dp[i-2] + 2;
    1.2 If i-1 is ')':
    1.2.1 If this ')' is a valid ending, trace back to the character before its start point, let it be c1
    1.2.1.1 If the c1 is '(', dp[i] is at least dp[i-1]+2, because[c1+1, cur-1] is a valid seq
            Then check the condition of c1-1. 
            If c1-1 is a valid end, the length of the sequnce shoule include the sequence end at c1-1
    2. When i is '(', dp[i] should be 0
    */ 
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        if (len <= 1) return 0;
        int dp[len];
        dp[0] = 0;
        int start;
        int ret = 0;
        for (int i = 1; i < len; i ++) {
            dp[i] = 0;
            if (s[i] == ')') { 
                if (s[i-1] == '('){
                    dp[i] = 2;
                    if (i >= 2 && s[i-2] == ')' && dp[i-2] > 0) {
                        dp[i] += dp[i-2];
                    }
                }
                else {
                    if (dp[i-1] > 0) {
                        start = i-1-dp[i-1];
                        if (s[start] == '('){
                            dp[i] = dp[i-1] + 2 + (start-1 > 0 ? dp[start-1] : 0);
                        }
                    }
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
