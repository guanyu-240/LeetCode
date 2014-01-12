class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int len = num.size();
        vector<vector<int>> ret;
        if (len == 0) return ret;
        sort(num.begin(), num.end());
        vector<int> cand;
        solve(ret, cand, 0, num, target);
    }
    void solve(vector<vector<int> > &ret, vector<int> cand, int start, vector<int> &num, int target){
        if (target == 0) {
            ret.push_back(cand);
            return;
        }
        if (target < 0 || start >= num.size()) return;
        for (int i = start; i < num.size(); i ++) {
            if (i == start || (i > start && num[i] != num[i-1])){
                vector<int> newCand(cand);
                newCand.push_back(num[i]);
                solve(ret, newCand, i+1, num, target-num[i]);
            }
        }
    }
};
