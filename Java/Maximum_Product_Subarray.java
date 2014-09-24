public class Solution {
    /*
    Solution: Track two values when iterating the array
    a. maximum positive product till the current element
    b. minimum negative product till the current element
    If positive product is updated, it can be a candidate,
    otherwise, the current element is the candidate
    */
    public int maxProduct(int[] A) {
        int n = A.length;
        if (n == 0) return 0;
        int maxCurPos = 0, maxPrevPos = 0;
        int minCurNeg = 0, minPrevNeg = 0;
        int maxCur = 0;
        int ret = Integer.MIN_VALUE;
        for (int i = 0; i < n; i ++) {
            maxPrevPos = maxCurPos;
            minPrevNeg = minCurNeg;
            if (A[i] >= 0) {
                maxCurPos = maxPrevPos != 0 ? maxPrevPos*A[i] : A[i];
                minCurNeg = minPrevNeg * A[i];
                maxCur = maxCurPos;
            }
            else {
                maxCurPos = minPrevNeg * A[i];
                minCurNeg = maxPrevPos != 0 ? maxPrevPos*A[i] : A[i];
                if (maxCurPos > 0) maxCur = maxCurPos;
                else maxCur = A[i];
            }
            ret = Math.max(ret, maxCur);
        }
        return ret;
    }
}
