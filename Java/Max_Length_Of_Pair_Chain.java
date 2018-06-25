class Solution {
    public int findLongestChain(int[][] pairs) {
        int longestChain = 0;
        int[] end = null;
        Arrays.sort(pairs, (p1, p2) -> p1[0] - p2[0]);
                
        for (int[] p : pairs) {
            if (end == null || end[1] < p[0]) {
                end = p;
                longestChain ++;
            } else {
                if (end[1] >= p[1]) {
                    end = p;
                }
            }
        }
        
        return longestChain;
    }
}
