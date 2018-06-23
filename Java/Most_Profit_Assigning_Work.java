class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        if (difficulty.length != profit.length) {
            return 0;
        }
        
        int[][] works = new int[difficulty.length][2];
        for (int i = 0; i < difficulty.length; i ++) {
            works[i][0] = difficulty[i];
            works[i][1] = profit[i];
        }
        
        Arrays.sort(works, (w1, w2) -> w1[1] - w2[1]);
        Arrays.sort(worker);
        
        int maxProfit = 0;
        int work = difficulty.length - 1;
        for (int i = worker.length - 1; i >= 0; i --) {
            while (work >= 0 && works[work][0] > worker[i]) {
                work --;
            }
            
            if (work >= 0) {
                maxProfit += works[work][1];
            }
        }
        
        return maxProfit;
    }
}
