class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count[n];
        fill_n(count, n, 0);
        for (int c : citations) {
            if (c > 0) {
                count[min(c, n)-1] ++;
            }
        }
        for (int ret = n; ret > 0; ret --) {
            if (ret < n) count[ret-1] += count[ret];
            if (count[ret-1] >= ret) return ret;
        }
        return 0;
    }
};
