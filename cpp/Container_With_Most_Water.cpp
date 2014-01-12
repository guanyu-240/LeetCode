class Solution {
public:
    /*
    Reason for moving the pointer with smaller height
    current area: smaller*|index_larger - index_smaller|
    if moving the larger ptr, new area: min(smaller, newPtr)*(|index_larger - index_smaller| - 1) <= current
    if moving the smaller ptr, new area: min(newPtr, larger)*(|index_larger - index_smaller| - 1), UNKNOWN and needs to be compared
    */
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = height.size();
        if (len <= 1) return 0;
        int ret = 0;
        int left = 0, right = len - 1;
        while (left < right) {
            ret = max(ret, min(height[left], height[right])*(right-left));
            if (height[left] <= height[right]) {left++;}
            else {right--;}
        }
        return ret;
    }
};
