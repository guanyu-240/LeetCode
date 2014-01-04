class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int ret = 0;
        vector<vector<int> > ones(m + 1, vector<int>(n));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1') {
                    if (j == 0) ones[i][j] = 1;
                    else ones[i][j] = ones[i][j-1] + 1;
                }
                else {
                    ones[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j ++) {
            ones[m][j] = 0;
        }
        for (int i = 0; i < n; i ++) {
            int maxRec = largestRectangle(ones, m, i);
            ret = max(maxRec, ret);
        }
        return ret;
    }
    int largestRectangle(vector<vector<int> > &ones, int m, int col) {
        stack<int> st;
        int sum = 0;
        for (int i = 0; i <= m; i ++) {
            if (st.empty() || ones[i][col] > ones[st.top()][col]){
                st.push(i);
            }
            else {
                int tmp = st.top();
                st.pop();
                sum = max(sum, ones[tmp][col]*(st.empty()? i : i-st.top()-1));
                i --;
            }
        }
        return sum;
    }
};
