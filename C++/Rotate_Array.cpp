class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n == 0) return;
        k %= n;
        int start = 0, end = n-1;
        int toSwap = 0;
        while (start < end && k > 0) {
            if (k == (end-start+1)) break;
            toSwap = k > (end-start+1)/2 ? (end-start+1-k) : k;
            swap(nums, start, end, toSwap);
            if (k > (end-start+1)/2) {
                end -= toSwap;
                k = end-start+1-toSwap;
            }
            else {
                start += toSwap;
            }
        }
    }
    void swap(int nums[], int start, int end, int k) {
        if (start >= end || k > (end-start+1)/2) return;
        int tmp;
        for (int i = 0; i < k; i ++) {
            tmp = nums[start+i];
            nums[start+i] = nums[end-k+i+1];
            nums[end-k+i+1] = tmp;
        }
    }
};
