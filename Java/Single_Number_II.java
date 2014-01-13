public class Solution {
    public int singleNumber(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = A.length;
        if (n == 0) return 0;
        int one = 0, two = 0, zero = ~0;
        /*
        one: stores the bits with count % 3 = 1
        The ith bit of one is 1 indicates:
        Total number of appearances of 1s in the ith bit is k and k % 3 = 1
        The ith bit of one is 0 indicates:
        Total number of appearances of 1s in the ith bit is k and k % 3 != 1
        
        two: stores the bits with count % 3 = 2
        zero: stores the bits with count % 3 = 0
        */
        for (int i = 0; i < n; i ++) {
            two ^= (two & A[i]);   // clear the bits shifted up
            two |= (one & A[i]);   // include the bits shifted up from 'one'
            one ^= (one & A[i]);   // clear the bits shifted up
            one |= (zero & A[i]);  // include the bits shifted up from 'zero'
            zero = ~ (one | two);
        }
        return one;
    }
}
