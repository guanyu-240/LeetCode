public class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.sort(coins);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = -1;
            for (int c : coins) {
                if (i - c >= 0 && dp[i-c] >= 0) {
                    if (dp[i] == -1) dp[i] = dp[i-c]+1;
                    else dp[i] = Math.min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount];
    }
}
