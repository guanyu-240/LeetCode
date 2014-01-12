class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        stack<int> s;
        height.push_back(0);
        int len = height.size();
        int maxRec = 0;
        for (int n = 0; n < len; n ++) {
            if (s.empty() || height[s.top()] < height[n]) {
                s.push(n);
            }
            else {
                while (!s.empty() && height[s.top()] > height[n]) {
                    int tmp = s.top();
                    s.pop();
                    maxRec = height[tmp] * (s.empty() ? n : (n - s.top() - 1));
                    ret = max(maxRec, ret);
                }
                s.push(n);
            }
        }
        return ret;
    }
};
