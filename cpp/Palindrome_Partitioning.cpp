class Solution {
public:
    // Non-recursion solution
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> ret;
        int len = s.length();
        if (len == 0) return ret;
        bool isPal[len][len];
        for (int i = 0; i < len; i ++) {
            for (int j = i; j >= 0; j --) {
                if (s[j] == s[i] && (i - j < 2 || isPal[j+1][i-1])) {
                    isPal[j][i] = true;
                }
                else isPal[j][i] = false;
            }
        }
        int start = 0;
        queue<int> starts;
        queue<vector<string>> cands;
        vector<string> cand;
        starts.push(start);
        cands.push(cand) ;
        while (!starts.empty()) {
            start = starts.front();
            cand = cands.front();
            starts.pop();
            cands.pop();
            for (int i = start; i < len; i ++) {
                if (isPal[start][i]) {
                    vector<string> newCand(cand);
                    newCand.push_back(s.substr(start, i+1-start));
                    if (i == len - 1) {
                        ret.push_back(newCand);
                    }
                    else{
                        cands.push(newCand);
                        starts.push(i+1);
                    }
                }
            }
        }
        return ret;
    }
};
