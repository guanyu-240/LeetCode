public class Solution {
    public int characterReplacement(String s, int k) {
        /* Longest substring(length: m) with the majority
         * character c with m-k apperances   
         */
        int n = s.length(), start = 0, end = 0;
        if (n == 0) return 0;
        int ret = 1;
        int[] count = new int[26];
        count[s.charAt(0)-'A'] ++;
        while (start <= end) {
            if (array_max(count)+k >= end-start+1) {
                ret = Math.max(ret, end-start+1);
                if (end == n-1) break;
                count[s.charAt(++end)-'A']++;
            }
            else {
                count[s.charAt(start++)-'A']--;
            }
        }
        return ret;
    }
    private int array_max(int[] array) {
        int ret = 0;
        for (int x : array) {
            ret = Math.max(x, ret);
        }
        return ret;
    }
}
