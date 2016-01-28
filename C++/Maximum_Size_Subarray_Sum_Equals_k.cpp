class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, ret = 0;
        unordered_map<int, int> sum_index;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == k) {
                ret = i + 1;
            }
            else {
                it = sum_index.find(sum-k);
                if (it != sum_index.end()) {
                    ret = max(ret, i-it->second);
                }
            }
            if (sum_index.find(sum) == sum_index.end()) {
                sum_index[sum] = i;
            }
        }
        return ret;
    }
};
