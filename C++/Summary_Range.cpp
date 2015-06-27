class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        bool rangeStart = true;
        int n = nums.size();
        int startNum;
        for (int i = 0; i < n; i ++) {
            if (rangeStart) {
                startNum = nums[i];
                rangeStart = false;
            }
            if (i == n-1 || (i != n-1 && nums[i+1] - nums[i] != 1)) {
                if (nums[i] != startNum) {
                    ret.push_back(to_string(startNum) + "->" + to_string(nums[i]));
                }
                else {
                    ret.push_back(to_string(nums[i]));
                }
                rangeStart = true;
            }
        }
        return ret;
    }
};
