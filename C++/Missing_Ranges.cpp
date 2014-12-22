class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> ret;
        int cur = 0, pre = 0;
        lower --; upper ++;
        for (int i = 0; i <= n; i ++) {
            pre = (i == 0 ? lower : A[i-1]);
            cur = (i == n ? upper : A[i]);
            if (cur - pre < 2) continue;
            else if (cur - pre == 2) {
                ret.push_back(to_string(cur-1));
            }
            else {
                ret.push_back(to_string(pre+1)+"->"+to_string(cur-1));
            }
        }
        return ret;
    }
};
