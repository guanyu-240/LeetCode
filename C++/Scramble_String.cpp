class Solution {

public:

    bool isScramble(string s1, string s2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s1.size() != s2.size()) return false;
        if (!equalCharCount(s1, s2)) return false;
        if (s1.size() == 1) return true;
        bool ret = false;
        for (int n = 1; n < s1.size(); n ++) {
            ret = isScramble(s1.substr(0, n), s2.substr(0, n)) && 
                    isScramble(s1.substr(n, s1.size()-n), s2.substr(n, s2.size()-n));
            if (ret) return true;
            ret = isScramble(s1.substr(0, n), s2.substr(s2.size()-n, n)) &&
                    isScramble(s1.substr(n, s1.size()-n), s2.substr(0, s2.size()-n));
            if (ret) return true;
        }
        return false;
    }

    bool equalCharCount(string s1, string s2) {
        int count[256];
        fill_n(count, 256, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i]] ++;
            count[s2[i]] --;
        }
        for (int i = 0; i < 256; i ++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};
