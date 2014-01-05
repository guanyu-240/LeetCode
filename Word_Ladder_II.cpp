class Solution {
public:
    vector<vector<string>> ret;
    unordered_map<string, unordered_set<string>> predsMap;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        // Clear return vector and the predecessor map
        ret.clear(); 
        predsMap.clear();

        // Initialize the predecessor map
        unordered_set<string>::iterator it;
        for (it = dict.begin(); it != dict.end(); ++it) {
            predsMap[*it] = unordered_set<string>();
        }
        predsMap[end] = unordered_set<string>();
       
        // Breadth first seach process
        queue<string> words;
        unordered_set<string> cands;
        words.push(start);
        int remain = 1;
        string tmp, cand;
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
                    if (!endSearch && dict.find(tmp) != dict.end()) {
                        cands.insert(tmp);
                        predsMap[tmp].insert(cand);
                    }
                }
                tmp[i] = original;
            }
            if (remain == 0) {          // ready to start the next level or terminate
                if (endSearch) break;
                for (it = cands.begin(); it != cands.end(); ++ it) {
                    words.push(*it);
                    dict.erase(*it);
                }
                remain = words.size();
                cands.clear();
            }
        }

        // generate the results
        genResults(vector<string>(1, end), start, end);
        return ret;

    }
   
    void genResults(vector<string> res, string start, string end){
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
            genResults(newRes, start, *it);
        }
    }
};
