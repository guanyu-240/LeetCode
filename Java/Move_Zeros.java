public class Solution {
    public void moveZeroes(int[] nums) {
        int ptr1 = -1, ptr2 = 0;
        while (ptr2 < nums.length) {
            if (nums[ptr2] == 0) {
                ptr2 ++;
            }
            else {
                nums[++ptr1] = nums[ptr2++];
            }
        }
        while (ptr1 < nums.length-1) {
            nums[++ptr1] = 0;
        }
    }
}
