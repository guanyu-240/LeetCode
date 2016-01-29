class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int x = A.size();
        int y = B.size();
        int z = y > 0 ? B[0].size() : 0;
        if (x == 0 || y == 0) return (vector<vector<int>>());
        vector<vector<int>> ret(x, vector<int>(z, 0));
        for (int i = 0; i < x; ++ i) {
            for (int j = 0; j < y; ++ j) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < z; ++ k) {
                        ret[i][k] += A[i][j]*B[j][k];
                    }
                }
            }
        }
        return ret;
    }
};
