public class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int low = 1, high = n-1;
        int mid = 0, count = 0;
        while (low < high) {
            mid = low + (high-low)/2;
            count = 0;
            for (int x : nums) {
                if (x <= mid) count ++;
            }
            if (count > mid) high = mid;
            else low = mid + 1;
        }
        return low;
    }
}
