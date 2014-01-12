class Solution {
public:
    /*
    Idea:
    Dynamic Programming
    dp[i][j] indicates the number of distinct subsequences of T[i] in S[j]
    Recursion:
    1.If T[i] is a subsequence of S[j-1], T[i] should be a subsequence of  S[j]. 
    Therefore countSequences(T[i], S[j-1]) contributes to countSequences(T[i], S[j]) 
    2.If T[i] = S[j] and T[i-1] is a subsequence of S[j-1], then T[i] is a subsequence of S[j].
    Therefore countSequences(T[i-1], S[j-1]) contributes to countSequences(T[i], S[j]).
    Thus we get the recursion:
    dp[i][j] = dp[i][j-1] + (T[i]==S[j] ? dp[i-1][j-1] : 0)
    */
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = S.length();
        int n = T.length();
        if (m == 0 || m < n) return 0;
        if (n == 0) return m;
        int dp[n+1][m+1];
        for (int i = 0; i <= n; i ++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j ++) {
            dp[0][j] = 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++){
                dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[n][m];
    }
};
