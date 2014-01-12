class Solution {
public:
    vector<vector<string> > ret;
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        vector<string> cand;
        cand.clear();
        solve(cand, n);
        return ret;
    }
    void solve(vector<string> cand, int n){
        int i;
        int len = cand.size();
        if (len == n){
            ret.push_back(cand);
        }
        if (len == 0){
            for (i = 0; i < n; i ++){
                string str(n, '.');
                str[i] = 'Q';
                vector<string> new_cand;
                new_cand.clear();
                new_cand.push_back(str);
                solve(new_cand, n);
            }
        }
        else{
            int j, leftToCheck, rightToCheck;
            for (i = 0; i < n; i ++){
                for (j = 0; j < len; j ++){
                    if (cand[j][i] == 'Q')  break;
                    leftToCheck = i - (len - j);
                    if (leftToCheck >= 0){
                        if (cand[j][leftToCheck] == 'Q') break;
                    }
                    rightToCheck = i + (len - j);
                    if (rightToCheck < n){
                        if (cand[j][rightToCheck] == 'Q') break;
                    }
                }
                if (j == len){
                    vector<string> new_cand(cand);
                    string str(n, '.');
                    str[i] = 'Q';
                    new_cand.push_back(str);
                    solve(new_cand, n);
                }
            }
        }
    }
}; 
