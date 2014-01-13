public class Solution {
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
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        char[] sc = s.toCharArray();
        char[] pc = p.toCharArray();
        boolean[][] dp = new boolean[m+1][n+1];
        for (boolean[] row : dp) {
            Arrays.fill(row, false);
        }
        dp[m][n] = true;
        for (int i = m; i >= 0; i --) {
            for (int j = n-1; j >= 0; j --) {
                if (pc[j] == '*') continue;
                if (j < n-1 && pc[j+1] == '*') {
                    if (i < m && (pc[j] == '.' || pc[j] == sc[i])) {
                        dp[i][j] = dp[i][j+2] || dp[i+1][j+2] || dp[i+1][j];
                    }
                    else {
                        dp[i][j] = dp[i][j+2];
                    }
                }
                else {
                    if (i < m && (pc[j] == '.' || pc[j] == sc[i])) {
                        dp[i][j] = dp[i+1][j+1];
                    }
                }
            }
        }
        return dp[0][0];
    }
}
