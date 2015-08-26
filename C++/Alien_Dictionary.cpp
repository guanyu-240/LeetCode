class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        if (n == 0) return "";
        if (n == 1) return words[0];
        /* start constructing graph */
        vector<vector<int>> adj_list(26, vector<int>());
        int count_incoming[26];
        fill_n(count_incoming, 26, -1);
        int ptr;
        for (string w : words) {
            ptr = 0;
            while (ptr < w.size()) {
                count_incoming[w[ptr]-'a'] = 0;
                ptr ++;
            }
        }
        for (int i = 1; i < n; ++ i) {
            ptr = 0;
            while (ptr < min(words[i-1].size(), words[i].size()) &&
                    words[i-1][ptr] == words[i][ptr]) { ptr ++; }
            if (ptr < words[i-1].size() && ptr < words[i].size()) {
                adj_list[words[i-1][ptr]-'a'].push_back(words[i][ptr]);
                count_incoming[words[i][ptr]-'a'] ++;
            }
        }
        
        /* start topological sort process */
        queue<char> q;
        char cand;
        string ret = "";
        for (char c='a'; c <= 'z'; c ++) {
            if (count_incoming[c-'a']== 0) q.push(c);
        }
        while (!q.empty()) {
            cand = q.front();
            q.pop();
            ret.append(1, cand);
            for (char c : adj_list[cand-'a']) {
                count_incoming[c-'a'] --;
                if (count_incoming[c-'a']==0) {
                    q.push(c);
                }
            }
        }
        for (char c = 'a'; c <= 'z'; c ++) {
            if (count_incoming[c-'a'] > 0) return "";
        }
        
        return ret;
    }
};
