class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        if (k == 1) return n == 1 ? costs[0][0] : 0;
        int min1,min2;
        int min1_id,min2_id;
        int ret = INT_MAX;
        
        for (int i = 0; i < n; i ++) {
            if (i == 0) continue;
            min1 = INT_MAX;
            min2 = INT_MAX;
            for (int j = 0; j < k; j ++) {
                if (costs[i-1][j] < min1) {
                    min1 = costs[i-1][j];
                    min1_id = j;
                }
            }
            for (int j = 0; j < k; j ++) {
                if (costs[i-1][j] < min2 && costs[i-1][j] >= min1 && j != min1_id){
                    min2 = costs[i-1][j];
                    min2_id = j;
                }
            }
            for (int j = 0; j < k; j ++) {
                if (j == min1_id) costs[i][j] += min2;
                else costs[i][j] += min1;
            }
        }
        for (int j = 0; j < k; j ++) {
            ret = min(ret, costs[n-1][j]);
        }
        return ret;
    }
};
