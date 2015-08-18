class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j,k;
        int ret = 0;
        for (int i = 0; i < n-2; i ++) {
            j = i+1;
            k = n-1;
            while (j < k) {
                if (nums[i]+nums[j]+nums[k] >= target) k --;
                else { ret += k-j; j ++; }
            }
        }
        return ret;
    }
};
