class Solution {
public:
    /*
    Solution: Track two values when iterating the array
    a. maximum positive product till the current element
    b. minimum negative product till the current element
    If positive product is updated, it can be a candidate,
    otherwise, the current element is the candidate
    */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxCurPos = 0, maxPrevPos = 0;
        int minCurNeg = 0, minPrevNeg = 0;
        int maxCur = 0;
        int ret = INT_MIN;
        for (int i = 0; i < n; i ++) {
            maxPrevPos = maxCurPos;
            minPrevNeg = minCurNeg;
            if (nums[i] >= 0) {
                maxCurPos = maxPrevPos != 0 ? maxPrevPos*nums[i] : nums[i];
                minCurNeg = minPrevNeg * nums[i];
                maxCur = maxCurPos;
            }
            else {
                maxCurPos = minPrevNeg * nums[i];
                minCurNeg = maxPrevPos != 0 ? maxPrevPos*nums[i] : nums[i];
                if (maxCurPos > 0) maxCur = maxCurPos;
                else maxCur = nums[i];
            }
            ret = max(ret, maxCur);
        }
        return ret;
    }
};
