class Solution {
public:
    int minDistance(string word1, string word2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = word1.length();
        int n = word2.length();
        if (m == 0){return n;}
        if (n == 0){return m;}
        int dp[m+1][n+1];
        dp[0][0] = 0; 
        for (int i = 1; i <= m; i ++){
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j ++){
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i ++){
            for (int j = 1; j <= n; j ++){
                dp[i][j] = INT_MAX;
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {                               // replace  
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if (dp[i][j-1] + 1 <= dp[i][j]) {    // insert
                    dp[i][j] = dp[i][j-1] + 1;
                }
                if (dp[i-1][j] + 1 <= dp[i][j]) {    // delete
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }
        return dp[m][n];
    }
};
