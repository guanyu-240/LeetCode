class Solution {
    public int findLength(int[] A, int[] B) {
        int[][] dp = new int[A.length][B.length];
        int maxSubArrayLen = 0;
        for (int i = 0; i < A.length; i ++) {
            for (int j = 0; j < B.length; j ++) {
                if (A[i] == B[j]) {
                    dp[i][j] = i == 0 || j == 0 ? 1 : dp[i-1][j-1] + 1;
                        maxSubArrayLen = Math.max(maxSubArrayLen, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return maxSubArrayLen;
    }
}
