class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret = solve(n, 2);
        for (vector<int> &cand : ret) {
            reverse(cand.begin(), cand.end());
        }
        return ret;
    }
    vector<vector<int>> solve(int n, int start) {
        vector<vector<int>> ret;
        for (int i = start; i <= sqrt(n); i ++) {
            if (n%i == 0) {
                ret.push_back(vector<int> { n/i, i });
                vector<vector<int>> tmp = solve(n/i, i);
                for (vector<int> cand : tmp) {
                    cand.push_back(i);
                    ret.push_back(cand);
                }
            }
        }
        return ret;
    }
};
