class Solution {
public:
    vector<vector<int> >ret;
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret.clear();
        vector<int> cand;
        ret.push_back(cand);
        if (S.size() == 0) return ret;
        sort(S.begin(), S.end());
        solve(S, cand, 0);
        return ret;
    }
    void solve(vector<int> &S, vector<int> &cand, int minIndex){
        if (minIndex >= S.size()) return;
        for (int n = minIndex; n < S.size(); n ++){
            vector<int>newCand(cand);
            newCand.push_back(S[n]);
            ret.push_back(newCand);
            if (n+1 < S.size()){
                solve(S, newCand, n+1);
            }
        }
    }
};
