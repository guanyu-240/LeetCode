class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<string, int> strMap;
        vector<string> ret;
        int len = strs.size();
        if (len == 0) return ret;
        bool ana[len];
        fill_n(ana, len, false);
        unordered_map<string, int>:: iterator it;
        for (int n = 0; n < len; n ++){
            string str(strs[n]);
            sort(str.begin(), str.end());
            it = strMap.find(str);
            if (it != strMap.end()) {
                if (it->second != -1) {
                    ana[it->second] = true;
                    strMap[str] = -1;
                }
                ana[n] = true;
            }
            else {
                strMap[str] = n;
            }
        }
        for (int n = 0; n < len; n ++) {
            if (ana[n]) ret.push_back(strs[n]);
        }
        return ret;
    }
};
