class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string combs[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        ret.push_back("");
        vector<string> tmp;
        int len = digits.length();
        if (len == 0) return ret;
        for (int n = 0; n < len; n ++) {
            string comb = combs[digits[n]-50]; 
            for (int i = 0; i < ret.size(); i ++){
                for (int j = 0; j < comb.length(); j ++){
                    string cand(ret[i]);
                    cand.append(1, comb[j]);
                    tmp.push_back(cand);
                }
            }
            ret = vector<string>(tmp);
            tmp.clear();
        }
        return ret;
    }
};
