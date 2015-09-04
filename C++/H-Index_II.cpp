class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lb = 1, ub = n;
        int ret;
        /*
        Binary search
        End when ret satisfies and ret+1 does not,
        or ret reaches either minimum or maximum value
        which is citations[n-ret] >= ret and citations[n-ret-1] < ret+1
        */
        while (lb <= ub) {
            ret = (lb+ub)/2;
            if (citations[n-ret] >= ret) {
                if (ret == n || citations[n-ret-1] < ret+1) return ret;
                else {
                    lb = ret + 1;
                }
            }
            else {
                ub = ret - 1;
            }
        }
        return 0;
    }
};
