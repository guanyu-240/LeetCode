class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (numRows == 0) return ret;
        for (int n = 1; n <= numRows; n ++){
            vector<int> row;
            for (int i = 0; i < n; i ++) {
                if (i == 0 || i == n - 1) {
                    row.push_back(1);
                }
                else {
                    row.push_back(ret[n-2][i-1] + ret[n-2][i]);
                }
            }
            ret.push_back(row);
        }
        return ret;
    }
};
