class Solution:
    # @return a boolean
    """
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
    """
    def isMatch(self, s, p):
        m = len(s)
        n = len(p)
        dp = [[False]*(n+1) for i in range(m+1)]
        dp[m][n] = True
        for i in range (m, -1, -1):
            for j in range (n-1, -1, -1):
                if p[j] == '*': 
                    continue
                if j < n-1 and p[j+1] == '*':
                    if i < m and (p[j] == s[i] or p[j] == '.'):
                        dp[i][j] = (dp[i][j+2] or dp[i+1][j+2] or dp[i+1][j])
                    else:
                        dp[i][j] = dp[i][j+2]
                else:
                    if i < m and (p[j] == s[i] or p[j] == '.'):
                        dp[i][j] = dp[i+1][j+1]
                    else: dp[i][j] = False
        return dp[0][0]
