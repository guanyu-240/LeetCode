class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        vector<string> ret;
        if (len == 0) {
            ret.push_back("");
            return ret;
        }
        // start tracing and get the result
        vector<vector<bool> > exists(len, vector<bool>(len));
        for (int i = 0; i < len; i ++) {
            for (int j = i; j < len; j ++) {
                if (dict.find(s.substr(i, j-i+1)) != dict.end()) {
                    exists[i][j] = true;
                }
                else {
                    exists[i][j] = false;
                }
            }
        }
        solve(ret, s, exists, "", len-1);
        return ret;
    }
    void solve(vector<string> &ret, string s, vector<vector<bool> > &exists, string cand, int end){
        for (int n = end; n >= 0; n --){
            if (exists[n][end]){
                string newCand(cand);
                newCand.insert(0, s.substr(n, end-n+1));
                if (n > 0) {
                    newCand.insert(0, " ");
                    solve(ret, s, exists, newCand, n - 1);
                }
                else {
                    ret.push_back(newCand);
                }
            }
        }
    }
};
