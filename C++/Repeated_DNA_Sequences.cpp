class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.length() <= 10) return ret;
        unordered_map<int, int> dnaSeqs;
        int n = s.length();
        int encode = 0;
        int mask = ~(~0 << 20);
        for (int i = 0; i < 10; i ++) {
            encode <<= 2;
            encode += getBit(s[i]);
        }
        ++ dnaSeqs[encode];
        for (int i = 10; i < n; i ++) {
            encode = (encode << 2) & mask;
            encode += getBit(s[i]);
            if ((++dnaSeqs[encode]) == 2) {
                ret.push_back(s.substr(i-10+1, 10));
            }
        }
        return ret;
    }
    
    int getBit(char c) {
        switch (c) {
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return 0;
        }
    }
};
