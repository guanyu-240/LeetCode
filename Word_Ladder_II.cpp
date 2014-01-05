class Solution {
public:
    vector<vector<string>> ret;
    unordered_map<string, unordered_set<string>> predsMap;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear(); predsMap.clear();
        unordered_set<string>::iterator it;
        for (it = dict.begin(); it != dict.end(); ++it) {
            predsMap[*it] = unordered_set<string>();
        }
        predsMap[end] = unordered_set<string>();
        queue<string> words;
        unordered_set<string> cands;
        words.push(start);
        int remain = 1;
        string tmp;
        string cand;
        char original;
        bool endSearch = false;
        while (!words.empty()) {
            cand = words.front();
            words.pop();
            remain --;
            tmp = string(cand);
            for (int i = 0; i < tmp.length(); i ++) {
                original = tmp[i];    
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (tmp == end) {
                        endSearch = true;
                        predsMap[end].insert(cand);
                    }
                    if (dict.find(tmp) != dict.end()) {
                        cands.insert(tmp);
                        predsMap[tmp].insert(cand);
                    }
                }
                tmp[i] = original;
            }
            if (remain == 0) {
                if (endSearch) break;
                for (it = cands.begin(); it != cands.end(); ++ it) {
                    words.push(*it);
                    dict.erase(*it);
                }
                remain = words.size();
                cands.clear();
            }
        }
        vector<string> res;
        res.push_back(end);
        trace(res, start, end);
        return ret;
    }
    
    void trace(vector<string> res, string start, string end){
        if (end == start) {
            reverse(res.begin(), res.end());
            ret.push_back(res);
            return;
        }
        unordered_set<string> preds = predsMap[end];
        unordered_set<string>:: iterator it;
        for (it = preds.begin(); it != preds.end(); ++it) {
            vector<string> newRes(res);
            newRes.push_back(*it);
            trace(newRes, start, *it);
        }
    }
};
