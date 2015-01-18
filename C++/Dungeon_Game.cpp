class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 0;
        int n = dungeon[0].size();
        if (n == 0) return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int x1 = 0, x2 = 0;
        for (int i = m-1; i >= 0; i --) {
            for (int j = n-1; j >= 0; j --) {
                if (i == m-1 && j == n-1) {
                    dp[i][j] = dungeon[i][j] > 0 ? 1 : 1+(-1)*dungeon[i][j];
                }
                else {
                    x1 = (i == m-1 ? INT_MAX: dp[i+1][j]);
                    x2 = (j == n-1 ? INT_MAX: dp[i][j+1]);
                    if (dungeon[i][j] < 0) {
                        dp[i][j] = min(x1, x2) - dungeon[i][j];
                    }
                    else {
                        dp[i][j] = max(min(x1, x2) - dungeon[i][j], 1);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
