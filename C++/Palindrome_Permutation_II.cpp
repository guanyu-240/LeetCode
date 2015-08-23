class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> ret;
        unordered_map<char, int> c_count;
        for (char c : s) { c_count[c]++; }
        int count_odd = 0;
        char odd_c = 0;
        unordered_map<char, int>::iterator it;
        for (it = c_count.begin(); it != c_count.end(); ++it) {
            if (it->second % 2 == 1) {
                count_odd ++;
                odd_c = it->first;
                if (count_odd >= 2) return ret;
            }
            it->second /= 2;
        }
        
        ret = solve(c_count);
        for (string &s : ret) {
            string sr(s);
            reverse(sr.begin(), sr.end());
            if (count_odd != 0) s.append(1, odd_c);
            s += sr;
        }
        return ret;
    }
    
    vector<string> solve(unordered_map<char, int> &c_count) {
        unordered_map<char, int>::iterator it;
        vector<string> ret;
        for (it = c_count.begin(); it != c_count.end(); ++it) {
            if (it->second > 0) {
                it->second --;
                for (string cand: solve(c_count)) {
                    cand.append(1, it->first);
                    ret.push_back(cand);
                }
                it->second ++;
            }
        }
        if (ret.size() == 0) ret.push_back("");
        return ret;
    }
};
