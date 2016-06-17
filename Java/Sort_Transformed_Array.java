public class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int n = nums.length;
        int[] ret = new int[n];
        int ptr_l = -1, ptr_r = -1;
        boolean increase = true;
        double vertex = 0.0;
        if (a == 0) {
            ptr_r = 0;
            increase = b > 0 ? true : false;
        }
        else {
            increase = a > 0 ? true : false;
            vertex = b*(-1.0)/(2.0*a);
            ptr_l = -1;
            while (ptr_l < n-1 && nums[ptr_l+1] < vertex) { 
                ++ ptr_l;
            }
            ptr_r = ptr_l + 1;
        }
        int ptr_ret = increase ? 0 : n-1;
        int cand = 0;
        while (ptr_l >= 0 || ptr_r < n) {
            if (ptr_l < 0) cand = nums[ptr_r++]; 
            else if (ptr_r >= n) cand = nums[ptr_l--]; 
            else if (vertex - nums[ptr_l] > nums[ptr_r] - vertex) cand = nums[ptr_r++];
            else cand = nums[ptr_l --];
            ret[ptr_ret] = a*cand*cand+b*cand+c;
            ptr_ret += increase ? 1 : -1;
        }
        return ret;
    }
}
