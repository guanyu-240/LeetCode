public class Solution {
    // count the number of arithmetic subslices with an arithmetic slice
    private int countSubSlices(int len) {
        int ret = 0;
        for (int n = 3; n <= len; ++ n) {
            ret += len-n+1; 
        }
        return ret;
    }
    public int numberOfArithmeticSlices(int[] A) {
        int n = A.length;
        if (n < 3) return 0;
        int diff = A[1]-A[0], count = 1;
        int ret = 0;
        for (int i = 2; i < n; ++ i) {
            if (i < n && A[i]-A[i-1] == diff) {
                count ++;
            }
            else {
                ret += countSubSlices(count+1);
                diff = A[i]-A[i-1];
                count = 1;
            }
        }
        if (count > 1) ret += countSubSlices(count+1);
        return ret;
    }
}
