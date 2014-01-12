class Solution {
public:
    vector<vector<int> > ret;
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret.clear();
        vector<int> cand;
        solve(cand, num);
        return ret;
    }
    void solve(vector<int> &cand, vector<int> &remain){
        if (remain.size() == 0){
            ret.push_back(cand);
        }
        for (int n = 0; n < remain.size(); n ++){
            vector<int> newCand(cand);
            vector<int> newRemain(remain);
            newCand.push_back(remain[n]);
            newRemain.erase(newRemain.begin()+n);
            solve(newCand, newRemain);
        }
    }
};
