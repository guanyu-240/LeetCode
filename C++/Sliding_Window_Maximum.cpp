class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        For the window from [i-k+1, i], 
        Assume the index of the max value within this window is m,
        Then in the following iterations,
        - Elements before nums[m] will no longer be used
        - For an element num[j] where m<j<i, if nums[j] < nums[i], 
          nums[j] is not and will no longer be a candidate
        */
        int n = nums.size();
        deque<int> dq;
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (i-k >= 0 && !dq.empty() && dq.front() == nums[i-k]) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.front() < nums[i]) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if (i >= k-1) {
                ret.push_back(dq.front());
            }
        }
        return ret;
    }
};
