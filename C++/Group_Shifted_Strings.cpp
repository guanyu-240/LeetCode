class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        unordered_map <string, vector<string>> groups;
        for (string s : strings) {
            groups[shift(s)].push_back(s);
        }
        for (auto &group : groups) {
            vector<string> cand = group.second;
            sort(cand.begin(), cand.end());
            ret.push_back(cand);
        }
        return ret;
    }

    string shift(string x) {
        string ret(x);
        if (x.length() == 0) return ret;
        int d = diff(x[0], 'a');
        if (d == 0) return ret;
        for (char &c : ret) {
            c -= d;
            if (c < 'a') c += 26;
        }
        return ret;
    }
    int diff(char x, char y){
        if (x >= y) return x-y;
        else return x-y+26;
    }
};
