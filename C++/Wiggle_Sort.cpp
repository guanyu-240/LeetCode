class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int tmp = 0;
        for (int i = 1; i < n; ++i) {
            if (i%2 == 1) {
                if (nums[i] < nums[i-1]) {
                    tmp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = tmp;
                }
            }
            else {
                if (nums[i] > nums[i-1]) {
                    tmp = nums[i];
                    nums[i] = nums[i-1];
                    nums[i-1] = tmp;
                }
            }
        }
    }
};
