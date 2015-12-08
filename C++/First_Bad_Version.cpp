// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    /* Binary search, additional attention needed for overflow */
    int firstBadVersion(int n) {
        int left = 1, right = n;
        int ret;
        while (left <= right) {
            ret = left + (right-left)/2;
            if (isBadVersion(ret)) {
                if (ret == left || !isBadVersion(ret-1)) return ret;
                else right = ret-1;
            }
            else {
                left = ret+1;
            }
        }
        return 0;
    }
};
