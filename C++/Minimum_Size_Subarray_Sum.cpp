class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /* Sliding windows strategy */
        int n = nums.size();
        if (n == 0) return 0;
        
        int x = 0, y = 0, ss = nums[0];
        int ret = n + 1;
        while (y < n && x <= y) {
            if (ss < s) {
                ++y;
                ss += nums[y];
            }
            else {
                ret = min(ret, y-x+1);
                ss -= nums[x];
                ++x;
            }
        }
        return ret == n+1 ? 0 : ret;
    }
};
