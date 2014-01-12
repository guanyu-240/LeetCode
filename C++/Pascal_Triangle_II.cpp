class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        if (rowIndex < 0) return ret;
        vector<int> row;
        for (int n = 1; n <= rowIndex+1; n ++){
            for (int i = 0; i < n; i ++) {
                if (i == 0 || i == n - 1) {
                    row.push_back(1);
                }
                else {
                    row.push_back(ret[i-1] + ret[i]);
                }
            }
            ret = vector<int>(row);
            row.clear();
        }
        return ret;
    }
};
