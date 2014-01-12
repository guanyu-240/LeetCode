class Solution {
public:
    /*
    Dynamic Programming:
    Recursion:
    consider i in s and j in p
    s[i] = c
    When p[j+1] = '*'
    if p[j] = c or '.', match[i, j] = match[i+1, j+2] || match[i+1, j] || match[i, j+2]
    if p[j] != c, match[i, j] = match[i, j+2]
    When p[j+1] != '*'
    if p[i] = c or '.', match[i, j] = match[i+1, j+1]
    otherwise false
    Pay attention to borders
    */
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s);
        int n = strlen(p);
        bool dp[m+1][n+1];
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                dp[i][j] = false;
            }
        }
        dp[m][n] = true;
        for (int i = m; i >= 0; i --) {
            for (int j = n-1; j >= 0; j --) {
                if (p[j] == '*') continue;
                if (j < n-1 && p[j+1] == '*') {
                    if (i < m && (s[i] == p[j] || p[j] == '.')) {
                        dp[i][j] = dp[i+1][j+2] || dp[i+1][j] || dp[i][j+2];
                    }
                    else {
                        dp[i][j] = dp[i][j+2];
                    }
                }
                else {
                    if (i < m && (s[i] == p[j] || p[j] == '.')) {
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[0][0];
    }
};
