class Solution {
public:
    /*
    Recursion Function:
    For a existing subset s, there are k distinct unselected numbers.
    Generate k new different subsets by copying s and append a candidate number.
    For every new subset, call recursion function if this subset can generate new subsets.
    */
    vector<vector<int> > ret;
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
            if ((n > minIndex && S[n] != S[n-1]) || (n == minIndex)){
                vector<int>newCand(cand);
                newCand.push_back(S[n]);
                ret.push_back(newCand);
                if (n+1 < S.size()){
                    solve(S, newCand, n+1);
                }
            }
        }
    }
};
